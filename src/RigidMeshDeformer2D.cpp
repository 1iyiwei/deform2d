#include "RigidMeshDeformer2D.h"

#include <WmlLinearSystem.h>
#include <WmlMatrix4.h>
#include "WmlExtTriangleUtils.h"
#include "rmsdebug.h"

using namespace rmsmesh;


RigidMeshDeformer2D::RigidMeshDeformer2D()
{
	InvalidateSetup();
}

void RigidMeshDeformer2D::SetDeformedHandle( unsigned int nHandle, const Wml::Vector2f & vHandle )
{
	Constraint c(nHandle, vHandle);
	UpdateConstraint(c);
}

void RigidMeshDeformer2D::RemoveHandle( unsigned int nHandle )
{	
	Constraint c(nHandle, Wml::Vector2f::ZERO);
	m_vConstraints.erase(c);
	m_vDeformedVerts[nHandle].vPosition = m_vInitialVerts[nHandle].vPosition;
	InvalidateSetup();
}


void RigidMeshDeformer2D::UnTransformPoint( Wml::Vector2f & vTransform )
{
	// find triangle
	size_t nTris = m_vTriangles.size();
	for ( unsigned int i = 0; i < nTris; ++i ) {
		Wml::Vector2f v1( m_vDeformedVerts[m_vTriangles[i].nVerts[0]].vPosition );
		Wml::Vector2f v2( m_vDeformedVerts[m_vTriangles[i].nVerts[1]].vPosition );
		Wml::Vector2f v3( m_vDeformedVerts[m_vTriangles[i].nVerts[2]].vPosition );

		float fBary1, fBary2, fBary3;
		Wml::BarycentricCoords(v1,v2,v3,vTransform, fBary1, fBary2, fBary3 );
		if ( fBary1 < 0 || fBary1 > 1 || fBary2 < 0 || fBary2 > 1 || fBary3 < 0 || fBary3 > 1 )
			continue;

		Wml::Vector2f v1Init( m_vInitialVerts[m_vTriangles[i].nVerts[0]].vPosition );
		Wml::Vector2f v2Init( m_vInitialVerts[m_vTriangles[i].nVerts[1]].vPosition );
		Wml::Vector2f v3Init( m_vInitialVerts[m_vTriangles[i].nVerts[2]].vPosition );
		vTransform = fBary1 * v1Init + fBary2 * v2Init + fBary3 * v3Init;
		return;
	}

}



void RigidMeshDeformer2D::InitializeFromMesh( TriangleMesh * pMesh )
{
	m_vConstraints.clear();
	m_vInitialVerts.resize(0);
	m_vDeformedVerts.resize(0);
	m_vTriangles.resize(0);

	// copy vertices
	unsigned int nVerts = pMesh->GetNumVertices();
	for ( unsigned int i = 0; i < nVerts; ++i ) {
		Wml::Vector3f vVertex;
		pMesh->GetVertex(i, vVertex);

		Vertex v;
		v.vPosition = Wml::Vector2f( vVertex.X(), vVertex.Y() );
		m_vInitialVerts.push_back( v );
		m_vDeformedVerts.push_back( v );
	}

	// copy triangles
	unsigned int nTris = pMesh->GetNumTriangles();
	for ( unsigned int i = 0; i < nTris; ++i ) {
		Triangle t;
		pMesh->GetTriangle(i, t.nVerts );
		m_vTriangles.push_back(t);
	}


	// set up triangle-local coordinate systems
	for ( unsigned int i = 0; i < nTris; ++i ) {
		Triangle & t = m_vTriangles[i];
		
		for ( int j = 0; j < 3; ++j ) {
			unsigned int n0 = j;
			unsigned int n1 = (j+1)%3;
			unsigned int n2 = (j+2)%3;

			Wml::Vector2f v0 = GetInitialVert( t.nVerts[n0] );
			Wml::Vector2f v1 = GetInitialVert( t.nVerts[n1] );
			Wml::Vector2f v2 = GetInitialVert( t.nVerts[n2] );

			// find coordinate system
			Wml::Vector2f v01( v1 - v0 );
			Wml::Vector2f v01N( v01 );  v01N.Normalize();
			Wml::Vector2f v01Rot90( v01.Y(), -v01.X() );
			Wml::Vector2f v01Rot90N( v01Rot90 );  v01Rot90N.Normalize();

			// express v2 in coordinate system
			Wml::Vector2f vLocal(v2 - v0);
			float fX = vLocal.Dot(v01) /  v01.SquaredLength();
			float fY = vLocal.Dot(v01Rot90) / v01Rot90.SquaredLength();

			// sanity check
			Wml::Vector2f v2test(v0 + fX * v01 + fY * v01Rot90);
			float fLength = (v2test - v2).Length();
			if ( fLength > 0.001f )
				DebugBreak();

			t.vTriCoords[j] = Wml::Vector2f(fX,fY);
		}
	}
}


