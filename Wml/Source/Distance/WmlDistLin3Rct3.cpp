// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#include "WmlDistLin3Lin3.h"
#include "WmlDistLin3Rct3.h"
#include "WmlDistVec3Rct3.h"
using namespace Wml;

//----------------------------------------------------------------------------
template <class Real>
Real Wml::SqrDistance (const Line3<Real>& rkLine,
    const Rectangle3<Real>& rkRct, Real* pfLinP, Real* pfRctP0, Real* pfRctP1)
{
    Vector3<Real> kDiff = rkRct.Origin() - rkLine.Origin();
    Real fA00 = rkLine.Direction().SquaredLength();
    Real fA01 = -rkLine.Direction().Dot(rkRct.Edge0());
    Real fA02 = -rkLine.Direction().Dot(rkRct.Edge1());
    Real fA11 = rkRct.Edge0().SquaredLength();
    Real fA22 = rkRct.Edge1().SquaredLength();
    Real fB0  = -kDiff.Dot(rkLine.Direction());
    Real fB1  = kDiff.Dot(rkRct.Edge0());
    Real fB2  = kDiff.Dot(rkRct.Edge1());
    Real fCof00 = fA11*fA22;
    Real fCof01 = -fA01*fA22;
    Real fCof02 = -fA02*fA11;
    Real fDet = fA00*fCof00+fA01*fCof01+fA02*fCof02;

    Segment3<Real> kSegPgm;
    Real fSqrDist, fSqrDist0, fR, fS, fT, fR0, fS0, fT0;

    if ( Math<Real>::FAbs(fDet) >= Math<Real>::EPSILON )
    {
        Real fCof11 = fA00*fA22-fA02*fA02;
        Real fCof12 = fA02*fA01;
        Real fCof22 = fA00*fA11-fA01*fA01;
        Real fInvDet = ((Real)1.0)/fDet;
        Real fRhs0 = -fB0*fInvDet;
        Real fRhs1 = -fB1*fInvDet;
        Real fRhs2 = -fB2*fInvDet;

        fR = fCof00*fRhs0+fCof01*fRhs1+fCof02*fRhs2;
        fS = fCof01*fRhs0+fCof11*fRhs1+fCof12*fRhs2;
        fT = fCof02*fRhs0+fCof12*fRhs1+fCof22*fRhs2;

        if ( fS < (Real)0.0 )
        {
            if ( fT < (Real)0.0 )  // region 6
            {
                // min on face s=0 or t=0
                kSegPgm.Origin() = rkRct.Origin();
                kSegPgm.Direction() = rkRct.Edge1();
                fSqrDist = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fT);
                fS = (Real)0.0;
                kSegPgm.Origin() = rkRct.Origin();
                kSegPgm.Direction() = rkRct.Edge0();
                fSqrDist0 = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fS0);
                fT0 = (Real)0.0;
                if ( fSqrDist0 < fSqrDist )
                {
                    fSqrDist = fSqrDist0;
                    fS = fS0;
                    fT = fT0;
                }
            }
            else if ( fT <= (Real)1.0 )  // region 5
            {
                // min on face s=0
                kSegPgm.Origin() = rkRct.Origin();
                kSegPgm.Direction() = rkRct.Edge1();
                fSqrDist = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fT);
                fS = (Real)0.0;
            }
            else  // region 4
            {
                // min on face s=0 or t=1
                kSegPgm.Origin() = rkRct.Origin();
                kSegPgm.Direction() = rkRct.Edge1();
                fSqrDist = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fT);
                fS = (Real)0.0;
                kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                kSegPgm.Direction() = rkRct.Edge0();
                fSqrDist0 = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fS0);
                fT0 = (Real)1.0;
                if ( fSqrDist0 < fSqrDist )
                {
                    fSqrDist = fSqrDist0;
                    fS = fS0;
                    fT = fT0;
                }
            }
        }
        else if ( fS <= (Real)1.0 )
        {
            if ( fT < (Real)0.0 )  // region 7
            {
                // min on face t=0
                kSegPgm.Origin() = rkRct.Origin();
                kSegPgm.Direction() = rkRct.Edge0();
                fSqrDist = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fS);
                fT = (Real)0.0;
            }
            else if ( fT <= (Real)1.0 )  // region 0
            {
                // line intersects rectangle
                fSqrDist = (Real)0.0;
            }
            else  // region 3
            {
                // min on face t=1
                kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                kSegPgm.Direction() = rkRct.Edge0();
                fSqrDist = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fS);
                fT = (Real)1.0;
            }
        }
        else
        {
            if ( fT < (Real)0.0 )  // region 8
            {
                // min on face s=1 or t=0
                kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                kSegPgm.Direction() = rkRct.Edge1();
                fSqrDist = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fT);
                fS = (Real)1.0;
                kSegPgm.Origin() = rkRct.Origin();
                kSegPgm.Direction() = rkRct.Edge0();
                fSqrDist0 = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fS0);
                fT0 = (Real)0.0;
                if ( fSqrDist0 < fSqrDist )
                {
                    fSqrDist = fSqrDist0;
                    fS = fS0;
                    fT = fT0;
                }
            }
            else if ( fT <= (Real)1.0 )  // region 1
            {
                // min on face s=1
                kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                kSegPgm.Direction() = rkRct.Edge1();
                fSqrDist = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fT);
                fS = (Real)1.0;
            }
            else  // region 2
            {
                // min on face s=1 or t=1
                kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                kSegPgm.Direction() = rkRct.Edge1();
                fSqrDist = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fT);
                fS = (Real)1.0;
                kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                kSegPgm.Direction() = rkRct.Edge0();
                fSqrDist0 = SqrDistance<Real>(rkLine,kSegPgm,NULL,&fS0);
                fT0 = (Real)1.0;
                if ( fSqrDist0 < fSqrDist )
                {
                    fSqrDist = fSqrDist0;
                    fS = fS0;
                    fT = fT0;
                }
            }
        }
    }
    else
    {
        // line and rectangle are parallel
        kSegPgm.Origin() = rkRct.Origin();
        kSegPgm.Direction() = rkRct.Edge0();
        fSqrDist = SqrDistance(rkLine,kSegPgm,&fR,&fS);
        fT = (Real)0.0;

        kSegPgm.Direction() = rkRct.Edge1();
        fSqrDist0 = SqrDistance(rkLine,kSegPgm,&fR0,&fT0);
        fS0 = (Real)0.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
        kSegPgm.Direction() = rkRct.Edge0();
        fSqrDist0 = SqrDistance(rkLine,kSegPgm,&fR0,&fS0);
        fT0 = (Real)1.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
        kSegPgm.Direction() = rkRct.Edge1();
        fSqrDist0 = SqrDistance(rkLine,kSegPgm,&fR0,&fT0);
        fS0 = (Real)1.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }
    }

    if ( pfLinP )
        *pfLinP = fR;

    if ( pfRctP0 )
        *pfRctP0 = fS;

    if ( pfRctP1 )
        *pfRctP1 = fT;

    return Math<Real>::FAbs(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real Wml::SqrDistance (const Ray3<Real>& rkRay,
    const Rectangle3<Real>& rkRct, Real* pfRayP, Real* pfRctP0, Real* pfRctP1)
{
    Vector3<Real> kDiff = rkRct.Origin() - rkRay.Origin();
    Real fA00 = rkRay.Direction().SquaredLength();
    Real fA01 = -rkRay.Direction().Dot(rkRct.Edge0());
    Real fA02 = -rkRay.Direction().Dot(rkRct.Edge1());
    Real fA11 = rkRct.Edge0().SquaredLength();
    Real fA22 = rkRct.Edge1().SquaredLength();
    Real fB0  = -kDiff.Dot(rkRay.Direction());
    Real fB1  = kDiff.Dot(rkRct.Edge0());
    Real fB2  = kDiff.Dot(rkRct.Edge1());
    Real fCof00 = fA11*fA22;
    Real fCof01 = -fA01*fA22;
    Real fCof02 = -fA02*fA11;
    Real fDet = fA00*fCof00+fA01*fCof01+fA02*fCof02;

    Segment3<Real> kSegPgm;
    Real fSqrDist, fSqrDist0, fR, fS, fT, fR0, fS0, fT0;

    if ( Math<Real>::FAbs(fDet) >= Math<Real>::EPSILON )
    {
        Real fCof11 = fA00*fA22-fA02*fA02;
        Real fCof12 = fA02*fA01;
        Real fCof22 = fA00*fA11-fA01*fA01;
        Real fInvDet = ((Real)1.0)/fDet;
        Real fRhs0 = -fB0*fInvDet;
        Real fRhs1 = -fB1*fInvDet;
        Real fRhs2 = -fB2*fInvDet;

        fR = fCof00*fRhs0+fCof01*fRhs1+fCof02*fRhs2;
        fS = fCof01*fRhs0+fCof11*fRhs1+fCof12*fRhs2;
        fT = fCof02*fRhs0+fCof12*fRhs1+fCof22*fRhs2;

        if ( fR <= (Real)0.0 )
        {
            if ( fS < (Real)0.0 )
            {
                if ( fT < (Real)0.0 )  // region 6m
                {
                    // min on face s=0 or t=0 or r=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkRay,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkRay,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    fSqrDist0 = SqrDistance(rkRay.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 5m
                {
                    // min on face s=0 or r=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkRay,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                    fSqrDist0 = SqrDistance(rkRay.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else  // region 4m
                {
                    // min on face s=0 or t=1 or r=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkRay,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkRay,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    fSqrDist0 = SqrDistance(rkRay.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
            else if ( fS <= (Real)1.0 )
            {
                if ( fT < (Real)0.0 )  // region 7m
                {
                    // min on face t=0 or r=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist = SqrDistance(rkRay,kSegPgm,&fR,&fS);
                    fT = (Real)0.0;
                    fSqrDist0 = SqrDistance(rkRay.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 0m
                {
                    // min on face r=0
                    fSqrDist = SqrDistance(rkRay.Origin(),rkRct,&fS,&fT);
                    fR = (Real)0.0;
                }
                else  // region 3m
                {
                    // min on face t=1 or r=0
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist = SqrDistance(rkRay,kSegPgm,&fR,&fS);
                    fT = (Real)1.0;
                    fSqrDist0 = SqrDistance(rkRay.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
            else
            {
                if ( fT < (Real)0.0 )  // region 8m
                {
                    // min on face s=1 or t=0 or r=0
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkRay,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkRay,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    fSqrDist0 = SqrDistance(rkRay.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 1m
                {
                    // min on face s=1 or r=0
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkRay,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                    fSqrDist0 = SqrDistance(rkRay.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else  // region 2m
                {
                    // min on face s=1 or t=1 or r=0
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkRay,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkRay,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    fSqrDist0 = SqrDistance(rkRay.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
        }
        else  // fR > 0
        {
            if ( fS < (Real)0.0 )
            {
                if ( fT < (Real)0.0 )  // region 6p
                {
                    // min on face s=0 or t=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fT);
                    fS = (Real)0.0;
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fS0);
                    fT0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 5p
                {
                    // min on face s=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fT);
                    fS = (Real)0.0;
                }
                else  // region 4p
                {
                    // min on face s=0 or t=1
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fT);
                    fS = (Real)0.0;
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fS0);
                    fT0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
            else if ( fS <= (Real)1.0 )
            {
                if ( fT < (Real)0.0 )  // region 7p
                {
                    // min on face t=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fS);
                    fT = (Real)0.0;
                }
                else if ( fT <= (Real)1.0 )  // region 0p
                {
                    // ray intersects the rectangle
                    fSqrDist = (Real)0.0;
                }
                else  // region 3p
                {
                    // min on face t=1
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fS);
                    fT = (Real)1.0;
                }
            }
            else
            {
                if ( fT < (Real)0.0 )  // region 8p
                {
                    // min on face s=1 or t=0
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fT);
                    fS = (Real)1.0;
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fS0);
                    fT0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 1p
                {
                    // min on face s=1
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fT);
                    fS = (Real)1.0;
                }
                else  // region 2p
                {
                    // min on face s=1 or t=1
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fT);
                    fS = (Real)1.0;
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance<Real>(rkRay,kSegPgm,NULL,&fS0);
                    fT0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
        }
    }
    else
    {
        // ray and rectangle are parallel
        kSegPgm.Origin() = rkRct.Origin();
        kSegPgm.Direction() = rkRct.Edge0();
        fSqrDist = SqrDistance(rkRay,kSegPgm,&fR,&fS);
        fT = (Real)0.0;

        kSegPgm.Direction() = rkRct.Edge1();
        fSqrDist0 = SqrDistance(rkRay,kSegPgm,&fR0,&fT0);
        fS0 = (Real)0.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
        kSegPgm.Direction() = rkRct.Edge0();
        fSqrDist0 = SqrDistance(rkRay,kSegPgm,&fR0,&fS0);
        fT0 = (Real)1.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
        kSegPgm.Direction() = rkRct.Edge1();
        fSqrDist0 = SqrDistance(rkRay,kSegPgm,&fR0,&fT0);
        fS0 = (Real)1.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        fSqrDist0 = SqrDistance(rkRay.Origin(),rkRct,&fS0,&fT0);
        fR0 = (Real)0.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }
    }

    if ( pfRayP )
        *pfRayP = fR;

    if ( pfRctP0 )
        *pfRctP0 = fS;

    if ( pfRctP1 )
        *pfRctP1 = fT;

    return Math<Real>::FAbs(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real Wml::SqrDistance (const Segment3<Real>& rkSeg,
    const Rectangle3<Real>& rkRct, Real* pfSegP, Real* pfRctP0, Real* pfRctP1)
{
    Vector3<Real> kDiff = rkRct.Origin() - rkSeg.Origin();
    Real fA00 = rkSeg.Direction().SquaredLength();
    Real fA01 = -rkSeg.Direction().Dot(rkRct.Edge0());
    Real fA02 = -rkSeg.Direction().Dot(rkRct.Edge1());
    Real fA11 = rkRct.Edge0().SquaredLength();
    Real fA22 = rkRct.Edge1().SquaredLength();
    Real fB0  = -kDiff.Dot(rkSeg.Direction());
    Real fB1  = kDiff.Dot(rkRct.Edge0());
    Real fB2  = kDiff.Dot(rkRct.Edge1());
    Real fCof00 = fA11*fA22;
    Real fCof01 = -fA01*fA22;
    Real fCof02 = -fA02*fA11;
    Real fDet = fA00*fCof00+fA01*fCof01+fA02*fCof02;

    Segment3<Real> kSegPgm;
    Vector3<Real> kPt;
    Real fSqrDist, fSqrDist0, fR, fS, fT, fR0, fS0, fT0;

    if ( Math<Real>::FAbs(fDet) >= Math<Real>::EPSILON )
    {
        Real fCof11 = fA00*fA22-fA02*fA02;
        Real fCof12 = fA02*fA01;
        Real fCof22 = fA00*fA11-fA01*fA01;
        Real fInvDet = ((Real)1.0)/fDet;
        Real fRhs0 = -fB0*fInvDet;
        Real fRhs1 = -fB1*fInvDet;
        Real fRhs2 = -fB2*fInvDet;

        fR = fCof00*fRhs0+fCof01*fRhs1+fCof02*fRhs2;
        fS = fCof01*fRhs0+fCof11*fRhs1+fCof12*fRhs2;
        fT = fCof02*fRhs0+fCof12*fRhs1+fCof22*fRhs2;

        if ( fR < (Real)0.0 )
        {
            if ( fS < (Real)0.0 )
            {
                if ( fT < (Real)0.0 )  // region 6m
                {
                    // min on face s=0 or t=0 or r=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    fSqrDist0 = SqrDistance(rkSeg.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 5m
                {
                    // min on face s=0 or r=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                    fSqrDist0 = SqrDistance(rkSeg.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else  // region 4m
                {
                    // min on face s=0 or t=1 or r=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    fSqrDist0 = SqrDistance(rkSeg.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
            else if ( fS <= (Real)1.0 )
            {
                if ( fT < (Real)0.0 )  // region 7m
                {
                    // min on face t=0 or r=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fS);
                    fT = (Real)0.0;
                    fSqrDist0 = SqrDistance(rkSeg.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 0m
                {
                    // min on face r=0
                    fSqrDist = SqrDistance(rkSeg.Origin(),rkRct,&fS,&fT);
                    fR = (Real)0.0;
                }
                else  // region 3m
                {
                    // min on face t=1 or r=0
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fS);
                    fT = (Real)1.0;
                    fSqrDist0 = SqrDistance(rkSeg.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
            else
            {
                if ( fT < (Real)0.0 )  // region 8m
                {
                    // min on face s=1 or t=0 or r=0
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    fSqrDist0 = SqrDistance(rkSeg.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 1m
                {
                    // min on face s=1 or r=0
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                    fSqrDist0 = SqrDistance(rkSeg.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else  // region 2m
                {
                    // min on face s=1 or t=1 or r=0
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    fSqrDist0 = SqrDistance(rkSeg.Origin(),rkRct,&fS0,&fT0);
                    fR0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
        }
        else if ( fR <= (Real)1.0 )
        {
            if ( fS < (Real)0.0 )
            {
                if ( fT < (Real)0.0 )  // region 6
                {
                    // min on face s=0 or t=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 5
                {
                    // min on face s=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                }
                else // region 4
                {
                    // min on face s=0 or t=1
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
            else if ( fS <= (Real)1.0 )
            {
                if ( fT < (Real)0.0 )  // region 7
                {
                    // min on face t=0
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fS);
                    fT = (Real)0.0;
                }
                else if ( fT <= (Real)1.0 )  // region 0
                {
                    // global minimum is interior
                    fSqrDist = fR*(fA00*fR+fA01*fS+fA02*fT+((Real)2.0)*fB0)
                          +fS*(fA01*fR+fA11*fS+((Real)2.0)*fB1)
                          +fT*(fA02*fR+fA22*fT+((Real)2.0)*fB2)
                          +kDiff.SquaredLength();
                }
                else  // region 3
                {
                    // min on face t=1
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fS);
                    fT = (Real)1.0;
                }
            }
            else
            {
                if ( fT < 0.0 )  // region 8
                {
                    // min on face s=1 or t=0
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 1
                {
                    // min on face s=1
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                }
                else  // region 2
                {
                    // min on face s=1 or t=1
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
        }
        else
        {
            if ( fS < (Real)0.0 )
            {
                if ( fT < (Real)0.0 )  // region 6p
                {
                    // min on face s=0 or t=0 or r=1
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    kPt = rkSeg.Origin()+rkSeg.Direction();
                    fSqrDist0 = SqrDistance(kPt,rkRct,&fS0,&fT0);
                    fR0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 5p
                {
                    // min on face s=0 or r=1
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                    fSqrDist0 = SqrDistance(rkSeg.Origin(),rkRct,&fS0,&fT0);
                    kPt = rkSeg.Origin()+rkSeg.Direction();
                    fSqrDist0 = SqrDistance(kPt,rkRct,&fS0,&fT0);
                    fR0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else  // region 4p
                {
                    // min on face s=0 or t=1 or r=1
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)0.0;
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    kPt = rkSeg.Origin()+rkSeg.Direction();
                    fSqrDist0 = SqrDistance(kPt,rkRct,&fS0,&fT0);
                    fR0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
            else if ( fS <= (Real)1.0 )
            {
                if ( fT < (Real)0.0 )  // region 7p
                {
                    // min on face t=0 or r=1
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fS);
                    fT = (Real)0.0;
                    kPt = rkSeg.Origin()+rkSeg.Direction();
                    fSqrDist0 = SqrDistance(kPt,rkRct,&fS0,&fT0);
                    fR0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 0p
                {
                    // min on face r=1
                    kPt = rkSeg.Origin()+rkSeg.Direction();
                    fSqrDist = SqrDistance(kPt,rkRct,&fS,&fT);
                    fR = (Real)1.0;
                }
                else  // region 3p
                {
                    // min on face t=1 or r=1
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fS);
                    fT = (Real)1.0;
                    kPt = rkSeg.Origin()+rkSeg.Direction();
                    fSqrDist0 = SqrDistance(kPt,rkRct,&fS0,&fT0);
                    fR0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
            else
            {
                if ( fT < (Real)0.0 )  // region 8p
                {
                    // min on face s=1 or t=0 or r=1
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                    kSegPgm.Origin() = rkRct.Origin();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)0.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    kPt = rkSeg.Origin()+rkSeg.Direction();
                    fSqrDist0 = SqrDistance(kPt,rkRct,&fS0,&fT0);
                    fR0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if ( fT <= (Real)1.0 )  // region 1p
                {
                    // min on face s=1 or r=1
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                    kPt = rkSeg.Origin()+rkSeg.Direction();
                    fSqrDist0 = SqrDistance(kPt,rkRct,&fS0,&fT0);
                    fR0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else  // region 2p
                {
                    // min on face s=1 or t=1 or r=1
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
                    kSegPgm.Direction() = rkRct.Edge1();
                    fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fT);
                    fS = (Real)1.0;
                    kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
                    kSegPgm.Direction() = rkRct.Edge0();
                    fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
                    fT0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    kPt = rkSeg.Origin()+rkSeg.Direction();
                    fSqrDist0 = SqrDistance(kPt,rkRct,&fS0,&fT0);
                    fR0 = (Real)1.0;
                    if ( fSqrDist0 < fSqrDist )
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
        }
    }
    else
    {
        // segment and rectangle are parallel
        kSegPgm.Origin() = rkRct.Origin();
        kSegPgm.Direction() = rkRct.Edge0();
        fSqrDist = SqrDistance(rkSeg,kSegPgm,&fR,&fS);
        fT = (Real)0.0;

        kSegPgm.Direction() = rkRct.Edge1();
        fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fT0);
        fS0 = (Real)0.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge1();
        kSegPgm.Direction() = rkRct.Edge0();
        fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fS0);
        fT0 = (Real)1.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        kSegPgm.Origin() = rkRct.Origin()+rkRct.Edge0();
        kSegPgm.Direction() = rkRct.Edge1();
        fSqrDist0 = SqrDistance(rkSeg,kSegPgm,&fR0,&fT0);
        fS0 = (Real)1.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        fSqrDist0 = SqrDistance(rkSeg.Origin(),rkRct,&fS0,&fT0);
        fR0 = (Real)0.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        kPt = rkSeg.Origin()+rkSeg.Direction();
        fSqrDist0 = SqrDistance(kPt,rkRct,&fS0,&fT0);
        fR0 = (Real)1.0;
        if ( fSqrDist0 < fSqrDist )
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }
    }

    if ( pfSegP )
        *pfSegP = fR;

    if ( pfRctP0 )
        *pfRctP0 = fS;

    if ( pfRctP1 )
        *pfRctP1 = fT;

    return Math<Real>::FAbs(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real Wml::Distance (const Line3<Real>& rkLine, const Rectangle3<Real>& rkRct,
    Real* pfLinP, Real* pfRctP0, Real* pfRctP1)
{
    return Math<Real>::Sqrt(SqrDistance(rkLine,rkRct,pfLinP,pfRctP0,pfRctP1));
}
//----------------------------------------------------------------------------
template <class Real>
Real Wml::Distance (const Ray3<Real>& rkRay, const Rectangle3<Real>& rkRct,
    Real* pfRayP, Real* pfRctP0, Real* pfRctP1)
{
    return Math<Real>::Sqrt(SqrDistance(rkRay,rkRct,pfRayP,pfRctP0,pfRctP1));
}
//----------------------------------------------------------------------------
template <class Real>
Real Wml::Distance (const Segment3<Real>& rkSeg,
    const Rectangle3<Real>& rkRct, Real* pfSegP, Real* pfRctP0, Real* pfRctP1)
{
    return Math<Real>::Sqrt(SqrDistance(rkSeg,rkRct,pfSegP,pfRctP0,pfRctP1));
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
namespace Wml
{
template WML_ITEM float SqrDistance<float> (const Line3<float>&,
    const Rectangle3<float>&, float*, float*, float*);
template WML_ITEM float SqrDistance<float> (const Ray3<float>&,
    const Rectangle3<float>&, float*, float*, float*);
template WML_ITEM float SqrDistance<float> (const Segment3<float>&,
    const Rectangle3<float>&, float*, float*, float*);
template WML_ITEM float Distance<float> (const Line3<float>&,
    const Rectangle3<float>&, float*, float*, float*);
template WML_ITEM float Distance<float> (const Ray3<float>&,
    const Rectangle3<float>&, float*, float*, float*);
template WML_ITEM float Distance<float> (const Segment3<float>&,
    const Rectangle3<float>&, float*, float*, float*);

template WML_ITEM double SqrDistance<double> (const Line3<double>&,
    const Rectangle3<double>&, double*, double*, double*);
template WML_ITEM double SqrDistance<double> (const Ray3<double>&,
    const Rectangle3<double>&, double*, double*, double*);
template WML_ITEM double SqrDistance<double> (const Segment3<double>&,
    const Rectangle3<double>&, double*, double*, double*);
template WML_ITEM double Distance<double> (const Line3<double>&,
    const Rectangle3<double>&, double*, double*, double*);
template WML_ITEM double Distance<double> (const Ray3<double>&,
    const Rectangle3<double>&, double*, double*, double*);
template WML_ITEM double Distance<double> (const Segment3<double>&,
    const Rectangle3<double>&, double*, double*, double*);
}
//----------------------------------------------------------------------------
