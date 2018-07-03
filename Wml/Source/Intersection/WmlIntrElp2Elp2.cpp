// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#include "WmlIntrElp2Elp2.h"
#include "WmlPolynomial1.h"
#include "WmlPolynomialRoots.h"
#include "WmlMatrix2.h"
using namespace Wml;

//----------------------------------------------------------------------------
template <class Real>
static void GetAABB (const Vector2<Real>& rkC, const Vector2<Real> akAxis[2],
    const Real afL[2], Real& rfXMin, Real& rfXMax, Real& rfYMin, Real& rfYMax)
{
    Real fRx = afL[0]*Math<Real>::FAbs(akAxis[0].X()) +
        afL[1]*Math<Real>::FAbs(akAxis[1].X());
    rfXMin = rkC.X() - fRx;
    rfXMax = rkC.X() + fRx;

    Real fRy = afL[0]*Math<Real>::FAbs(akAxis[0].Y()) +
        afL[1]*Math<Real>::FAbs(akAxis[1].Y());
    rfYMin = rkC.Y() - fRy;
    rfYMax = rkC.Y() + fRy;
}
//----------------------------------------------------------------------------
template <class Real>
static Real EvaluateQuadratic (const Real afQP[6], Real fX, Real fY)
{
    return (afQP[0]*fX + afQP[1]*fY + afQP[3])*fX + (afQP[2]*fY + afQP[4])*fY
        + afQP[5];
}
//----------------------------------------------------------------------------
template <class Real>
static Polynomial1<Real> GetQuartic (const Real afP0[6], const Real afP1[6],
    Real afDet[11])
{
    // polynomial is constructed as a Bezout determinant
    afDet[ 0] = afP0[0]*afP1[1] - afP1[0]*afP0[1];  // AB
    afDet[ 1] = afP0[0]*afP1[2] - afP1[0]*afP0[2];  // AC
    afDet[ 2] = afP0[0]*afP1[3] - afP1[0]*afP0[3];  // AD
    afDet[ 3] = afP0[0]*afP1[4] - afP1[0]*afP0[4];  // AE
    afDet[ 4] = afP0[0]*afP1[5] - afP1[0]*afP0[5];  // AF
    afDet[ 5] = afP0[1]*afP1[2] - afP1[1]*afP0[2];  // BC
    afDet[ 6] = afP0[1]*afP1[4] - afP1[1]*afP0[4];  // BE
    afDet[ 7] = afP0[1]*afP1[5] - afP1[1]*afP0[5];  // BF
    afDet[ 8] = afP0[2]*afP1[3] - afP1[2]*afP0[3];  // CD
    afDet[ 9] = afP0[3]*afP1[4] - afP1[3]*afP0[4];  // DE
    afDet[10] = afP0[3]*afP1[5] - afP1[3]*afP0[5];  // DF
    Real fBFpDE = afDet[7] + afDet[9];
    Real fBEmCD = afDet[6] - afDet[8];

    Real afU[5];

    // AD*DF - AF*AF
    afU[0] = afDet[2]*afDet[10] - afDet[4]*afDet[4];

    // AB*DF + AD*(BF+DE) - 2*AE*AF
    afU[1] = afDet[0]*afDet[10] + afDet[2]*fBFpDE -
        ((Real)2.0)*afDet[3]*afDet[4];

    // AB*(BF+DE) + AD*(BE - CD) - AE*AE - 2*AC*AF
    afU[2] = afDet[0]*fBFpDE + afDet[2]*fBEmCD - afDet[3]*afDet[3] -
        ((Real)2.0)*afDet[1]*afDet[4];

    // AB*(BE - CD) + AD*BC - 2*AC*AE
    afU[3] = afDet[0]*fBEmCD + afDet[2]*afDet[5] -
        ((Real)2.0)*afDet[1]*afDet[3];

    // AB*BC - AC*AC
    afU[4] = afDet[0]*afDet[5]-afDet[1]*afDet[1];

    // reduce degree if necessary
    int iDegree = 4;
    while ( iDegree > 0
    &&      Math<Real>::FAbs(afU[iDegree]) < Math<Real>::EPSILON )
    {
        iDegree--;
    }

    Polynomial1<Real> kPoly(iDegree);
    memcpy(&kPoly[0],afU,(iDegree+1)*sizeof(Real));
    return kPoly;
}
//----------------------------------------------------------------------------
template <class Real>
void Wml::ConvertEllipseToQuadratic (const Vector2<Real>& rkC,
    const Vector2<Real> akAxis[2], const Real afL[2], Real afQuad[6])
{
    Vector2<Real> akScaledAxis[2] =
    {
        akAxis[0]/afL[0],
        akAxis[1]/afL[1]
    };

    Matrix2<Real> kTensor0(akScaledAxis[0],akScaledAxis[0]);
    Matrix2<Real> kTensor1(akScaledAxis[1],akScaledAxis[1]);
    Matrix2<Real> kA = kTensor0 + kTensor1;
    Vector2<Real> kPrd = kA*rkC;
    Vector2<Real> kB = -((Real)2.0)*kPrd;
    Real fC = rkC.Dot(kPrd) - (Real)1.0;

    afQuad[0] = kA[0][0];
    afQuad[1] = ((Real)2.0)*kA[0][1];
    afQuad[2] = kA[1][1];
    afQuad[3] = kB[0];
    afQuad[4] = kB[1];
    afQuad[5] = fC;

    Real fMax = Math<Real>::FAbs(afQuad[0]);
    int i;
    for (i = 1; i < 6; i++)
    {
        Real fTest = Math<Real>::FAbs(afQuad[i]);
        if ( fTest > fMax )
            fMax = fTest;
    }

    Real fInvMax = ((Real)1.0)/fMax;
    for (i = 0; i < 6; i++)
        afQuad[i] *= fInvMax;
}
//----------------------------------------------------------------------------
template <class Real>
static void ScaleEllipsesToQuadratics (const Vector2<Real>& rkC0,
    const Vector2<Real> akAxis0[2], const Real afL0[2],
    const Vector2<Real>& rkC1, const Vector2<Real> akAxis1[2],
    const Real afL1[2], Real afQP0[6], Real afQP1[6], Real& rfMin,
    Real& rfHalfRange)
{
    // The ellipse E[i] is contained in the oriented rectangle with vertices
    //   C[i] + s0*L[i][0]*U[i] + s1*L[i][1]*V[i]
    // where |s0| = 1 and |s1| = 1 (four choices).  The implementation for
    // finding intersections first computes the smallest axis-aligned
    // rectangle that contains the oriented rectangles of the ellipses.  The
    // bounding rectangle is mapped to the square [-1,1]^2.  This portion of
    // the algorithm is designed to help keep the floating point calculations
    // robust in the root finding.

    // construct axis-aligned bounding rectangle for E0
    Real fXMin0, fXMax0, fYMin0, fYMax0;
    GetAABB(rkC0,akAxis0,afL0,fXMin0,fXMax0,fYMin0,fYMax0);

    // construct axis-aligned bounding rectangle for E1
    Real fXMin1, fXMax1, fYMin1, fYMax1;
    GetAABB(rkC1,akAxis1,afL1,fXMin1,fXMax1,fYMin1,fYMax1);

    // construct axis-aligned bounding square of bounding rectangles
    Real fMin = fXMin0, fMax = fXMax0;
    if ( fXMin1 < fMin ) fMin = fXMin1;
    if ( fXMax1 > fMax ) fMax = fXMax1;
    if ( fYMin0 < fMin ) fMin = fYMin0;
    if ( fYMax0 > fMax ) fMax = fYMax0;
    if ( fYMin1 < fMin ) fMin = fYMin1;
    if ( fYMax1 > fMax ) fMax = fYMax1;

    Real fHalfRange = ((Real)0.5)*(fMax - fMin);
    Real fInvHalfRange = ((Real)1.0)/fHalfRange;

    // map ellipses to bounding square [-1,1]^2
    Vector2<Real> kC0Tmp, kC1Tmp;
    Real afL0Tmp[2], afL1Tmp[2];

    kC0Tmp.X() = -(Real)1.0 + fInvHalfRange*(rkC0.X() - fMin);
    kC0Tmp.Y() = -(Real)1.0 + fInvHalfRange*(rkC0.Y() - fMin);
    kC1Tmp.X() = -(Real)1.0 + fInvHalfRange*(rkC1.X() - fMin);
    kC1Tmp.Y() = -(Real)1.0 + fInvHalfRange*(rkC1.Y() - fMin);
    afL0Tmp[0] = fInvHalfRange*afL0[0];
    afL0Tmp[1] = fInvHalfRange*afL0[1];
    afL1Tmp[0] = fInvHalfRange*afL1[0];
    afL1Tmp[1] = fInvHalfRange*afL1[1];

    // convert ellipses to quadratic equations
    ConvertEllipseToQuadratic(kC0Tmp,akAxis0,afL0Tmp,afQP0);
    ConvertEllipseToQuadratic(kC1Tmp,akAxis1,afL1Tmp,afQP1);

    rfMin = fMin;
    rfHalfRange = fHalfRange;
}
//----------------------------------------------------------------------------
template <class Real>
bool Wml::FindIntersection (const Vector2<Real>& rkC0,
    const Vector2<Real> akAxis0[2], const Real afL0[2],
    const Vector2<Real>& rkC1, const Vector2<Real> akAxis1[2],
    const Real afL1[2], int& riQuantity, Vector2<Real> akP[4])
{
    Real afQP0[6], afQP1[6], fMin, fHalfRange;
    ScaleEllipsesToQuadratics(rkC0,akAxis0,afL0,rkC1,akAxis1,afL1,afQP0,afQP1,
        fMin,fHalfRange);

    // Get the 4th-degree polynomial whose roots lead to intersections of the
    // ellipses.  The y-values are in the interval [-1,1], so we only need
    // to locate roots there.  The increase to [-1.5,1.5] is to catch roots
    // that are nearly 1 or -1 without having to worry about floating point
    // round-off errors.
    Real afDet[11];
    Polynomial1<Real> kPoly = GetQuartic(afQP0,afQP1,afDet);
    PolynomialRoots<Real> kPR(Math<Real>::EPSILON);
    kPR.FindB(kPoly,-(Real)1.5,(Real)1.5,6);
    int iYCount = kPR.GetCount();
    const Real* afY = kPR.GetRoots();
    if ( iYCount == 0 )
    {
        riQuantity = 0;
        return false;
    }

    // Adjustment for quadratics to allow for relative error testing when
    // eliminating extraneous roots.
    Real fNorm0 = afQP0[0]*afQP0[0] + ((Real)2.0)*afQP0[1]*afQP0[1] +
        afQP0[2]*afQP0[2];
    Real fNorm1 = afQP1[0]*afQP1[0] + ((Real)2.0)*afQP1[1]*afQP1[1] +
        afQP1[2]*afQP1[2];

    // test roots to eliminate extraneous ones that occurred due to "squaring"
    riQuantity = 0;
    for (int iY = 0; iY < iYCount; iY++)
    {
        Real fY = afY[iY];
        Real fXNumer = -((afDet[1]*fY+afDet[3])*fY+afDet[4]);
        Real fXDenom = afDet[0]*fY + afDet[2];
        Real fX = fXNumer/fXDenom;

        const Real fEpsilon = (Real)1e-03;
        Real fTest = EvaluateQuadratic(afQP0,fX,fY);
        if ( Math<Real>::FAbs(fTest) < fEpsilon*fNorm0 )
        {
            fTest = EvaluateQuadratic(afQP1,fX,fY);
            if ( Math<Real>::FAbs(fTest) < fEpsilon*fNorm1 )
            {
                akP[riQuantity].X() = fX;
                akP[riQuantity].Y() = fY;
                riQuantity++;
            }
        }
    }

    // map intersections back to original space
    for (int i = 0; i < riQuantity; i++)
    {
        akP[i].X() = fHalfRange*(akP[i].X()+(Real)1.0) + fMin;
        akP[i].Y() = fHalfRange*(akP[i].Y()+(Real)1.0) + fMin;
    }

    return riQuantity > 0;
}
//----------------------------------------------------------------------------
template <class Real>
bool Wml::TestIntersection (const Vector2<Real>& rkC0,
    const Vector2<Real> akAxis0[2], const Real afL0[2],
    const Vector2<Real>& rkC1, const Vector2<Real> akAxis1[2],
    const Real afL1[2])
{
    Real afQP0[6], afQP1[6], fMin, fHalfRange;
    ScaleEllipsesToQuadratics(rkC0,akAxis0,afL0,rkC1,akAxis1,afL1,afQP0,afQP1,
        fMin,fHalfRange);

    Real afDet[11];
    Polynomial1<Real> kPoly = GetQuartic(afQP0,afQP1,afDet);

    PolynomialRoots<Real> kPR(Math<Real>::EPSILON);
    int iCount = kPR.GetRootCount(kPoly,-Math<Real>::MAX_REAL,
        Math<Real>::MAX_REAL);

    return iCount > 0;
}
//----------------------------------------------------------------------------
template <class Real>
bool Wml::TestIntersection (const Real afQP0[6], const Real afQP1[6])
{
    Real afDet[11];
    Polynomial1<Real> kPoly = GetQuartic(afQP0,afQP1,afDet);

    PolynomialRoots<Real> kPR(Math<Real>::EPSILON);
    int iCount = kPR.GetRootCount(kPoly,-Math<Real>::MAX_REAL,
        Math<Real>::MAX_REAL);

    return iCount > 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
namespace Wml
{
template WML_ITEM void ConvertEllipseToQuadratic<float> (
    const Vector2<float>&, const Vector2<float>[2], const float[2],
    float[6]);
template WML_ITEM bool FindIntersection<float> (
    const Vector2<float>&, const Vector2<float>[2], const float[2],
    const Vector2<float>&, const Vector2<float>[2],  const float[2],
    int&, Vector2<float>[4]);
template WML_ITEM bool TestIntersection<float> (
    const Vector2<float>&, const Vector2<float>[2], const float[2],
    const Vector2<float>&, const Vector2<float>[2], const float[2]);
template WML_ITEM bool TestIntersection<float> (const float[6],
    const float[6]);

template WML_ITEM void ConvertEllipseToQuadratic<double> (
    const Vector2<double>&, const Vector2<double>[2], const double[2],
    double[6]);
template WML_ITEM bool FindIntersection<double> (
    const Vector2<double>&, const Vector2<double>[2], const double[2],
    const Vector2<double>&, const Vector2<double>[2],  const double[2],
    int&, Vector2<double>[4]);
template WML_ITEM bool TestIntersection<double> (
    const Vector2<double>&, const Vector2<double>[2], const double[2],
    const Vector2<double>&, const Vector2<double>[2], const double[2]);
template WML_ITEM bool TestIntersection<double> (const double[6],
    const double[6]);
}
//----------------------------------------------------------------------------
