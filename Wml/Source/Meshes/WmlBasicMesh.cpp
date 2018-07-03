// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#include "WmlBasicMesh.h"
#include "WmlEdgeKey.h"
using namespace Wml;

#include <cassert>
#include <map>
using namespace std;

//----------------------------------------------------------------------------
BasicMesh::BasicMesh (int iVQuantity, void* akPoint, int iTQuantity,
    const int* aiConnect)
{
    m_iVQuantity = iVQuantity;
    m_iEQuantity = 0;
    m_iTQuantity = iTQuantity;
    m_akPoint = akPoint;
    m_aiConnect = aiConnect;

    // dynamically construct triangle mesh from input
    m_akVertex = new Vertex[m_iVQuantity];
    m_akEdge = new Edge[3*m_iTQuantity];
    m_akTriangle = new Triangle[m_iTQuantity];
    map<EdgeKey,int> kEMap;
    for (int iT = 0; iT < m_iTQuantity; iT++)
    {
        // update triangle
        Triangle& rkT = m_akTriangle[iT];
        rkT.V[0] = *aiConnect++;
        rkT.V[1] = *aiConnect++;
        rkT.V[2] = *aiConnect++;

        // add edges to mesh
        for (int i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
        {
            // update vertices
            m_akVertex[rkT.V[i1]].InsertTriangle(iT);

            EdgeKey kKey(rkT.V[i0],rkT.V[i1]);
            map<EdgeKey,int>::iterator kEIter = kEMap.find(kKey);
            if ( kEIter == kEMap.end() )
            {
                // first time edge encountered
                kEMap[kKey] = m_iEQuantity;

                // update edge
                Edge& rkE = m_akEdge[m_iEQuantity];
                rkE.V[0] = rkT.V[i0];
                rkE.V[1] = rkT.V[i1];
                rkE.T[0] = iT;

                // update vertices
                m_akVertex[rkE.V[0]].InsertEdge(rkE.V[1],m_iEQuantity);
                m_akVertex[rkE.V[1]].InsertEdge(rkE.V[0],m_iEQuantity);

                // update triangle
                rkT.E[i0] = m_iEQuantity;

                m_iEQuantity++;
            }
            else
            {
                // second time edge encountered
                int iE = kEIter->second;
                Edge& rkE = m_akEdge[iE];

                // update edge
                assert( rkE.T[1] == -1 );  // mesh must be manifold
                rkE.T[1] = iT;

                // update triangles
                int iAdj = rkE.T[0];
                Triangle& rkAdj = m_akTriangle[iAdj];
                for (int j = 0; j < 3; j++)
                {
                    if ( rkAdj.E[j] == iE )
                    {
                        rkAdj.T[j] = iT;
                        break;
                    }
                }
                rkT.E[i0] = iE;
                rkT.T[i0] = iAdj;
            }
        }
    }
}
//----------------------------------------------------------------------------
BasicMesh::~BasicMesh ()
{
    delete[] m_akVertex;
    delete[] m_akEdge;
    delete[] m_akTriangle;
}
//----------------------------------------------------------------------------
int BasicMesh::GetVQuantity () const
{
    return m_iVQuantity;
}
//----------------------------------------------------------------------------
int BasicMesh::GetEQuantity () const
{
    return m_iEQuantity;
}
//----------------------------------------------------------------------------
int BasicMesh::GetTQuantity () const
{
    return m_iTQuantity;
}
//----------------------------------------------------------------------------
void* BasicMesh::GetPoints () const
{
    return m_akPoint;
}
//----------------------------------------------------------------------------
const int* BasicMesh::GetConnectivity () const
{
    return m_aiConnect;
}
//----------------------------------------------------------------------------
const BasicMesh::Vertex* BasicMesh::GetVertices () const
{
    return m_akVertex;
}
//----------------------------------------------------------------------------
const BasicMesh::Edge* BasicMesh::GetEdges () const
{
    return m_akEdge;
}
//----------------------------------------------------------------------------
const BasicMesh::Triangle* BasicMesh::GetTriangles () const
{
    return m_akTriangle;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// BasicMesh::Vertex
//----------------------------------------------------------------------------
BasicMesh::Vertex::Vertex ()
{
    VQuantity = 0;
    V = NULL;
    E = NULL;
    TQuantity = 0;
    T = 0;
}
//----------------------------------------------------------------------------
BasicMesh::Vertex::~Vertex ()
{
    delete[] V;
    delete[] E;
    delete[] T;
}
//----------------------------------------------------------------------------
void BasicMesh::Vertex::InsertEdge (int iV, int iE)
{
    // check if vertex/edge in adjacency array (nothing to do if in array)
    for (int i = 0; i < VQuantity; i++)
    {
        if ( iV == V[i] )
            return;
    }

    if ( (VQuantity % MV_CHUNK) == 0 )
    {
        int* aiSave = V;
        V = new int[VQuantity+MV_CHUNK];
        memcpy(V,aiSave,VQuantity*sizeof(int));

        aiSave = E;
        E = new int[VQuantity+MV_CHUNK];
        memcpy(E,aiSave,VQuantity*sizeof(int));
    }

    V[VQuantity] = iV;
    E[VQuantity] = iE;
    VQuantity++;
}
//----------------------------------------------------------------------------
void BasicMesh::Vertex::InsertTriangle (int iT)
{
    // check if triangle in adjacency array (nothing to do if in array)
    for (int i = 0; i < TQuantity; i++)
    {
        if ( iT == T[i] )
            return;
    }

    if ( (TQuantity % MV_CHUNK) == 0 )
    {
        int* aiSave = T;
        T = new int[TQuantity+MV_CHUNK];
        memcpy(T,aiSave,TQuantity*sizeof(int));
    }

    T[TQuantity] = iT;
    TQuantity++;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// BasicMesh::Edge
//----------------------------------------------------------------------------
BasicMesh::Edge::Edge ()
{
    for (int i = 0; i < 2; i++)
    {
        V[i] = -1;
        T[i] = -1;
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// BasicMesh::Triangle
//----------------------------------------------------------------------------
BasicMesh::Triangle::Triangle ()
{
    for (int i = 0; i < 3; i++)
    {
        V[i] = -1;
        E[i] = -1;
        T[i] = -1;
    }
}
//----------------------------------------------------------------------------
