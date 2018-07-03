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
inline void CameraNode::SetCamera (Camera* pkCamera)
{
    m_spkCamera = pkCamera;
}
//----------------------------------------------------------------------------
inline Camera* CameraNode::GetCamera ()
{
    return m_spkCamera;
}
//----------------------------------------------------------------------------
inline const Camera* CameraNode::GetCamera () const
{
    return m_spkCamera;
}
//----------------------------------------------------------------------------
inline Matrix3f& CameraNode::CameraRotate ()
{
    return m_kCRotate;
}
//----------------------------------------------------------------------------
inline const Matrix3f& CameraNode::CameraRotate () const
{
    return m_kCRotate;
}
//----------------------------------------------------------------------------
inline Vector3f& CameraNode::CameraTranslate ()
{
    return m_kCTranslate;
}
//----------------------------------------------------------------------------
inline const Vector3f& CameraNode::CameraTranslate () const
{
    return m_kCTranslate;
}
//----------------------------------------------------------------------------
