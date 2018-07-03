// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#ifndef WMLCONFORMALMAP_H
#define WMLCONFORMALMAP_H

#include "WmlVector2.h"
#include "WmlVector3.h"

namespace Wml
{

template <class Real>
class WML_ITEM ConformalMap
{
public:
    // The caller is responsible for deleting the input arrays.
    ConformalMap (int iVQuantity, Vector3<Real>* akPoint, int iTQuantity,
        const int* aiConnect);

    ~ConformalMap ();

    // conformal mapping of mesh to plane
    const Vector2<Real>* GetPlaneCoordinates () const;
    const Vector2<Real>& GetPlaneMin () const;
    const Vector2<Real>& GetPlaneMax () const;

    // conformal mapping of mesh to sphere (centered at origin)
    const Vector3<Real>* GetSphereCoordinates () const;
    Real GetSphereRadius () const;

private:
    Real ComputeRadius (const Vector2<Real>& rkV0, const Vector2<Real>& rkV1,
        const Vector2<Real>& rkV2, Real fAreaFraction) const;

    // Conformal mapping to a plane.  The (u,v) points correspond to the
    // (x,y,z) mesh points.
    Vector2<Real>* m_akPlane;
    Vector2<Real> m_kPlaneMin, m_kPlaneMax;

    // Conformal mapping to a sphere.
    Vector3<Real>* m_akSphere;
    Real m_fRadius;
};

typedef ConformalMap<float> ConformalMapf;
typedef ConformalMap<double> ConformalMapd;

}

#endif
