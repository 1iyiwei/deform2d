#ifndef __RMS_WML_EXT_TRIANGLE_UTIL_H__
#define __RMS_WML_EXT_VECTOR_UTIL_H__

#include <WmlVector2.h>
#include <WmlVector3.h>

namespace Wml
{
	template <class Real>
	void BarycentricCoords( const Vector3<Real> & vTriVtx1, 
										const Vector3<Real> & vTriVtx2,
										const Vector3<Real> & vTriVtx3,
										const Vector3<Real> & vVertex,
										Real & fBary1, Real & fBary2, Real & fBary3 );

	template <class Real>
	Real Area( const Vector3<Real> & vTriVtx1, 
						   const Vector3<Real> & vTriVtx2,
						   const Vector3<Real> & vTriVtx3 );

	template <class Real>
	void BarycentricCoords( const Vector2<Real> & vTriVtx1, 
										const Vector2<Real> & vTriVtx2,
										const Vector2<Real> & vTriVtx3,
										const Vector2<Real> & vVertex,
										Real & fBary1, Real & fBary2, Real & fBary3 );

	template <class Real>
	Real Area( const Vector2<Real> & vTriVtx1, 
						   const Vector2<Real> & vTriVtx2,
						   const Vector2<Real> & vTriVtx3 );

	template <int N, class Real>
	Real Angle( const Vector<N,Real> & vTriVtxAngle,
							const Vector<N,Real> & vTriV1,
							const Vector<N,Real> & vTriV2 );

	template <int N, class Real>
	void Scale( Vector<N,Real> & vTriV0,
							Vector<N,Real> & vTriV1,
							Vector<N,Real> & vTriV2,
							Real fScale );


	//! This metric is from Texture Mapping Progressive Meshes, Sander et al, Siggraph 2001
	template <class Real>
	void StretchMetric1( const Vector3<Real> & vTriVtx1, 
									 const Vector3<Real> & vTriVtx2,
									 const Vector3<Real> & vTriVtx3,
									 const Vector2<Real> & vVtxParam1,
									 const Vector2<Real> & vVtxParam2,
									 const Vector2<Real> & vVtxParam3,
									 Real & MaxSV, Real & MinSV, Real & L2Norm, Real & LInfNorm );

	template <int N, class Real> 
	bool PtInTri2D( const Vector<N,Real> & vTriVtx1,
								const Vector<N,Real> & vTriVtx2,
								const Vector<N,Real> & vTriVtx3,
								Real fTestX, Real fTestY );
	//template <class Real> 
	//bool PtInTri2D( const Vector3<Real> & vTriVtx1,
	//							const Vector3<Real> & vTriVtx2,
	//							const Vector3<Real> & vTriVtx3,
	//							Real fTestX, Real fTestY );

	//template <class Real>
	//bool FindExitEdge( const Vector3<Real> & vTriVtx1,
	//							   const Vector3<Real> & vTriVtx2,
	//							   const Vector3<Real> & vTriVtx3,
	//							   Real fTestX, Real fTestY 
									 


}  // end namespace Wml

#endif // __RMS_WML_EXT_TRIANGLE_UTIL_H__
