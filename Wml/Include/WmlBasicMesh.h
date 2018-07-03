// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#ifndef WMLBASICMESH_H
#define WMLBASICMESH_H

#include "WmlVector3.h"

namespace Wml
{

class BasicMesh
{
public:
    // The caller is responsible for deleting the input arrays.  The void*
    // input is typically vertices, but can be any data type you prefer.
    BasicMesh (int iVQuantity, void* akPoint, int iTQuantity,
        const int* aiConnect);

    virtual ~BasicMesh ();

    class Vertex
    {
    public:
        Vertex ();
        ~Vertex ();

        enum { MV_CHUNK = 8 };

        void InsertEdge (int iV, int iE);
        void InsertTriangle (int iT);

        int VQuantity;
        int* V;
        int* E;
        int TQuantity;
        int* T;
    };

    class Edge
    {
    public:
        Edge ();

        int V[2];
        int T[2];
    };

    class Triangle
    {
    public:
        Triangle ();

        int V[3];
        int E[3];
        int T[3];
    };

    // member access
    int GetVQuantity () const;
    int GetEQuantity () const;
    int GetTQuantity () const;
    void* GetPoints () const;
    const int* GetConnectivity () const;
    const Vertex* GetVertices () const;
    const Edge* GetEdges () const;
    const Triangle* GetTriangles () const;

protected:
    int m_iVQuantity, m_iEQuantity, m_iTQuantity;
    void* m_akPoint;
    const int* m_aiConnect;
    Vertex* m_akVertex;
    Edge* m_akEdge;
    Triangle* m_akTriangle;
};

}

#endif