void RigidMeshDeformer2D::UpdateDeformedMesh( TriangleMesh * pMesh, bool bRigid )
{
	ValidateDeformedMesh(bRigid);

	std::vector<Vertex> & vVerts = (m_vConstraints.size() > 1) ? m_vDeformedVerts : m_vInitialVerts;

	unsigned int nVerts = pMesh->GetNumVertices();
	for ( unsigned int i = 0; i < nVerts; ++i ) {
		Wml::Vector2f vNewPos( vVerts[i].vPosition );
		pMesh->SetVertex( i, Wml::Vector3f( vNewPos.X(), vNewPos.Y(), 0.0f ) );
	}
}



void RigidMeshDeformer2D::UpdateConstraint( Constraint & cons )
{
	std::set<Constraint>::iterator found( m_vConstraints.find(cons) );
	if ( found != m_vConstraints.end() ) {

		(*found).vConstrainedPos = cons.vConstrainedPos;
		m_vDeformedVerts[cons.nVertex].vPosition = cons.vConstrainedPos;

	} else {
		m_vConstraints.insert( cons );
		m_vDeformedVerts[cons.nVertex].vPosition = cons.vConstrainedPos;
		InvalidateSetup();
	} 

}




void ExtractSubMatrix( Wml::GMatrixd & mFrom, int nRowOffset, int nColOffset, Wml::GMatrixd & mTo )
{
	int nRows = mTo.GetRows();
	int nCols = mTo.GetColumns();

	for ( int i = 0; i < nRows; ++i ) {
		for ( int j = 0; j < nCols; ++j ) {
			mTo[i][j] = mFrom[ i + nRowOffset][ j + nColOffset ];
		}
	}
}


void RigidMeshDeformer2D::ValidateSetup()
{
	if  ( m_bSetupValid || m_vConstraints.size() < 2)
		return;

	_RMSInfo("Computing matrices for mesh with %d verts....this might take a while...\n", m_vInitialVerts.size() );

	PrecomputeOrientationMatrix();

	// ok, now scale triangles
	size_t nTris = m_vTriangles.size();
	for ( unsigned int i = 0; i < nTris; ++i )
		PrecomputeScalingMatrices(i);

	PrecomputeFittingMatrices();

	_RMSInfo("Done!\n" );


	m_bSetupValid = true;
}




