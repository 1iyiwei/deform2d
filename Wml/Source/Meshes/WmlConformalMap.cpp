// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#include "WmlConformalMap.h"
#include "WmlBasicMesh.h"
#include "WmlLinearSystem.h"
#include "WmlPolynomialRoots.h"
using namespace Wml;

#include <utility>
using namespace std;

//----------------------------------------------------------------------------
template <class Real>
ConformalMap<Real>::ConformalMap (int iVQuantity, Vector3<Real>* akPoint,
    int iTQuantity, const int* aiConnect)
{
    // construct a vertex-triangle-edge representation of mesh
    BasicMesh kMesh(iVQuantity,akPoint,iTQuantity,aiConnect);
    int iEQuantity = kMesh.GetEQuantity();
    const BasicMesh::Edge* akEdge = kMesh.GetEdges();
    const BasicMesh::Triangle* akTriangle = kMesh.GetTriangles();

    m_akPlane = new Vector2<Real>[iVQuantity];
    m_akSphere = new Vector3<Real>[iVQuantity];

    // construct sparse matrix A nondiagonal entries
    typename LinearSystem<Real>::SparseMatrix kAMat;
    int i, iE, iT, iV0, iV1, iV2;
    Real fValue;
    for (iE = 0; iE < iEQuantity; iE++)
    {
        const BasicMesh::Edge& rkE = akEdge[iE];
        iV0 = rkE.V[0];
        iV1 = rkE.V[1];

        Vector3<Real> kE0, kE1;

        const BasicMesh::Triangle& rkT0 = akTriangle[rkE.T[0]];
        for (i = 0; i < 3; i++)
        {
            iV2 = rkT0.V[i];
            if ( iV2 != iV0 && iV2 != iV1 )
            {
                kE0 = akPoint[iV0] - akPoint[iV2];
                kE1 = akPoint[iV1] - akPoint[iV2];
                fValue = kE0.Dot(kE1)/kE0.Cross(kE1).Length();
            }
        }

        const BasicMesh::Triangle& rkT1 = akTriangle[rkE.T[1]];
        for (i = 0; i < 3; i++)
        {
            iV2 = rkT1.V[i];
            if ( iV2 != iV0 && iV2 != iV1 )
            {
                kE0 = akPoint[iV0] - akPoint[iV2];
                kE1 = akPoint[iV1] - akPoint[iV2];
                fValue += kE0.Dot(kE1)/kE0.Cross(kE1).Length();
            }
        }

        fValue *= -(Real)0.5;
        kAMat[make_pair(iV0,iV1)] = fValue;
    }

    // construct sparse matrix A diagonal entries
    Real* afTmp = new Real[iVQuantity];
    memset(afTmp,0,iVQuantity*sizeof(Real));
    typename LinearSystem<Real>::SparseMatrix::iterator pkIter =
        kAMat.begin();
    for (/**/; pkIter != kAMat.end(); pkIter++)
    {
        iV0 = pkIter->first.first;
        iV1 = pkIter->first.second;
        fValue = pkIter->second;
        assert( iV0 != iV1 );
        afTmp[iV0] -= fValue;
        afTmp[iV1] -= fValue;
    }
    for (int iV = 0; iV < iVQuantity; iV++)
        kAMat[make_pair(iV,iV)] = afTmp[iV];

    assert( iVQuantity + iEQuantity == (int)kAMat.size() );

    // construct column vector B (happens to be sparse)
    const BasicMesh::Triangle& rkT = akTriangle[0];
    iV0 = rkT.V[0];
    iV1 = rkT.V[1];
    iV2 = rkT.V[2];
    Vector3<Real> kV0 = akPoint[iV0];
    Vector3<Real> kV1 = akPoint[iV1];
    Vector3<Real> kV2 = akPoint[iV2];
    Vector3<Real> kE10 = kV1 - kV0;
    Vector3<Real> kE20 = kV2 - kV0;
    Vector3<Real> kE12 = kV1 - kV2;
    Vector3<Real> kCross = kE20.Cross(kE10);
    Real fLen10 = kE10.Length();
    Real fInvLen10 = ((Real)1.0)/fLen10;
    Real fTwoArea = kCross.Length();
    Real fInvLenCross = ((Real)1.0)/fTwoArea;
    Real fInvProd = fInvLen10*fInvLenCross;
    Real fRe0 = -fInvLen10;
    Real fIm0 = fInvProd*kE12.Dot(kE10);
    Real fRe1 = fInvLen10;
    Real fIm1 = fInvProd*kE20.Dot(kE10);
    Real fRe2 = (Real)0.0;
    Real fIm2 = -fLen10*fInvLenCross;

    // solve sparse system for real parts
    memset(afTmp,0,iVQuantity*sizeof(Real));
    afTmp[iV0] = fRe0;
    afTmp[iV1] = fRe1;
    afTmp[iV2] = fRe2;
    Real* afResult = new Real[iVQuantity];
    bool bSolved = LinearSystem<Real>::SolveSymmetricCG(iVQuantity,kAMat,
        afTmp,afResult);
    assert( bSolved );
    for (i = 0; i < iVQuantity; i++)
        m_akPlane[i].X() = afResult[i];

    // solve sparse system for imaginary parts
    memset(afTmp,0,iVQuantity*sizeof(Real));
    afTmp[iV0] = -fIm0;
    afTmp[iV1] = -fIm1;
    afTmp[iV2] = -fIm2;
    bSolved = LinearSystem<Real>::SolveSymmetricCG(iVQuantity,kAMat,afTmp,
        afResult);
    assert( bSolved );
    for (i = 0; i < iVQuantity; i++)
        m_akPlane[i].Y() = afResult[i];
    delete[] afTmp;
    delete[] afResult;

    // scale to [-1,1]^2 for numerical conditioning in later steps
    Real fMin = m_akPlane[0].X(), fMax = fMin;
    for (i = 0; i < iVQuantity; i++)
    {
        if ( m_akPlane[i].X() < fMin )
            fMin = m_akPlane[i].X();
        else if ( m_akPlane[i].X() > fMax )
            fMax = m_akPlane[i].X();
        if ( m_akPlane[i].Y() < fMin )
            fMin = m_akPlane[i].Y();
        else if ( m_akPlane[i].Y() > fMax )
            fMax = m_akPlane[i].Y();
    }
    Real fHalfRange = ((Real)0.5)*(fMax - fMin);
    Real fInvHalfRange = ((Real)1.0)/fHalfRange;
    for (i = 0; i < iVQuantity; i++)
    {
        m_akPlane[i].X() = -(Real)1.0+fInvHalfRange*(m_akPlane[i].X()-fMin);
        m_akPlane[i].Y() = -(Real)1.0+fInvHalfRange*(m_akPlane[i].Y()-fMin);
    }

    // Map plane points to sphere using inverse stereographic projection.
    // The main issue is selecting a translation in (x,y) and a radius of
    // the projection sphere.  Both factors strongly influence the final
    // result.

    // Use the average as the south pole.  The points tend to be clustered
    // approximately in the middle of the conformally mapped punctured
    // triangle, so the average is a good choice to place the pole.
    Vector2<Real> kOrigin((Real)0.0,(Real)0.0);
    for (i = 0; i < iVQuantity; i++)
        kOrigin += m_akPlane[i];
    kOrigin /= (Real)iVQuantity;
    for (i = 0; i < iVQuantity; i++)
        m_akPlane[i] -= kOrigin;

    m_kPlaneMin = m_akPlane[0];
    m_kPlaneMax = m_akPlane[0];
    for (i = 1; i < iVQuantity; i++)
    {
        if ( m_akPlane[i].X() < m_kPlaneMin.X() )
            m_kPlaneMin.X() = m_akPlane[i].X();
        else if ( m_akPlane[i].X() > m_kPlaneMax.X() )
            m_kPlaneMax.X() = m_akPlane[i].X();

        if ( m_akPlane[i].Y() < m_kPlaneMin.Y() )
            m_kPlaneMin.Y() = m_akPlane[i].Y();
        else if ( m_akPlane[i].Y() > m_kPlaneMax.Y() )
            m_kPlaneMax.Y() = m_akPlane[i].Y();
    }

    // Select the radius of the sphere so that the projected punctured
    // triangle has an area whose fraction of total spherical area is the
    // same fraction as the area of the punctured triangle to the total area
    // of the original triangle mesh.
    Real fTwoTotalArea = (Real)0.0;
    for (iT = 0; iT < iTQuantity; iT++)
    {
        const BasicMesh::Triangle& rkT0 = akTriangle[iT];
        const Vector3<Real>& rkV0 = akPoint[rkT0.V[0]];
        const Vector3<Real>& rkV1 = akPoint[rkT0.V[1]];
        const Vector3<Real>& rkV2 = akPoint[rkT0.V[2]];
        Vector3<Real> kE0 = rkV1 - rkV0, kE1 = rkV2 - rkV0;
        fTwoTotalArea += kE0.Cross(kE1).Length();
    }
    m_fRadius = ComputeRadius(m_akPlane[iV0],m_akPlane[iV1],m_akPlane[iV2],
        fTwoArea/fTwoTotalArea);
    Real fRadiusSqr = m_fRadius*m_fRadius;

    // Inverse stereographic projection to obtain sphere coordinates.  The
    // sphere is centered at the origin and has radius 1.
    for (i = 0; i < iVQuantity; i++)
    {
        Real fRSqr = m_akPlane[i].SquaredLength();
        Real fMult = ((Real)1.0)/(fRSqr + fRadiusSqr);
        Real fX = ((Real)2.0)*fMult*fRadiusSqr*m_akPlane[i].X();
        Real fY = ((Real)2.0)*fMult*fRadiusSqr*m_akPlane[i].Y();
        Real fZ = fMult*m_fRadius*(fRSqr-fRadiusSqr);
        m_akSphere[i] = Vector3<Real>(fX,fY,fZ)/m_fRadius;
    }
}
//----------------------------------------------------------------------------
template <class Real>
ConformalMap<Real>::~ConformalMap ()
{
    delete[] m_akPlane;
    delete[] m_akSphere;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector2<Real>* ConformalMap<Real>::GetPlaneCoordinates () const
{
    return m_akPlane;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector2<Real>& ConformalMap<Real>::GetPlaneMin () const
{
    return m_kPlaneMin;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector2<Real>& ConformalMap<Real>::GetPlaneMax () const
{
    return m_kPlaneMax;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector3<Real>* ConformalMap<Real>::GetSphereCoordinates () const
{
    return m_akSphere;
}
//----------------------------------------------------------------------------
template <class Real>
Real ConformalMap<Real>::GetSphereRadius () const
{
    return m_fRadius;
}
//----------------------------------------------------------------------------
template <class Real>
Real ConformalMap<Real>::ComputeRadius (const Vector2<Real>& rkV0,
    const Vector2<Real>& rkV1, const Vector2<Real>& rkV2, Real fAreaFraction)
    const
{
    Real fR0Sqr = rkV0.SquaredLength();
    Real fR1Sqr = rkV1.SquaredLength();
    Real fR2Sqr = rkV2.SquaredLength();
    Real fDR10 = fR1Sqr - fR0Sqr;
    Real fDR20 = fR2Sqr - fR0Sqr;
    Real fDX10 = rkV1.X() - rkV0.X();
    Real fDY10 = rkV1.Y() - rkV0.Y();
    Real fDX20 = rkV2.X() - rkV0.X();
    Real fDY20 = rkV2.Y() - rkV0.Y();
    Real fDRX10 = rkV1.X()*fR0Sqr - rkV0.X()*fR1Sqr;
    Real fDRY10 = rkV1.Y()*fR0Sqr - rkV0.Y()*fR1Sqr;
    Real fDRX20 = rkV2.X()*fR0Sqr - rkV0.X()*fR2Sqr;
    Real fDRY20 = rkV2.Y()*fR0Sqr - rkV0.Y()*fR2Sqr;

    Real fC0 = fDR20*fDRY10 - fDR10*fDRY20;
    Real fC1 = fDR20*fDY10 - fDR10*fDY20;
    Real fD0 = fDR10*fDRX20 - fDR20*fDRX10;
    Real fD1 = fDR10*fDX20 - fDR20*fDX10;
    Real fE0 = fDRX10*fDRY20 - fDRX20*fDRY10;
    Real fE1 = fDRX10*fDY20 - fDRX20*fDY10;
    Real fE2 = fDX10*fDY20 - fDX20*fDY10;

    Polynomial1<Real> kP0(6);
    kP0[0] = (Real)0.0;
    kP0[1] = (Real)0.0;
    kP0[2] = fE0*fE0;
    kP0[3] = fC0*fC0 + fD0*fD0 + ((Real)2.0)*fE0*fE1;
    kP0[4] = ((Real)2.0)*(fC0*fC1 + fD0*fD1 + fE0*fE1) + fE1*fE1;
    kP0[5] = fC1*fC1 + fD1*fD1 + ((Real)2.0)*fE1*fE2;
    kP0[6] = fE2*fE2;

    Polynomial1<Real> kQ0(1), kQ1(1), kQ2(1);
    kQ0[0] = fR0Sqr;
    kQ0[1] = (Real)1.0;
    kQ1[0] = fR1Sqr;
    kQ1[1] = (Real)1.0;
    kQ2[0] = fR2Sqr;
    kQ2[1] = (Real)1.0;

    Real fTmp = fAreaFraction*Math<Real>::PI;
    Real fAmp = fTmp*fTmp;
    Polynomial1<Real> kP1 = fAmp*kQ0;
    kP1 = kP1*kQ0;
    kP1 = kP1*kQ0;
    kP1 = kP1*kQ0;
    kP1 = kP1*kQ1;
    kP1 = kP1*kQ1;
    kP1 = kP1*kQ2;
    kP1 = kP1*kQ2;

    Polynomial1<Real> kFinal = kP1 - kP0;
    assert( kFinal.GetDegree() <= 8 );
    PolynomialRoots<Real> kPR((Real)1e-06);
    kPR.FindB(kFinal,(Real)0.0,(Real)1.0,6);
    if ( kPR.GetCount() > 0 && kPR.GetRoot(0) > (Real)0.0 )
        return Math<Real>::Sqrt(kPR.GetRoot(0));

    // Catch-all if the root finder fails.  Hopefully we do not get here.
    assert( false );
    return (Real)1.0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
namespace Wml
{
template class WML_ITEM ConformalMap<float>;
template class WML_ITEM ConformalMap<double>;
}
//----------------------------------------------------------------------------
