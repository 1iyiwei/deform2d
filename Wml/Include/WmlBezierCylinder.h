// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#ifndef WMLBEZIERCYLINDER_H
#define WMLBEZIERCYLINDER_H

#include "WmlBezierPatch.h"

namespace Wml
{

class WML_ITEM BezierCylinder : public BezierPatch
{
    WmlDeclareRTTI;
    WmlDeclareStream;

public:
    virtual PatchType GetType () const { return PT_CYLINDER; }

    // The 'level' parameter in the tessellation controls the number of
    // subdivisions of the boundary curves.  The 'cylinder level' parameter
    // controls the number of subdivisions of the cylinder edges (default
    // value is 0).
    int& CylinderLevel ();

    // number of vertices/triangles generated by tessellation at given level
    virtual int GetVerticesPerPatch (int iLevel) const;
    virtual int GetTrianglesPerPatch (int iLevel) const;

protected:
    // Construction.  BezierCylinder accepts responsibility for deleting
    // the input array.  The control point indices for the two boundary
    // curves are stored in the input array.
    BezierCylinder (int iDegree, int iIndexQuantity, int* aiIndex);

    BezierCylinder ();

    // tessellation
    void GenerateConnectivity (int iLevel, TriMesh* pkMesh,
        int& riTriangleStart);

    int m_iCylinderLevel;
};

WmlSmartPointer(BezierCylinder);
WmlRegisterStream(BezierCylinder);
#include "WmlBezierCylinder.inl"

}

#endif