void RigidMeshDeformer2D::PrecomputeFittingMatrices()
{
	// put constraints into vector (will be useful)
	std::vector<Constraint> vConstraintsVec;
	std::set<Constraint>::iterator cur(m_vConstraints.begin()), end(m_vConstraints.end());
	while ( cur != end )
		vConstraintsVec.push_back( *cur++ );

	// resize matrix and clear to zero
	unsigned int nVerts = (unsigned int)m_vDeformedVerts.size();
	size_t nConstraints = vConstraintsVec.size();
	unsigned int nFreeVerts = nVerts - nConstraints;

	// figure out vertex ordering. first do free vertices, then constraints
	unsigned int nRow = 0;
	m_vVertexMap.resize(nVerts);
	for ( unsigned int i = 0; i < nVerts; ++i ) {
		Constraint c(i, Wml::Vector2f::ZERO);
		if ( m_vConstraints.find(c) != m_vConstraints.end() )
			continue;
		m_vVertexMap[i] = nRow++;
	}
	if ( nRow != nFreeVerts )	DebugBreak();
	for ( unsigned int i = 0 ; i < nConstraints; ++i )
		m_vVertexMap[vConstraintsVec[i].nVertex ] = nRow++;
	if ( nRow != nVerts )	DebugBreak();		// bad!
	

	// test vector...
	Wml::GVectord gUTestX( nVerts ), gUTestY(nVerts);
	for ( unsigned int i = 0; i < nVerts; ++i ) {
		Constraint c(i,Wml::Vector2f::ZERO);
		if ( m_vConstraints.find(c) != m_vConstraints.end() )
			continue;
		int nRow = m_vVertexMap[i];
		gUTestX[nRow] = m_vInitialVerts[i].vPosition.X();
		gUTestY[nRow] = m_vInitialVerts[i].vPosition.Y();
	}
	for ( unsigned int i = 0; i < nConstraints; ++i ) {
		int nRow = m_vVertexMap[ vConstraintsVec[i].nVertex ];
		gUTestX[nRow] = vConstraintsVec[i].vConstrainedPos.X();
		gUTestY[nRow] = vConstraintsVec[i].vConstrainedPos.Y();
	}


	// make Hy and Hx matrices
	Wml::GMatrixd mHX( nVerts, nVerts );
	Wml::GMatrixd mHY( nVerts, nVerts );
	for ( unsigned int i = 0; i < nVerts; ++i )
		for ( unsigned int j = 0; j < nVerts; ++j )
			mHX(i,j) = mHY(i,j) = 0.0;

	// ok, now fill matrix
	size_t nTriangles = m_vTriangles.size();
	for ( unsigned int i = 0; i < nTriangles; ++i ) {
		Triangle & t = m_vTriangles[i];

//		_RMSInfo("Triangle %d: \n", i);
		double fTriSumErr = 0;
		for ( int j = 0; j < 3; ++j ) {
			double fTriErr = 0;

			int nA = m_vVertexMap[ t.nVerts[j] ];
			int nB = m_vVertexMap[ t.nVerts[(j+1)%3] ];

			// X elems
			mHX[nA][nA] += 2;
			mHX[nA][nB] += -2;
			mHX[nB][nA] += -2;
			mHX[nB][nB] += 2;

			//  Y elems
			mHY[nA][nA] += 2;
			mHY[nA][nB] += -2;
			mHY[nB][nA] += -2;
			mHY[nB][nB] += 2;			
		}
	}

	// extract HX00 and  HY00 matrices
	Wml::GMatrixd mHX00( (int)nFreeVerts, (int)nFreeVerts );
	Wml::GMatrixd mHY00( (int)nFreeVerts, (int)nFreeVerts );
	ExtractSubMatrix( mHX, 0, 0, mHX00 );
	ExtractSubMatrix( mHY, 0, 0, mHY00 );

	// Extract HX01 and HX10 matrices
	Wml::GMatrixd mHX01( (int)nFreeVerts, (int)nConstraints );
	Wml::GMatrixd mHX10( (int)nConstraints, (int)nFreeVerts );
	ExtractSubMatrix( mHX, 0, nFreeVerts, mHX01 );
	ExtractSubMatrix( mHX, nFreeVerts, 0, mHX10 );

	// Extract HY01 and HY10 matrices
	Wml::GMatrixd mHY01( (int)nFreeVerts, (int)nConstraints );
	Wml::GMatrixd mHY10( (int)nConstraints, (int)nFreeVerts );
	ExtractSubMatrix( mHY, 0, nFreeVerts, mHY01 );
	ExtractSubMatrix( mHY, nFreeVerts, 0, mHY10 );

	// now compute HXPrime = HX00 + Transpose(HX00) (and HYPrime)
	//Wml::GMatrixd mHXPrime( mHX00 + mHX00.Transpose() );
	//Wml::GMatrixd mHYPrime( mHY00 + mHY00.Transpose() );
	m_mHXPrime = mHX00;
	m_mHYPrime = mHY00;

	// and then D = HX01 + Transpose(HX10)
	//Wml::GMatrixd mDX = mHX01 + mHX10.Transpose();
	//Wml::GMatrixd mDY = mHY01 + mHY10.Transpose();
	m_mDX = mHX01;
	m_mDY = mHY01;

	// pre-compute LU decompositions
	bool bResult = Wml::LinearSystemExtd::LUDecompose( m_mHXPrime, m_mLUDecompX );
	if (!bResult)
		DebugBreak();
	bResult = Wml::LinearSystemExtd::LUDecompose( m_mHYPrime, m_mLUDecompY );
	if (!bResult)
		DebugBreak();

}


