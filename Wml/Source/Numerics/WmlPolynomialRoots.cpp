// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#include "WmlPolynomialRoots.h"
#include "WmlMath.h"
namespace Wml
{
#include "WmlPolynomialRootsDeg1.inl"
#include "WmlPolynomialRootsDeg2.inl"
#include "WmlPolynomialRootsDeg3.inl"
#include "WmlPolynomialRootsDeg4.inl"
#include "WmlPolynomialRootsDegN.inl"
}
using namespace Wml;

//----------------------------------------------------------------------------
template <class Real>
PolynomialRoots<Real>::PolynomialRoots (Real fEpsilon)
{
    assert( fEpsilon >= (Real)0.0 );
    m_fEpsilon = fEpsilon;
    m_iMaxIterations = 128;
    m_iCount = 0;
    m_iMaxRoot = 4;  // default support for degree <= 4
    m_afRoot = new Real[m_iMaxRoot];
}
//----------------------------------------------------------------------------
template <class Real>
PolynomialRoots<Real>::~PolynomialRoots ()
{
    delete[] m_afRoot;
}
//----------------------------------------------------------------------------
template <class Real>
int PolynomialRoots<Real>::GetCount () const
{
    return m_iCount;
}
//----------------------------------------------------------------------------
template <class Real>
const Real* PolynomialRoots<Real>::GetRoots () const
{
    return m_afRoot;
}
//----------------------------------------------------------------------------
template <class Real>
Real PolynomialRoots<Real>::GetRoot (int i) const
{
    assert( 0 <= i && i < m_iCount );
    if ( 0 <= i && i < m_iCount )
        return m_afRoot[i];

    return Math<Real>::MAX_REAL;
}
//----------------------------------------------------------------------------
template <class Real>
Real& PolynomialRoots<Real>::Epsilon ()
{
    return m_fEpsilon;
}
//----------------------------------------------------------------------------
template <class Real>
Real PolynomialRoots<Real>::Epsilon () const
{
    return m_fEpsilon;
}
//----------------------------------------------------------------------------
template <class Real>
int& PolynomialRoots<Real>::MaxIterations ()
{
    return m_iMaxIterations;
}
//----------------------------------------------------------------------------
template <class Real>
int PolynomialRoots<Real>::MaxIterations () const
{
    return m_iMaxIterations;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
namespace Wml
{
#ifdef WML_INSTANTIATE_BEFORE
template<> const float PolynomialRoots<float>::THIRD = 1.0f/3.0f;
template<> const float PolynomialRoots<float>::TWENTYSEVENTH = 1.0f/27.0f;
template<> const float PolynomialRoots<float>::SQRT3 =
    Math<float>::Sqrt(3.0f);
template<> const float PolynomialRoots<float>::INVLOG2 =
    1.0f/Math<float>::Log(2.0f);
template<> const float PolynomialRoots<float>::LOG10 =
    Math<float>::Log(10.0f);
template class WML_ITEM PolynomialRoots<float>;

template<> const double PolynomialRoots<double>::THIRD = 1.0/3.0;
template<> const double PolynomialRoots<double>::TWENTYSEVENTH = 1.0/27.0;
template<> const double PolynomialRoots<double>::SQRT3 =
    Math<double>::Sqrt(3.0);
template<> const double PolynomialRoots<double>::INVLOG2 =
    1.0/Math<double>::Log(2.0);
template<> const double PolynomialRoots<double>::LOG10 =
    Math<double>::Log(10.0);
template class WML_ITEM PolynomialRoots<double>;

#else
template class WML_ITEM PolynomialRoots<float>;
template<> const float PolynomialRoots<float>::THIRD = 1.0f/3.0f;
template<> const float PolynomialRoots<float>::TWENTYSEVENTH = 1.0f/27.0f;
template<> const float PolynomialRoots<float>::SQRT3 =
    Math<float>::Sqrt(3.0f);
template<> const float PolynomialRoots<float>::INVLOG2 =
    1.0f/Math<float>::Log(2.0f);
template<> const float PolynomialRoots<float>::LOG10 =
    Math<float>::Log(10.0f);

template class WML_ITEM PolynomialRoots<double>;
template<> const double PolynomialRoots<double>::THIRD = 1.0/3.0;
template<> const double PolynomialRoots<double>::TWENTYSEVENTH = 1.0/27.0;
template<> const double PolynomialRoots<double>::SQRT3 =
    Math<double>::Sqrt(3.0);
template<> const double PolynomialRoots<double>::INVLOG2 =
    1.0/Math<double>::Log(2.0);
template<> const double PolynomialRoots<double>::LOG10 =
    Math<double>::Log(10.0);
#endif
}
//----------------------------------------------------------------------------
