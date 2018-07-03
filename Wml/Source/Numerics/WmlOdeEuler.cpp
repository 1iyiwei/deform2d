// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#include "WmlOdeEuler.h"
using namespace Wml;

//----------------------------------------------------------------------------
template <class Real>
OdeEuler<Real>::OdeEuler (int iDim, Real fStep,
    typename OdeSolver<Real>::Function oFunction, void* pvData)
    :
    OdeSolver<Real>(iDim,fStep,oFunction,pvData)
{
}
//----------------------------------------------------------------------------
template <class Real>
OdeEuler<Real>::~OdeEuler ()
{
}
//----------------------------------------------------------------------------
template <class Real>
void OdeEuler<Real>::Update (Real fTIn, Real* afXIn, Real& rfTOut,
    Real* afXOut)
{
    m_oFunction(fTIn,afXIn,m_pvData,m_afFValue);
    for (int i = 0; i < m_iDim; i++)
        afXOut[i] = afXIn[i] + m_fStep*m_afFValue[i];

    rfTOut = fTIn + m_fStep;
}
//----------------------------------------------------------------------------
template <class Real>
void OdeEuler<Real>::SetStepSize (Real fStep)
{
    m_fStep = fStep;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
namespace Wml
{
template class WML_ITEM OdeEuler<float>;
template class WML_ITEM OdeEuler<double>;
}
//----------------------------------------------------------------------------