void RigidMeshDeformer2D::ApplyFittingStep()
{
	// put constraints into vector (will be useful)
	std::vector<Constraint> vConstraintsVec;
	std::set<Constraint>::iterator cur(m_vConstraints.begin()), end(m_vConstraints.end());
	while ( cur != end )
		vConstraintsVec.push_back( *cur++ );

	unsigned int nVerts = (unsigned int)m_vDeformedVerts.size();
	size_t nConstraints = vConstraintsVec.size();
	unsigned int nFreeVerts = nVerts - nConstraints;

	// make vector of deformed vertex weights
	Wml::GVectord vFX( nVerts );
	Wml::GVectord vFY( nVerts );
	for ( int i = 0; i < (int)nVerts; ++i )
		vFX[i] = vFY[i] = 0.0;

	size_t nTriangles = m_vTriangles.size();
	for ( unsigned int i = 0; i < nTriangles; ++i ) {
		Triangle & t = m_vTriangles[i];

		for ( int j = 0; j < 3; ++j ) {

			int nA = m_vVertexMap[ t.nVerts[j] ];
			int nB = m_vVertexMap[ t.nVerts[(j+1)%3] ];

			Wml::Vector2f vDeformedA( t.vScaled[j] );
			Wml::Vector2f vDeformedB( t.vScaled[(j+1)%3] );

			// X elems
			vFX[nA] += -2 * vDeformedA.X() + 2 * vDeformedB.X();
			vFX[nB] += 2 * vDeformedA.X() - 2 * vDeformedB.X();

			//  Y elems
			vFY[nA] += -2 * vDeformedA.Y() + 2 * vDeformedB.Y();
			vFY[nB] += 2 * vDeformedA.Y() - 2 * vDeformedB.Y();
		}
	}

	// make F0 vectors
	Wml::GVectord vF0X( nFreeVerts ), vF0Y( nFreeVerts );
	for ( int i = 0; i < (int)nFreeVerts; ++i ) {
		vF0X[i] = vFX[i];
		vF0Y[i] = vFY[i];
	}

	// make Q vectors (vectors of constraints)
	Wml::GVectord vQX( (int)nConstraints ),  vQY( (int)nConstraints );
	for ( int i = 0; i < (int)nConstraints; ++i ) {
		vQX[i] = vConstraintsVec[i].vConstrainedPos.X();
		vQY[i] = vConstraintsVec[i].vConstrainedPos.Y();
	}

	// ok, compute RHS for X and solve
	Wml::GVectord vRHSX( m_mDX * vQX );
	vRHSX += vF0X;
	vRHSX *= -1;
	Wml::GVectord vSolutionX( (int)nFreeVerts );

	//Wml::LinearSystemd::Solve( m_mHXPrime, vRHSX, vSolutionX );
	bool bResult = Wml::LinearSystemExtd::LUBackSub( m_mLUDecompX, vRHSX, vSolutionX );
	if (!bResult)
		DebugBreak();

	// now for Y
	Wml::GVectord vRHSY( m_mDY * vQY );
	vRHSY += vF0Y;
	vRHSY *= -1;
	Wml::GVectord vSolutionY( (int)nFreeVerts );
//	Wml::LinearSystemd::Solve( m_mHYPrime, vRHSY, vSolutionY );
	bResult = Wml::LinearSystemExtd::LUBackSub( m_mLUDecompY, vRHSY, vSolutionY );
	if (!bResult)
		DebugBreak();

	// done!
	for ( unsigned int i = 0; i < nVerts; ++i ) {
		Constraint c(i,Wml::Vector2f::ZERO);
		if ( m_vConstraints.find(c) != m_vConstraints.end() )
			continue;
		int nRow = m_vVertexMap[i];
		m_vDeformedVerts[i].vPosition.X() = (float)vSolutionX[nRow];
		m_vDeformedVerts[i].vPosition.Y() = (float)vSolutionY[nRow];
	}

}












