// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WML) source code is supplied under the terms of
// the license agreement http://www.magic-software.com/License/WildMagic.pdf
// and may not be copied or disclosed except in accordance with the terms of
// that agreement.

#ifndef WMLODESOLVER_H
#define WMLODESOLVER_H

#include "WmlSystem.h"

namespace Wml
{

template <class Real>
class WML_ITEM OdeSolver
{
public:
    // abstract base class
    virtual ~OdeSolver ();

    // The system is dx/dt = F(t,x).  The dimension of x is passed to the
    // constructor of OdeSolver.
    typedef void (*Function)(
        Real,         // t
        const Real*,  // x
        void*,        // user-specified data
        Real*);       // F(t,x)

    virtual void Update (Real fTIn, Real* afXIn, Real& rfTOut,
        Real* afXOut) = 0;

    virtual void SetStepSize (Real fStep) = 0;
    Real GetStepSize () const;

    void SetData (void* pvData);
    void* GetData () const;

protected:
    OdeSolver (int iDim, Real fStep, Function oFunction, void* pvData = NULL);

    int m_iDim;
    Real m_fStep;
    Function m_oFunction;
    void* m_pvData;
    Real* m_afFValue;
};

typedef OdeSolver<float> OdeSolverf;
typedef OdeSolver<double> OdeSolverd;

}

#endif
