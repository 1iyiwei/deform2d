// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#ifndef WMLLIGHTNODE_H
#define WMLLIGHTNODE_H

#include "WmlLight.h"
#include "WmlNode.h"

namespace Wml
{

class WML_ITEM LightNode : public Node
{
    WmlDeclareRTTI;
    WmlDeclareStream;

public:
    // construction
    LightNode (Light* pkLight = NULL, int iQuantity = 1, int iGrowBy = 1);

    // member access
    void SetLight (Light* pkLight);
    Light* GetLight ();
    const Light* GetLight () const;

    // TO DO.  Light needs to be derived from Spatial.  For now, let the
    // LightNode store the local transformation for Light.  The Light
    // world transformation obtained from the Node world transformation times
    // the Light local transformation is what is used for the Light location,
    // left, up, and direction vectors.  Column 0 of the Light world rotation
    // matrix is used for the Light left vector.  Column 1 is used for the
    // Light up vector.  Column 2 is used for the Light direction vector.
    Matrix3f& LightRotate ();
    const Matrix3f& LightRotate () const;
    Vector3f& LightTranslate ();
    const Vector3f& LightTranslate () const;

    // support for searching by name
    virtual Object* GetObjectByName (const char* acName);
    virtual void GetAllObjectsByName (const char* acName,
        std::vector<Object*>& rkObjects);

protected:
    // geometric updates
    virtual void UpdateWorldData (float fAppTime);

    LightPtr m_spkLight;
    Matrix3f m_kLRotate;
    Vector3f m_kLTranslate;
};

WmlSmartPointer(LightNode);
WmlRegisterStream(LightNode);
#include "WmlLightNode.inl"

}

#endif