void RigidMeshDeformer2D::PrecomputeOrientationMatrix()
{
	// put constraints into vector (will be useful)
	std::vector<Constraint> vConstraintsVec;
	std::set<Constraint>::iterator cur(m_vConstraints.begin()), end(m_vConstraints.end());
	while ( cur != end )
		vConstraintsVec.push_back( *cur++ );

	// resize matrix and clear to zero
	unsigned int nVerts = (unsigned int)m_vDeformedVerts.size();
	m_mFirstMatrix.SetSize( 2*nVerts, 2*nVerts);
	for ( unsigned int i = 0; i < 2*nVerts; ++i )
		for ( unsigned int j = 0; j < 2*nVerts; ++j )
			m_mFirstMatrix(i,j) = 0.0;

	size_t nConstraints = vConstraintsVec.size();
	unsigned int nFreeVerts = nVerts - nConstraints;

	// figure out vertex ordering. first do free vertices, then constraints
	unsigned int nRow = 0;
	m_vVertexMap.resize(nVerts);
	for ( unsigned int i = 0; i < nVerts; ++i ) {
		Constraint c(i, Wml::Vector2f::ZERO);
		if ( m_vConstraints.find(c) != m_vConstraints.end() )
			continue;
		m_vVertexMap[i] = nRow++;
	}
	if ( nRow != nFreeVerts )	DebugBreak();
	for ( unsigned int i = 0 ; i < nConstraints; ++i )
		m_vVertexMap[vConstraintsVec[i].nVertex ] = nRow++;
	if ( nRow != nVerts )	DebugBreak();		// bad!


	// test vector...
	Wml::GVectord gUTest( nVerts * 2 );
	for ( unsigned int i = 0; i < nVerts; ++i ) {
		Constraint c(i,Wml::Vector2f::ZERO);
		if ( m_vConstraints.find(c) != m_vConstraints.end() )
			continue;
		int nRow = m_vVertexMap[i];
		gUTest[2*nRow] = m_vInitialVerts[i].vPosition.X();
		gUTest[2*nRow+1] = m_vInitialVerts[i].vPosition.Y();
	}
	for ( unsigned int i = 0; i < nConstraints; ++i ) {
		int nRow = m_vVertexMap[ vConstraintsVec[i].nVertex ];
		gUTest[2*nRow] = vConstraintsVec[i].vConstrainedPos.X();
		gUTest[2*nRow+1] = vConstraintsVec[i].vConstrainedPos.Y();
	}


	// ok, now fill matrix (?)
	size_t nTriangles = m_vTriangles.size();
	for ( unsigned int i = 0; i < nTriangles; ++i ) {
		Triangle & t = m_vTriangles[i];
		
//		_RMSInfo("Triangle %d: \n", i);
		double fTriSumErr = 0;
		for ( int j = 0; j < 3; ++j ) {
			double fTriErr = 0;

			int n0x = 2 * m_vVertexMap[ t.nVerts[j] ];
			int n0y = n0x + 1;
			int n1x = 2 * m_vVertexMap[ t.nVerts[(j+1)%3] ];
			int n1y = n1x + 1;
			int n2x = 2 * m_vVertexMap[ t.nVerts[(j+2)%3] ];
			int n2y = n2x + 1;
			float x = t.vTriCoords[j].X();
			float y = t.vTriCoords[j].Y();


			// DEBUG
			Wml::Vector2f v0( (float)gUTest[n0x], (float)gUTest[n0y] );
			Wml::Vector2f v1( (float)gUTest[n1x], (float)gUTest[n1y] );
			Wml::Vector2f v2( (float)gUTest[n2x], (float)gUTest[n2y] );
			Wml::Vector2f v01( v1 - v0 );
			Wml::Vector2f v01Perp( v01.Y(), -v01.X() );
			Wml::Vector2f vTest( v0 + x * v01 + y * v01Perp );
			float fDist = (vTest - v2).Dot(vTest - v2);
			//if ( fDist > 0.0001f )
			//	DebugBreak();
			//DEBUG

			//double dTest = 
			//(1 - 2*x + (x*x) + (y*y))*pow(gUTest[n0x],2) + (1 - 2*x + (x*x) + (y*y))*pow(gUTest[n0y],2) + 
			//	((x*x) + (y*y))*pow(gUTest[n1x],2) + ((x*x) + (y*y))*pow(gUTest[n1y],2) + 
			//	pow(gUTest[n2x],2) + pow(gUTest[n2y],2) + gUTest[n1y]*(-2*y*gUTest[n2x] - 2*x*gUTest[n2y]) + 
			//	gUTest[n0y]*(-2*y*gUTest[n1x] + (2*x - 2*(x*x) - 2*(y*y))*gUTest[n1y] + 2*y*gUTest[n2x] + 
			//	(-2 + 2*x)*gUTest[n2y]) + gUTest[n0x]*
			//	((2*x - 2*(x*x) - 2*(y*y))*gUTest[n1x] + 2*y*gUTest[n1y] + (-2 + 2*x)*gUTest[n2x] - 
			//	2*y*gUTest[n2y]) + gUTest[n1x]*(-2*x*gUTest[n2x] + 2*y*gUTest[n2y]);
			//_RMSInfo("TEST IS %f %f\n", dTest, fDist);
			
			// n0x,n?? elems
			m_mFirstMatrix[n0x][n0x] += 1 - 2*x + x*x + y*y;
			m_mFirstMatrix[n0x][n1x] += 2*x - 2*x*x - 2*y*y;		//m_mFirstMatrix[n1x][n0x] += 2*x - 2*x*x - 2*y*y;
			m_mFirstMatrix[n0x][n1y] += 2*y;						//m_mFirstMatrix[n1y][n0x] += 2*y;
			m_mFirstMatrix[n0x][n2x] += -2 + 2*x;					//m_mFirstMatrix[n2x][n0x] += -2 + 2*x;
			m_mFirstMatrix[n0x][n2y] += -2 * y;						//m_mFirstMatrix[n2y][n0x] += -2 * y;

			fTriErr += (1 - 2*x + x*x + y*y)  * gUTest[n0x] * gUTest[n0x];
			fTriErr += (2*x - 2*x*x - 2*y*y)  * gUTest[n0x] * gUTest[n1x];
			fTriErr += (2*y)                  * gUTest[n0x] * gUTest[n1y];
			fTriErr += (-2 + 2*x )            * gUTest[n0x] * gUTest[n2x];
			fTriErr += (-2 * y)               * gUTest[n0x] * gUTest[n2y];

			// n0y,n?? elems
			m_mFirstMatrix[n0y][n0y] += 1 - 2*x + x*x + y*y;
			m_mFirstMatrix[n0y][n1x] += -2*y;						//m_mFirstMatrix[n1x][n0y] += -2*y;
			m_mFirstMatrix[n0y][n1y] += 2*x - 2*x*x - 2*y*y;		//m_mFirstMatrix[n1y][n0y] += 2*x - 2*x*x - 2*y*y;
			m_mFirstMatrix[n0y][n2x] += 2*y;						//m_mFirstMatrix[n2x][n0y] += 2*y;
			m_mFirstMatrix[n0y][n2y] += -2 + 2*x;					//m_mFirstMatrix[n2y][n0y] += -2 + 2*x;

			fTriErr += (1 - 2*x + x*x + y*y)   * gUTest[n0y] * gUTest[n0y];
			fTriErr += (-2*y)                  * gUTest[n0y] * gUTest[n1x];
			fTriErr += (2*x - 2*x*x - 2*y*y)   * gUTest[n0y] * gUTest[n1y];
			fTriErr += (2*y)                   * gUTest[n0y] * gUTest[n2x];
			fTriErr += (-2 + 2*x)              * gUTest[n0y] * gUTest[n2y];

			// n1x,n?? elems
			m_mFirstMatrix[n1x][n1x] += x*x + y*y;
			m_mFirstMatrix[n1x][n2x] += -2*x;						//m_mFirstMatrix[n2x][n1x] += -2*x;
			m_mFirstMatrix[n1x][n2y] += 2*y;						//m_mFirstMatrix[n2y][n1x] += 2*y;

			fTriErr += (x*x + y*y)            * gUTest[n1x] * gUTest[n1x];
			fTriErr += (-2*x)                 * gUTest[n1x] * gUTest[n2x];
			fTriErr += (2*y)                  * gUTest[n1x] * gUTest[n2y];

			//n1y,n?? elems
			m_mFirstMatrix[n1y][n1y] += x*x + y*y;
			m_mFirstMatrix[n1y][n2x] += -2*y;						//m_mFirstMatrix[n2x][n1y] += -2*y;
			m_mFirstMatrix[n1y][n2y] += -2*x;						//m_mFirstMatrix[n2y][n1y] += -2*x;


			fTriErr += (x*x + y*y)            * gUTest[n1y] * gUTest[n1y];
			fTriErr += (-2*y)                 * gUTest[n1y] * gUTest[n2x];
			fTriErr += (-2*x)                 * gUTest[n1y] * gUTest[n2y];

			// final 2 elems
			m_mFirstMatrix[n2x][n2x] += 1;
			m_mFirstMatrix[n2y][n2y] += 1;

			fTriErr += gUTest[n2x] * gUTest[n2x]  +  gUTest[n2y] * gUTest[n2y] ;

			//_RMSInfo("  Error for vert %d (%d) - %f\n", j, t.nVerts[j], fTriErr);
			fTriSumErr += fTriErr;
		}
		//_RMSInfo("  Total Error: %f\n", fTriSumErr);
	}


	// test...
	Wml::GVectord gUTemp = m_mFirstMatrix * gUTest;
	double fSum = gUTemp.Dot( gUTest );
	_RMSInfo("    (test) Residual is %f\n", fSum);

/*
	// just try printing out matrix...
	for ( unsigned int i = 0; i < 2*nFreeVerts; ++i ) {
		for ( unsigned int j = 0 ; j < 2*nFreeVerts; ++j )
			_RMSInfo("%5.2f ", m_mFirstMatrix(i,j));
		_RMSInfo("| ");
		for ( unsigned int j = 0; j < 2*nConstraints; ++j )
			_RMSInfo("%5.2f ", m_mFirstMatrix(i, 2*nFreeVerts+j));
		_RMSInfo("\n");
	}
	_RMSInfo("-------\n");
	for ( unsigned int i = 0; i < 2*nConstraints; ++i ) {
		for ( unsigned int j = 0 ; j < 2*nFreeVerts; ++j )
			_RMSInfo("%5.2f ", m_mFirstMatrix(i+2*nFreeVerts,j));
		_RMSInfo("| ");
		for ( unsigned int j = 0; j < 2*nConstraints; ++j )
			_RMSInfo("%5.2f ", m_mFirstMatrix(i+2*nFreeVerts, 2*nFreeVerts+j));
		_RMSInfo("\n");
	}
	_RMSInfo("\n\n");
*/

	// extract G00 matrix
	Wml::GMatrixd mG00( 2*nFreeVerts, 2*nFreeVerts );
	ExtractSubMatrix( m_mFirstMatrix, 0, 0, mG00 );

	// extract G01 and G10 matrices
	Wml::GMatrixd mG01( 2 * (int)nFreeVerts, 2 * (int)nConstraints );
	ExtractSubMatrix( m_mFirstMatrix, 0, 2*nFreeVerts, mG01 );
	Wml::GMatrixd mG10( 2 * (int)nConstraints, 2 * (int)nFreeVerts );
	ExtractSubMatrix( m_mFirstMatrix, 2*nFreeVerts, 0, mG10 );

	// ok, now compute GPrime = G00 + Transpose(G00) and B = G01 + Transpose(G10)
	Wml::GMatrixd mGPrime = mG00 + mG00.Transpose();
	Wml::GMatrixd mB = mG01 + mG10.Transpose();

	// ok, now invert GPrime
	Wml::GMatrixd mGPrimeInverse( mGPrime.GetRows(), mGPrime.GetColumns() );
	bool bInverted = Wml::LinearSystemd::Inverse( mGPrime, mGPrimeInverse );
	if (!bInverted)
		DebugBreak();

	// now compute -GPrimeInverse * B
	Wml::GMatrixd mFinal = mGPrimeInverse * mB;
	mFinal *= -1;

	m_mFirstMatrix = mFinal;		// [RMS: not efficient!]
}








