// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

//----------------------------------------------------------------------------
inline int VEMesh::GetVertexQuantity () const
{
    return (int)m_kVMap.size();
}
//----------------------------------------------------------------------------
inline int VEMesh::GetEdgeQuantity () const
{
    return (int)m_kEMap.size();
}
//----------------------------------------------------------------------------
inline VEMesh* VEMesh::Create () const
{
    return new VEMesh;
}
//----------------------------------------------------------------------------
inline void VEMesh::OnVertexInsert (int,bool,void*&)
{
}
//----------------------------------------------------------------------------
inline void VEMesh::OnVertexRemove (int,bool,void*)
{
}
//----------------------------------------------------------------------------
inline void VEMesh::OnEdgeInsert (const Edge&,bool,void*&)
{
}
//----------------------------------------------------------------------------
inline void VEMesh::OnEdgeRemove (const Edge&,bool,void*)
{
}
//----------------------------------------------------------------------------
inline const VEMesh::VMap& VEMesh::GetVertexMap () const
{
    return m_kVMap;
}
//----------------------------------------------------------------------------
inline const VEMesh::EMap& VEMesh::GetEdgeMap () const
{
    return m_kEMap;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// VEMesh::Edge
//----------------------------------------------------------------------------
inline bool VEMesh::Edge::operator== (const Edge& rkE) const
{
    return m_aiV[0] == rkE.m_aiV[0] && m_aiV[1] == rkE.m_aiV[1];
}
//----------------------------------------------------------------------------
inline bool VEMesh::Edge::operator!= (const Edge& rkE) const
{
    return !operator==(rkE);
}
//----------------------------------------------------------------------------
inline VEMesh::Edge::Edge (int iV0, int iV1)
{
    if ( iV0 < iV1 )
    {
        // v0 is minimum
        m_aiV[0] = iV0;
        m_aiV[1] = iV1;
    }
    else
    {
        // vi is minimum
        m_aiV[0] = iV1;
        m_aiV[1] = iV0;
    }
}
//----------------------------------------------------------------------------
inline bool VEMesh::Edge::operator< (const Edge& rkE) const
{
    if ( m_aiV[1] < rkE.m_aiV[1] )
        return true;

    if ( m_aiV[1] == rkE.m_aiV[1] )
        return m_aiV[0] < rkE.m_aiV[0];

    return false;
}
//----------------------------------------------------------------------------
