// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#include "WmlOdeMidpoint.h"
using namespace Wml;

//----------------------------------------------------------------------------
template <class Real>
OdeMidpoint<Real>::OdeMidpoint (int iDim, Real fStep,
    typename OdeSolver<Real>::Function oFunction, void* pvData)
    :
    OdeSolver<Real>(iDim,fStep,oFunction,pvData)
{
    m_fHalfStep = ((Real)0.5)*fStep;
    m_afXTemp = new Real[iDim];
}
//----------------------------------------------------------------------------
template <class Real>
OdeMidpoint<Real>::~OdeMidpoint ()
{
    delete[] m_afXTemp;
}
//----------------------------------------------------------------------------
template <class Real>
void OdeMidpoint<Real>::Update (Real fTIn, Real* afXIn, Real& rfTOut,
    Real* afXOut)
{
    int i;

    // first step
    m_oFunction(fTIn,afXIn,m_pvData,m_afFValue);
    for (i = 0; i < m_iDim; i++)
        m_afXTemp[i] = afXIn[i] + m_fHalfStep*m_afFValue[i];

    // second step
    Real fHalfT = fTIn + m_fHalfStep;
    m_oFunction(fHalfT,m_afXTemp,m_pvData,m_afFValue);
    for (i = 0; i < m_iDim; i++)
        afXOut[i] = afXIn[i] + m_fStep*m_afFValue[i];

    rfTOut = fTIn + m_fStep;
}
//----------------------------------------------------------------------------
template <class Real>
void OdeMidpoint<Real>::SetStepSize (Real fStep)
{
    m_fStep = fStep;
    m_fHalfStep = ((Real)0.5)*fStep;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
namespace Wml
{
template class WML_ITEM OdeMidpoint<float>;
template class WML_ITEM OdeMidpoint<double>;
}
//----------------------------------------------------------------------------