static RigidMeshDeformer2D::Triangle * g_pCurTriangle = NULL;
float g_fErrSum = 0;
void AccumErrorSum( int nRow, int nCol, float fAccum )
{
	Wml::Vector2f & vRowVtx = g_pCurTriangle->vScaled[nRow/2];
	Wml::Vector2f & vColVtx = g_pCurTriangle->vScaled[nCol/2];
	g_fErrSum += fAccum * vRowVtx[nRow%2] * vColVtx[nCol%2];
}

void AccumScaleEntry( Wml::GMatrixd & mF, int nRow, int nCol, double fAccum )
{
	if ( nRow < 4 && nCol < 4 ) {
		mF[nRow][nCol] += fAccum;
	} else {
		DebugBreak();
	}
}





void RigidMeshDeformer2D::PrecomputeScalingMatrices( unsigned int nTriangle )
{
	// ok now fill matrix
	Triangle & t = m_vTriangles[nTriangle];

	// create matrices and clear to zero
	t.mF = Wml::GMatrixd(4,4);
	t.mC = Wml::GMatrixd(4,6);

	// precompute coeffs
	double x01 = t.vTriCoords[0].X();
	double y01 = t.vTriCoords[0].Y();
	double x12 = t.vTriCoords[1].X();
	double y12 = t.vTriCoords[1].Y();
	double x20 = t.vTriCoords[2].X();
	double y20 = t.vTriCoords[2].Y();

	double k1 = x12*y01 + (-1 + x01)*y12;
	double k2 = -x12 + x01*x12 - y01*y12;
	double k3 = -y01 + x20*y01 + x01*y20;
	double k4 = -y01 + x01*y01 + x01*y20;
	double k5 = -x01 + x01*x20 - y01*y20 ;

	double a = -1 + x01;
	double a1 = pow(-1 + x01,2) + pow(y01,2);
	double a2 = pow(x01,2) + pow(y01,2);
	double b =  -1 + x20;
	double b1 = pow(-1 + x20,2) + pow(y20,2);
	double c2 = pow(x12,2) + pow(y12,2);

	double r1 = 1 + 2*a*x12 + a1*pow(x12,2) - 2*y01*y12 + a1*pow(y12,2);
	double r2 = -(b*x01) - b1*pow(x01,2) + y01*(-(b1*y01) + y20);
	double r3 = -(a*x12) - a1*pow(x12,2) + y12*(y01 - a1*y12);
	double r5 = a*x01 + pow(y01,2);
	double r6 = -(b*y01) - x01*y20;
	double r7 = 1 + 2*b*x01 + b1*pow(x01,2) + b1*pow(y01,2) - 2*y01*y20;

	//  set up F matrix

	// row 0 mF
	t.mF[0][0] = 2*a1 + 2*a1*c2 + 2*r7;
	t.mF[0][1] = 0;
	t.mF[0][2] = 2*r2 + 2*r3 - 2*r5;
	t.mF[0][3] = 2*k1 + 2*r6 + 2*y01;

	// row 1
	t.mF[1][0] = 0;
	t.mF[1][1] = 2*a1 + 2*a1*c2 + 2*r7;
	t.mF[1][2] = -2*k1 + 2*k3 - 2*y01;
	t.mF[1][3] = 2*r2 + 2*r3 - 2*r5;

	// row 2
	t.mF[2][0] = 2*r2 + 2*r3 - 2*r5;
	t.mF[2][1] = -2*k1 + 2*k3 - 2*y01;
	t.mF[2][2] = 2*a2 + 2*a2*b1 + 2*r1;
	t.mF[2][3] = 0;

	//row 3
	t.mF[3][0] = 2*k1 - 2*k3 + 2*y01;
	t.mF[3][1] = 2*r2 + 2*r3 - 2*r5;
	t.mF[3][2] = 0;
	t.mF[3][3] = 2*a2 + 2*a2*b1 + 2*r1;

	// ok, now invert F
	Wml::GMatrixd mFInverse(4,4);
	bool bResult = Wml::LinearSystemd::Inverse(t.mF, mFInverse);
	mFInverse *= -1.0;
	if (!bResult) {
		DebugBreak();
	}
	t.mF =  mFInverse;

	// set up C matrix

	// row 0 mC
	t.mC[0][0] = 2*k2;
	t.mC[0][1] = -2*k1;
	t.mC[0][2] = 2*(-1-k5);
	t.mC[0][3] = 2*k3;
	t.mC[0][4] = 2*a;
	t.mC[0][5] = -2*y01;

	// row 1 mC
	t.mC[1][0] = 2*k1;
	t.mC[1][1] = 2*k2;
	t.mC[1][2] = -2*k3;
	t.mC[1][3] = 2*(-1-k5);
	t.mC[1][4] = 2*y01;
	t.mC[1][5] = 2*a;

	// row 2 mC
	t.mC[2][0] = 2*(-1-k2);
	t.mC[2][1] = 2*k1;
	t.mC[2][2] = 2*k5;
	t.mC[2][3] = 2*r6;
	t.mC[2][4] = -2*x01;
	t.mC[2][5] = 2*y01;

	// row 3 mC
	t.mC[3][0] = 2*k1;
	t.mC[3][1] = 2*(-1-k2);
	t.mC[3][2] = -2*k3;
	t.mC[3][3] = 2*k5;
	t.mC[3][4] = -2*y01;
	t.mC[3][5] = -2*x01;


}


