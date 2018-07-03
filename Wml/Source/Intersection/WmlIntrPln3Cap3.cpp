// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#include "WmlIntrPln3Cap3.h"
using namespace Wml;

//----------------------------------------------------------------------------
template <class Real>
bool Wml::TestIntersection (const Plane3<Real>& rkPlane,
    const Capsule3<Real>& rkCapsule, bool bUnitNormal)
{
    Vector3<Real> kNormal = rkPlane.GetNormal();
    Real fConstant = rkPlane.GetConstant();
    if ( !bUnitNormal )
    {
        Real fLength = kNormal.Normalize();
        fConstant /= fLength;
    }

    Real fTmp0 = kNormal.Dot(rkCapsule.Origin()) - fConstant;
    Real fTmp1 = fTmp0 + kNormal.Dot(rkCapsule.Direction());
    if ( fTmp0*fTmp1 <= (Real)0.0 )
    {
        // capsule ends on opposite sides of the plane
        return true;
    }
    else
    {
        return Math<Real>::FAbs(fTmp0) <= rkCapsule.Radius()
            || Math<Real>::FAbs(fTmp1) <= rkCapsule.Radius();
    }
}
//----------------------------------------------------------------------------
template <class Real>
bool Wml::Culled (const Plane3<Real>& rkPlane,
    const Capsule3<Real>& rkCapsule, bool bUnitNormal)
{
    Vector3<Real> kNormal = rkPlane.GetNormal();
    Real fConstant = rkPlane.GetConstant();
    if ( !bUnitNormal )
    {
        Real fLength = kNormal.Normalize();
        fConstant /= fLength;
    }

    Real fTmp0 = kNormal.Dot(rkCapsule.Origin()) - fConstant;
    if ( fTmp0 < (Real)0.0 )
    {
        Real fTmp1 = fTmp0 + kNormal.Dot(rkCapsule.Direction());
        if ( fTmp1 < (Real)0.0 )
        {
            if ( fTmp0 <= fTmp1 )
                return fTmp0 <= -rkCapsule.Radius();
            else
                return fTmp1 <= -rkCapsule.Radius();
        }
    }

    return false;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
namespace Wml
{
template WML_ITEM bool TestIntersection<float> (const Plane3<float>&,
    const Capsule3<float>&, bool);
template WML_ITEM bool Culled<float> (const Plane3<float>&,
    const Capsule3<float>&, bool);

template WML_ITEM bool TestIntersection<double> (const Plane3<double>&,
    const Capsule3<double>&, bool);
template WML_ITEM bool Culled<double> (const Plane3<double>&,
    const Capsule3<double>&, bool);
}
//----------------------------------------------------------------------------
