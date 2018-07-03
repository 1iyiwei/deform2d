// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#include "WmlAxisAlignedBox2.h"
using namespace Wml;

//----------------------------------------------------------------------------
template <class Real>
AxisAlignedBox2<Real>::AxisAlignedBox2 ()
{
    m_afMin[0] = (Real)0.0;
    m_afMax[0] = (Real)0.0;
    m_afMin[1] = (Real)0.0;
    m_afMax[1] = (Real)0.0;
}
//----------------------------------------------------------------------------
template <class Real>
AxisAlignedBox2<Real>::AxisAlignedBox2 (Real fXMin, Real fXMax, Real fYMin,
    Real fYMax)
{
    m_afMin[0] = fXMin;
    m_afMax[0] = fXMax;
    m_afMin[1] = fYMin;
    m_afMax[1] = fYMax;
}
//----------------------------------------------------------------------------
template <class Real>
Real AxisAlignedBox2<Real>::GetXMin () const
{
    return m_afMin[0];
}
//----------------------------------------------------------------------------
template <class Real>
Real& AxisAlignedBox2<Real>::XMin ()
{
    return m_afMin[0];
}
//----------------------------------------------------------------------------
template <class Real>
Real AxisAlignedBox2<Real>::GetXMax () const
{
    return m_afMax[0];
}
//----------------------------------------------------------------------------
template <class Real>
Real& AxisAlignedBox2<Real>::XMax ()
{
    return m_afMax[0];
}
//----------------------------------------------------------------------------
template <class Real>
Real AxisAlignedBox2<Real>::GetYMin () const
{
    return m_afMin[1];
}
//----------------------------------------------------------------------------
template <class Real>
Real& AxisAlignedBox2<Real>::YMin ()
{
    return m_afMin[1];
}
//----------------------------------------------------------------------------
template <class Real>
Real AxisAlignedBox2<Real>::GetYMax () const
{
    return m_afMax[1];
}
//----------------------------------------------------------------------------
template <class Real>
Real& AxisAlignedBox2<Real>::YMax ()
{
    return m_afMax[1];
}
//----------------------------------------------------------------------------
template <class Real>
bool AxisAlignedBox2<Real>::HasXOverlap (const AxisAlignedBox2& rkBox) const
{
    return m_afMax[0] >= rkBox.m_afMin[0] && m_afMin[0] <= rkBox.m_afMax[0];
}
//----------------------------------------------------------------------------
template <class Real>
bool AxisAlignedBox2<Real>::HasYOverlap (const AxisAlignedBox2& rkBox) const
{
    return m_afMax[1] >= rkBox.m_afMin[1] && m_afMin[1] <= rkBox.m_afMax[1];
}
//----------------------------------------------------------------------------
template <class Real>
bool AxisAlignedBox2<Real>::TestIntersection (const AxisAlignedBox2& rkBox)
    const
{
    for (int i = 0; i < 2; i++)
    {
        if ( m_afMax[i] < rkBox.m_afMin[i] || m_afMin[i] > rkBox.m_afMax[i] )
            return false;
    }
    return true;
}
//----------------------------------------------------------------------------
template <class Real>
bool AxisAlignedBox2<Real>::FindIntersection (const AxisAlignedBox2& rkBox,
    AxisAlignedBox2& rkIntr) const
{
    int i;
    for (i = 0; i < 2; i++)
    {
        if ( m_afMax[i] < rkBox.m_afMin[i] || m_afMin[i] > rkBox.m_afMax[i] )
            return false;
    }

    for (i = 0; i < 2; i++)
    {
        if ( m_afMax[i] <= rkBox.m_afMax[i] )
            rkIntr.m_afMax[i] = m_afMax[i];
        else
            rkIntr.m_afMax[i] = rkBox.m_afMax[i];

        if ( m_afMin[i] <= rkBox.m_afMin[i] )
            rkIntr.m_afMin[i] = rkBox.m_afMin[i];
        else
            rkIntr.m_afMin[i] = m_afMin[i];
    }
    return true;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
namespace Wml
{
template WML_ITEM class AxisAlignedBox2<float>;
template WML_ITEM class AxisAlignedBox2<double>;
}
//----------------------------------------------------------------------------