void RigidMeshDeformer2D::UpdateScaledTriangle( unsigned int nTriangle )
{
	// ok now fill matrix
	Triangle & t = m_vTriangles[nTriangle];

	// multiply mC by deformed vertex position
	const Wml::Vector2f & vDeformedV0 = m_vDeformedVerts[ t.nVerts[0] ].vPosition;
	const Wml::Vector2f & vDeformedV1 = m_vDeformedVerts[ t.nVerts[1] ].vPosition;
	const Wml::Vector2f & vDeformedV2 = m_vDeformedVerts[ t.nVerts[2] ].vPosition;
	double tmp[6] = { vDeformedV0.X(), vDeformedV0.Y(), 
					  vDeformedV1.X(), vDeformedV1.Y(), 
					  vDeformedV2.X(), vDeformedV2.Y() };
	Wml::GVectord vDeformed( 6, tmp );
	Wml::GVectord mCVec = t.mC * vDeformed;

	// compute -MFInv * mC
	Wml::GVectord vSolution = t.mF * mCVec;

	// ok, grab deformed v0 and v1 from solution vector
	Wml::Vector2f vFitted0( (float)vSolution[0], (float)vSolution[1] );
	Wml::Vector2f vFitted1( (float)vSolution[2], (float)vSolution[3] );

	// figure out fitted2
	float x01 = t.vTriCoords[0].X();
	float y01 = t.vTriCoords[0].Y();
	Wml::Vector2f vFitted01( vFitted1 - vFitted0 );
	Wml::Vector2f vFitted01Perp( vFitted01.Y(), -vFitted01.X() );
	Wml::Vector2f vFitted2( vFitted0 + (float)x01 * vFitted01 + (float)y01 * vFitted01Perp );

	// ok now determine scale
	Wml::Vector2f & vOrigV0 = m_vInitialVerts[ t.nVerts[0] ].vPosition;
	Wml::Vector2f & vOrigV1 = m_vInitialVerts[ t.nVerts[1] ].vPosition;
	float fScale = ( vOrigV1 - vOrigV0 ).Length() / vFitted01.Length();

	// now scale triangle
	Wml::Scale( vFitted0, vFitted1, vFitted2, fScale );

	t.vScaled[0] = vFitted0;
	t.vScaled[1] = vFitted1;
	t.vScaled[2] = vFitted2;
}


