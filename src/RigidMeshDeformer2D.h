#ifndef __RMSIMPLICIT_RIGID_MESH_DEFORMER_2D_H__
#define __RMSIMPLICIT_RIGID_MESH_DEFORMER_2D_H__

#include <map>
#include <set>
#include <limits>
#include <WmlBox2.h>
#include <WmlGMatrix.h>
#include "WmlLinearSystemExt.h"
#include "TriangleMesh.h"

namespace rmsmesh {


class RigidMeshDeformer2D
{
public:
	RigidMeshDeformer2D( );
	~RigidMeshDeformer2D() {};


	void ForceValidation() { ValidateSetup(); }
	void RemoveHandle( unsigned int nHandle );

/*
 * interface stuff
 */
	//unsigned int GetNumHandles();

	//const Wml::Vector2f & GetInitialHandle(unsigned int nHandle); 
	//const Wml::Vector2f & GetDeformedHandle( unsigned int nHandle );

	//! nHandle is vertex ID
	void SetDeformedHandle( unsigned int nHandle, const Wml::Vector2f & vHandle );

	//void TransformPoint( Wml::Vector2f & vTransform );
	void UnTransformPoint( Wml::Vector2f & vTransform );

/*
 * mesh handling
 */
	void InitializeFromMesh( TriangleMesh * pMesh );
	void UpdateDeformedMesh( TriangleMesh * pMesh, bool bRigid );


/*
 * debug
 */
	const Wml::Vector2f * GetTriangleVerts( unsigned int nTriangle ) { return m_vTriangles[nTriangle].vScaled; }
protected:

	struct Vertex {
		Wml::Vector2f vPosition;
	};

public:
	struct Triangle {
		unsigned int nVerts[3];

		// definition of each vertex in triangle-local coordinate system
		Wml::Vector2f vTriCoords[3];

		// un-scaled triangle
		Wml::Vector2f vScaled[3];

		// pre-computed matrices for triangle scaling step
		Wml::GMatrixd mF, mC;
	};

protected:
	std::vector<Vertex> m_vInitialVerts;
	std::vector<Vertex> m_vDeformedVerts;
	
	std::vector<Triangle> m_vTriangles;


	struct Constraint {
		unsigned int nVertex;
		Wml::Vector2f vConstrainedPos;

		Constraint() { nVertex = 0; vConstrainedPos = Wml::Vector2f::ZERO; }
		Constraint( unsigned int nVert, const Wml::Vector2f & vPos ) { nVertex = nVert; vConstrainedPos = vPos; }

		bool operator<(const Constraint & c2) const
			{ return nVertex < c2.nVertex; }
	};

	std::set<Constraint> m_vConstraints;
	void UpdateConstraint( Constraint & cons );


	bool m_bSetupValid;
	void InvalidateSetup() { m_bSetupValid = false; }
	void ValidateSetup();


	Wml::GMatrixd m_mFirstMatrix;
	std::vector<unsigned int> m_vVertexMap;
	Wml::GMatrixd m_mHXPrime, m_mHYPrime;
	Wml::GMatrixd m_mDX, m_mDY;

	Wml::LinearSystemExtd::LUData m_mLUDecompX, m_mLUDecompY;

	void PrecomputeOrientationMatrix();
	void PrecomputeScalingMatrices( unsigned int nTriangle );
	void PrecomputeFittingMatrices();

	void ValidateDeformedMesh( bool bRigid );
	void UpdateScaledTriangle( unsigned int nTriangle );
	void ApplyFittingStep();

	Wml::Vector2f GetInitialVert( unsigned int nVert ) 
	  { return Wml::Vector2f( m_vInitialVerts[ nVert ].vPosition.X(), m_vInitialVerts[ nVert ].vPosition.Y() ); }
};


} // namespace rmsimplicit


#endif // __RMSIMPLICIT_RIGID_MESH_DEFORMER_2D_H__
