// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#ifndef WMLCAMERANODE_H
#define WMLCAMERANODE_H

#include "WmlCamera.h"
#include "WmlNode.h"

namespace Wml
{

class WML_ITEM CameraNode : public Node
{
    WmlDeclareRTTI;
    WmlDeclareStream;

public:
    // construction
    CameraNode (Camera* pkCamera = NULL, int iQuantity = 1, int iGrowBy = 1);

    // member access
    void SetCamera (Camera* pkCamera);
    Camera* GetCamera ();
    const Camera* GetCamera () const;

    // TO DO.  Camera needs to be derived from Spatial.  For now, let the
    // CameraNode store the local transformation for Camera.  The Camera
    // world transformation obtained from the Node world transformation times
    // the Camera local transformation is what is used for the Camera location,
    // left, up, and direction vectors.  Column 0 of the Camera world rotation
    // matrix is used for the camera left vector.  Column 1 is used for the
    // camera up vector.  Column 2 is used for the camera direction vector.
    Matrix3f& CameraRotate ();
    const Matrix3f& CameraRotate () const;
    Vector3f& CameraTranslate ();
    const Vector3f& CameraTranslate () const;

    // support for searching by name
    virtual Object* GetObjectByName (const char* acName);
    virtual void GetAllObjectsByName (const char* acName,
        std::vector<Object*>& rkObjects);

protected:
    // geometric updates
    virtual void UpdateWorldData (float fAppTime);

    CameraPtr m_spkCamera;
    Matrix3f m_kCRotate;
    Vector3f m_kCTranslate;
};

WmlSmartPointer(CameraNode);
WmlRegisterStream(CameraNode);
#include "WmlCameraNode.inl"

}

#endif