void RigidMeshDeformer2D::ValidateDeformedMesh( bool bRigid )
{
	size_t nConstraints = m_vConstraints.size();
	if ( nConstraints < 2 )
		return;

	ValidateSetup();

	// make q vector of constraints
	Wml::GVectord vQ( 2 * (int)nConstraints );
	int k = 0;
	std::set<Constraint>::iterator cur(m_vConstraints.begin()), end(m_vConstraints.end());
	while ( cur != end ) {
		Constraint & c = (*cur++);
		vQ[ 2*k ] = c.vConstrainedPos.X();
		vQ[ 2*k + 1] = c.vConstrainedPos.Y();
		++k;
	}

	Wml::GVectord vU = m_mFirstMatrix * vQ;
	size_t nVerts = m_vDeformedVerts.size();
	for ( unsigned int i = 0; i < nVerts; ++i ) {
		Constraint c(i, Wml::Vector2f::ZERO);
		if ( m_vConstraints.find(c) != m_vConstraints.end() )
			continue;		
		int nRow = m_vVertexMap[i];

		double fX = vU[ 2*nRow ];
		double fY = vU[ 2*nRow + 1];
		m_vDeformedVerts[i].vPosition = Wml::Vector2f( (float)fX, (float)fY );
	}

	if ( bRigid ) {
		// ok, now scale triangles
		size_t nTris = m_vTriangles.size();
		for ( unsigned int i = 0; i < nTris; ++i )
			UpdateScaledTriangle(i);


		ApplyFittingStep();
	}
}


