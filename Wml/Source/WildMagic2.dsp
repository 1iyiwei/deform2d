# Microsoft Developer Studio Project File - Name="WildMagic2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=WildMagic2 - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WildMagic2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WildMagic2.mak" CFG="WildMagic2 - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WildMagic2 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "WildMagic2 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WildMagic2 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "Approximation" /I "Containment" /I "Curves" /I "Distance" /I "Geometry" /I "Graphics" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Math" /I "Meshes" /I "Miscellaneous" /I "Numerics" /I "Physics" /I "RationalArithmetic" /I "Surfaces" /I "System" /I "Tessellation" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\Library\Release\WildMagic2.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Approximation\*.h ..\Include	copy Containment\*.h ..\Include	copy Curves\*.h ..\Include	copy Distance\*.h ..\Include	copy Geometry\*.h ..\Include	copy Graphics\*.h ..\Include	copy Graphics\*.inl ..\Include	copy Graphics\*.mcr ..\Include	copy ImageAnalysis\*.h ..\Include	copy ImageAnalysis\*.inl ..\Include	copy Interpolation\*.h ..\Include	copy Intersection\*.h ..\Include	copy Math\*.h ..\Include	copy Math\*.inl ..\Include	copy Meshes\*.h ..\Include	copy Meshes\*.inl ..\Include	copy Miscellaneous\*.h ..\Include	copy Numerics\*.h ..\Include	copy Numerics\*.inl ..\Include	copy Physics\*.h ..\Include	copy Physics\*.inl ..\Include	copy RationalArithmetic\*.h ..\Include	copy RationalArithmetic\*.inl ..\Include	copy Surfaces\*.h ..\Include	copy System\*.h ..\Include	copy System\*.inl ..\Include	copy System\*.mcr ..\Include	copy Tessellation\*.h ..\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WildMagic2 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "Approximation" /I "Containment" /I "Curves" /I "Distance" /I "Geometry" /I "Graphics" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Math" /I "Meshes" /I "Miscellaneous" /I "Numerics" /I "Physics" /I "RationalArithmetic" /I "Surfaces" /I "System" /I "Tessellation" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\Library\Debug\WildMagic2.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Approximation\*.h ..\Include	copy Containment\*.h ..\Include	copy Curves\*.h ..\Include	copy Distance\*.h ..\Include	copy Geometry\*.h ..\Include	copy Graphics\*.h ..\Include	copy Graphics\*.inl ..\Include	copy Graphics\*.mcr ..\Include	copy ImageAnalysis\*.h ..\Include	copy ImageAnalysis\*.inl ..\Include	copy Interpolation\*.h ..\Include	copy Intersection\*.h ..\Include	copy Math\*.h ..\Include	copy Math\*.inl ..\Include	copy Meshes\*.h ..\Include	copy Meshes\*.inl ..\Include	copy Miscellaneous\*.h ..\Include	copy Numerics\*.h ..\Include	copy Numerics\*.inl ..\Include	copy Physics\*.h ..\Include	copy Physics\*.inl ..\Include	copy RationalArithmetic\*.h ..\Include	copy RationalArithmetic\*.inl ..\Include	copy Surfaces\*.h ..\Include	copy System\*.h ..\Include	copy System\*.inl ..\Include	copy System\*.mcr ..\Include	copy Tessellation\*.h ..\Include
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "WildMagic2 - Win32 Release"
# Name "WildMagic2 - Win32 Debug"
# Begin Group "Approximation"

# PROP Default_Filter ""
# Begin Group "Source Files (Approximation)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Approximation\WmlApprCircleFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprCylinderFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprEllipseByArcs2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprEllipseFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprEllipsoidFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprGaussPointsFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprGaussPointsFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprLineFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprLineFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprParaboloidFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprPlaneFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprPolyFit1.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprPolyFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprPolyFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprQuadraticFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprQuadraticFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprSphereFit3.cpp
# End Source File
# End Group
# Begin Group "Header Files (Approximation)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Approximation\WmlApprCircleFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprCylinderFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprEllipseByArcs2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprEllipseFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprEllipsoidFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprGaussPointsFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprGaussPointsFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprLineFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprLineFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprParaboloidFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprPlaneFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprPolyFit1.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprPolyFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprPolyFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprQuadraticFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprQuadraticFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\WmlApprSphereFit3.h
# End Source File
# End Group
# End Group
# Begin Group "Containment"

# PROP Default_Filter ""
# Begin Group "Source Files (Containment)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Containment\WmlContBox2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContBox3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContCapsule3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContCylinder3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContEllipse2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContEllipsoid3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContLozenge3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinBox2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinBox3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinCircle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinEllipseCR2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinEllipsoidCR3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinSphere3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContPointInPolygon2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContScribeCir2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContScribeCir3Sph3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContSeparatePoints2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContSeparatePoints3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContSphere3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlConvexHull2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlConvexHull3.cpp
# End Source File
# End Group
# Begin Group "Header Files (Containment)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Containment\WmlContBox2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContBox3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContCapsule3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContCylinder3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContEllipse2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContEllipsoid3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContLozenge3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinBox2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinBox3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinCircle2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinEllipseCR2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinEllipsoidCR3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContMinSphere3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContPointInPolygon2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContScribeCir2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContScribeCir3Sph3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContSeparatePoints2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContSeparatePoints3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlContSphere3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlConvexHull2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\WmlConvexHull3.h
# End Source File
# End Group
# End Group
# Begin Group "Curves"

# PROP Default_Filter ""
# Begin Group "Source Files (Curves)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Curves\WmlBezierCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlBezierCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlBSplineBasis.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlBSplineCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlBSplineCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlBSplineReduction.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlCubicPolynomialCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlCubicPolynomialCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlMultipleCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlMultipleCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlNaturalSpline2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlNaturalSpline3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlNURBSCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlNURBSCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlPolynomialCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlPolynomialCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlSingleCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlSingleCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlTCBSpline2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlTCBSpline3.cpp
# End Source File
# End Group
# Begin Group "Header Files (Curves)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Curves\WmlBezierCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlBezierCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlBSplineBasis.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlBSplineCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlBSplineCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlBSplineReduction.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlCubicPolynomialCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlCubicPolynomialCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlMultipleCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlMultipleCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlNaturalSpline2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlNaturalSpline3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlNURBSCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlNURBSCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlPolynomialCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlPolynomialCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlSingleCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlSingleCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlTCBSpline2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\WmlTCBSpline3.h
# End Source File
# End Group
# End Group
# Begin Group "Distance"

# PROP Default_Filter ""
# Begin Group "Source Files (Distance)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Distance\WmlDistCir3Cir3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistEllipsoidGeodesic.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistLin3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistLin3Cir3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistLin3Lin3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistLin3Rct3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistLin3Tri3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistRct3Rct3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistTri3Rct3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistTri3Tri3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec2Elp2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec2Lin2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec2Qdr2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Cir3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Eld3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Fru3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Lin3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Pln3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Qdr3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Rct3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Tri3.cpp
# End Source File
# End Group
# Begin Group "Header Files (Distance)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Distance\WmlDistCir3Cir3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistEllipsoidGeodesic.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistLin3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistLin3Cir3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistLin3Lin3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistLin3Rct3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistLin3Tri3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistRct3Rct3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistTri3Rct3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistTri3Tri3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec2Elp2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec2Lin2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec2Qdr2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Cir3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Eld3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Fru3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Lin3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Pln3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Qdr3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Rct3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\WmlDistVec3Tri3.h
# End Source File
# End Group
# End Group
# Begin Group "Geometry"

# PROP Default_Filter ""
# Begin Group "Source Files (Geometry)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Geometry\WmlArc2.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlAxisAlignedBox2.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlAxisAlignedBox3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlBox2.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlBox3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlCapsule3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlCircle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlCircle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlCone3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlConvexClipper.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlConvexPolygon2.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlConvexPolyhedron3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlCylinder3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlDisk2.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlDisk3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlEllipse2.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlEllipsoid3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlFrustum3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlHalfSpace3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlLine2.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlLine3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlLozenge3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlPlane3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlRay2.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlRay3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlRectangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlSegment2.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlSegment3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlSphere3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlTetrahedron3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlTorus3.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlTriangle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlTriangle3.cpp
# End Source File
# End Group
# Begin Group "Header Files (Geometry)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Geometry\WmlArc2.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlAxisAlignedBox2.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlAxisAlignedBox3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlBox2.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlBox3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlCapsule3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlCircle2.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlCircle3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlCone3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlConvexClipper.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlConvexPolygon2.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlConvexPolyhedron3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlCylinder3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlDisk2.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlDisk3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlEllipse2.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlEllipsoid3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlFrustum3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlHalfSpace3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlLine2.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlLine3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlLozenge3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlPlane3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlRay2.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlRay3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlRectangle3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlSegment2.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlSegment3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlSphere3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlTetrahedron3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlTorus3.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlTriangle2.h
# End Source File
# Begin Source File

SOURCE=.\Geometry\WmlTriangle3.h
# End Source File
# End Group
# End Group
# Begin Group "Graphics"

# PROP Default_Filter ""
# Begin Group "Source Files (Graphics)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Graphics\WmlAlphaState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlAmbientLight.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierCylinder.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierCylinder2.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierCylinder3.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierPatch.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierRectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierRectangle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierRectangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierTriangle.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierTriangle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierTriangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBillboardNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBound.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBoundingVolume.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBoundingVolumeTree.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBoxBV.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBspNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBspTree.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBumpMap.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCamera.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCameraNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCapsuleBV.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlClodMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCollapseRecord.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCollisionGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCollisionRecord.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlColorRGB.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlController.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlConvexRegion.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlConvexRegionManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCreateClodMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCullState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlDirectionalLight.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlDitherState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlDlodNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlFogState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlGeometry.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlGlossMap.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlIKController.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlIKGoal.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlIKJoint.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlImage.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlKeyframeController.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlLight.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlLightNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlLightState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlLozengeBV.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlMaterialState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlMorphController.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlObject.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlParticleController.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlParticles.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPixelShader.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPlanarReflection.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPlanarShadow.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPointController.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPointLight.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPolygonOffsetState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPolyline.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPolypoint.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPortal.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlProjectedTexture.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlRenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlRendererFont.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlRenderState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlScreenPolygon.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShader.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShaderConst.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShaderConstants.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShadeState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSkinController.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSpatial.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSphereBV.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSpotLight.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStandardMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStateConstant.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStream.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStringTree.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSwitchNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTerrainBlock.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTerrainPage.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTerrainVertex.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTexture.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTextureState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTriMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlVersion.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlVertexColorState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlVertexShader.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlWireframeState.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlZBufferState.cpp
# End Source File
# End Group
# Begin Group "Header Files (Graphics)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Graphics\WmlAlphaState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlAmbientLight.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierCylinder.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierCylinder2.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierCylinder3.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierMesh.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierPatch.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierRectangle.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierRectangle2.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierRectangle3.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierTriangle.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierTriangle2.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierTriangle3.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBillboardNode.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBound.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBoundingVolume.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBoundingVolumeTree.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBoxBV.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBspNode.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBspTree.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBumpMap.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCamera.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCameraNode.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCapsuleBV.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlClodMesh.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCollapseRecord.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCollisionGroup.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCollisionRecord.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlColorRGB.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlController.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlConvexRegion.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlConvexRegionManager.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCreateClodMesh.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCullState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlDirectionalLight.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlDitherState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlDlodNode.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlFogState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlGeometry.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlGlossMap.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlGraphics.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlIKController.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlIKGoal.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlIKJoint.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlImage.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlKeyframeController.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlLight.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlLightNode.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlLightState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlLozengeBV.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlMaterialState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlMorphController.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlNode.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlObject.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlParticleController.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlParticles.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPixelShader.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPlanarReflection.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPlanarShadow.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPointController.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPointLight.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPolygonOffsetState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPolyline.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPolypoint.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPortal.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlProjectedTexture.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlRenderer.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlRendererFont.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlRenderState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlRTTI.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlScreenPolygon.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShader.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShaderConst.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShaderConstants.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShadeState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSkinController.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSmartPointer.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSpatial.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSphereBV.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSpotLight.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStandardMesh.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStateConstant.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStream.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStringTree.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSwitchNode.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTerrainBlock.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTerrainPage.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTerrainVertex.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTexture.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTextureState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTriMesh.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlVersion.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlVertexColorState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlVertexShader.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlWireframeState.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlZBufferState.h
# End Source File
# End Group
# Begin Group "Inline Files (Graphics)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Graphics\WmlAlphaState.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlAmbientLight.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierCylinder.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBezierPatch.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBound.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBoundingVolumeTree.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBoxBV.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBspNode.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlBumpMap.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCamera.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCameraNode.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCapsuleBV.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlClodMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCollisionRecord.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlColorRGB.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlController.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlConvexRegion.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlConvexRegionManager.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlCullState.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlDirectionalLight.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlDitherState.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlDlodNode.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlFogState.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlGeometry.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlGlossMap.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlIKController.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlIKGoal.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlIKJoint.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlImage.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlKeyframeController.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlLight.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlLightNode.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlLozengeBV.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlMaterialState.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlMorphController.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlNode.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlObject.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlParticleController.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlParticles.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPixelShader.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPlanarReflection.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPlanarShadow.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPointController.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPointLight.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPolygonOffsetState.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPolyline.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPolypoint.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlPortal.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlProjectedTexture.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlRenderer.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlScreenPolygon.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShader.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShaderConst.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShaderConstants.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlShadeState.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSkinController.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSmartPointer.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSpatial.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSphereBV.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSpotLight.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStateConstant.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStream.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStringTree.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSwitchNode.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTerrainBlock.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTerrainPage.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTerrainVertex.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTexture.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlTriMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlVertexColorState.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlVertexShader.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlWireframeState.inl
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlZBufferState.inl
# End Source File
# End Group
# Begin Group "Macro Files (Graphics)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Graphics\WmlBoundingVolume.mcr
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlRenderState.mcr
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlRTTI.mcr
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlSmartPointer.mcr
# End Source File
# Begin Source File

SOURCE=.\Graphics\WmlStream.mcr
# End Source File
# End Group
# End Group
# Begin Group "ImageAnalysis"

# PROP Default_Filter ""
# Begin Group "Source Files (Images)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ImageAnalysis\WmlBinary2D.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlBinary3D.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlElement.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlExtractSurfaceCubes.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlExtractSurfaceTetra.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlFastBlur.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlImageConvert.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlImages.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlLattice.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlRasterDrawing.cpp
# End Source File
# End Group
# Begin Group "Header Files (Images)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ImageAnalysis\WmlBinary2D.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlBinary3D.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlElement.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlExtractSurfaceCubes.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlExtractSurfaceTetra.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlFastBlur.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlImageConvert.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlImages.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlLattice.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlRasterDrawing.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlTImage.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlTImage2D.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlTImage3D.h
# End Source File
# End Group
# Begin Group "Inline Files (Images)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ImageAnalysis\WmlElement.inl
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlExtractSurfaceCubes.inl
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlLattice.inl
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlTImage.inl
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlTImage2D.inl
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\WmlTImage3D.inl
# End Source File
# End Group
# End Group
# Begin Group "Interpolation"

# PROP Default_Filter ""
# Begin Group "Source Files (Interpolation)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Interpolation\WmlIntpAkima1.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpAkimaNonuniform1.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpAkimaUniform1.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpAkimaUniform2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpAkimaUniform3.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBicubic2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniform.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniform1.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniform2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniform3.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniform4.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniformN.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpLinearNonuniform2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpLinearNonuniform3.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpQdrNonuniform2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpSphere2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpThinPlateSpline2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpThinPlateSpline3.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpTricubic3.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpVectorField2.cpp
# End Source File
# End Group
# Begin Group "Header Files (Interpolation)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Interpolation\WmlIntpAkima1.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpAkimaNonuniform1.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpAkimaUniform1.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpAkimaUniform2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpAkimaUniform3.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBicubic2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniform.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniform1.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniform2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniform3.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniform4.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpBSplineUniformN.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpLinearNonuniform2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpLinearNonuniform3.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpQdrNonuniform2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpSphere2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpThinPlateSpline2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpThinPlateSpline3.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpTricubic3.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\WmlIntpVectorField2.h
# End Source File
# End Group
# End Group
# Begin Group "Intersection"

# PROP Default_Filter ""
# Begin Group "Source Files (Intersection)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Intersection\WmlIntrBox2Box2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrBox3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrBox3Fru3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrBox3Sph3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrCap3Cap3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrCir2Box2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrCir2Cir2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrElp2Elp2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrHsp3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrHsp3Lin3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrHsp3Sph3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrHsp3Tri3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrInterval.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin2Box2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin2Cir2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin2Lin2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Cap3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Con3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Cyl3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Eld3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Loz3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Sph3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Tor3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Tri3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLoz3Loz3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Cap3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Cyl3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Eld3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Loz3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Pln3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Sph3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrSph3Con3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrSph3Fru3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrSph3Sph3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTet3Tet3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTri2Tri2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTri3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTri3Con3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTri3Sph3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTri3Tri3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrUtility3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrUtilityBox3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrUtilityLin3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrUtilityTri3.cpp
# End Source File
# End Group
# Begin Group "Header Files (Intersection)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Intersection\WmlIntrBox2Box2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrBox3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrBox3Fru3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrBox3Sph3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrCap3Cap3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrCir2Box2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrCir2Cir2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrElp2Elp2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrHsp3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrHsp3Lin3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrHsp3Sph3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrHsp3Tri3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrInterval.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin2Box2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin2Cir2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin2Lin2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Cap3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Con3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Cyl3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Eld3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Lin3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Loz3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Sph3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Tor3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLin3Tri3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrLoz3Loz3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Cap3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Cyl3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Eld3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Loz3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Pln3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrPln3Sph3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrSph3Con3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrSph3Fru3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrSph3Sph3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTet3Tet3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTri2Tri2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTri3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTri3Con3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTri3Sph3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrTri3Tri3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrUtility3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrUtilityBox3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrUtilityLin3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\WmlIntrUtilityTri3.h
# End Source File
# End Group
# End Group
# Begin Group "Math"

# PROP Default_Filter ""
# Begin Group "Source Files (Math)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Math\WmlBandedMatrix.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlGMatrix.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlGVector.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlMath.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlMatrix2.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlMatrix3.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlMatrix4.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlPoint2.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlPoint3.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlPoint4.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlPolynomial1.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlQuaternion.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlVector2.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlVector3.cpp
# End Source File
# Begin Source File

SOURCE=.\Math\WmlVector4.cpp
# End Source File
# End Group
# Begin Group "Header Files (Math)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Math\WmlBandedMatrix.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlGMatrix.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlGVector.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlMath.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlMatrix.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlMatrix2.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlMatrix3.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlMatrix4.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlPoint.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlPoint2.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlPoint3.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlPoint4.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlPolynomial1.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlQuaternion.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlTuple.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlVector.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlVector2.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlVector3.h
# End Source File
# Begin Source File

SOURCE=.\Math\WmlVector4.h
# End Source File
# End Group
# Begin Group "Inline Files (Math)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Math\WmlMatrix.inl
# End Source File
# Begin Source File

SOURCE=.\Math\WmlPoint.inl
# End Source File
# Begin Source File

SOURCE=.\Math\WmlTuple.inl
# End Source File
# Begin Source File

SOURCE=.\Math\WmlVector.inl
# End Source File
# End Group
# End Group
# Begin Group "Meshes"

# PROP Default_Filter ""
# Begin Group "Source Files (Meshes)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Meshes\WmlBasicMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlConformalMap.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlETManifoldMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlETNonmanifoldMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMeshCurvature.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMeshSmoother.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTEdge.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTTriangle.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTVertex.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlVEMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlVETMesh.cpp
# End Source File
# End Group
# Begin Group "Header Files (Meshes)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Meshes\WmlBasicMesh.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlConformalMap.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlEdgeKey.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlETManifoldMesh.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlETNonmanifoldMesh.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMeshCurvature.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMeshSmoother.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTEdge.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTIEdge.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTITriangle.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTIVertex.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTMesh.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTTriangle.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTVertex.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlSmallSet.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlTriangleKey.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlUnorderedSet.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlVEMesh.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlVETMesh.h
# End Source File
# End Group
# Begin Group "Inline Files (Meshes)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Meshes\WmlEdgeKey.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlETManifoldMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlETNonmanifoldMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTEdge.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTIEdge.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTITriangle.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTIVertex.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTTriangle.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlMTVertex.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlSmallSet.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlTriangleKey.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlUnorderedSet.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlVEMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\WmlVETMesh.inl
# End Source File
# End Group
# End Group
# Begin Group "Miscellaneous"

# PROP Default_Filter ""
# Begin Group "Source Files (Miscellaneous)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Miscellaneous\WmlNormalCompression.cpp
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\WmlPerspProjEllipsoid.cpp
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\WmlQuadToQuadTransforms.cpp
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\WmlRandomHypersphere.cpp
# End Source File
# End Group
# Begin Group "Header Files (Miscellaneous)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Miscellaneous\WmlNormalCompression.h
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\WmlPerspProjEllipsoid.h
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\WmlQuadToQuadTransforms.h
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\WmlRandomHypersphere.h
# End Source File
# End Group
# End Group
# Begin Group "Numerics"

# PROP Default_Filter ""
# Begin Group "Source Files (Numerics)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Numerics\WmlBisect1.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlBisect2.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlBisect3.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlEigen.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlIntegrate1.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlLinearSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlMinimize1.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlMinimizeN.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlOdeEuler.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlOdeMidpoint.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlOdeRungeKutta4.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlOdeSolver.cpp
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlPolynomialRoots.cpp
# End Source File
# End Group
# Begin Group "Header Files (Numerics)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Numerics\WmlBisect1.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlBisect2.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlBisect3.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlEigen.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlIntegrate1.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlLinearSystem.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlMinimize1.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlMinimizeN.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlOdeEuler.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlOdeMidpoint.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlOdeRungeKutta4.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlOdeSolver.h
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlPolynomialRoots.h
# End Source File
# End Group
# Begin Group "Inline Files (Numerics)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Numerics\WmlPolynomialRootsDeg1.inl
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlPolynomialRootsDeg2.inl
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlPolynomialRootsDeg3.inl
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlPolynomialRootsDeg4.inl
# End Source File
# Begin Source File

SOURCE=.\Numerics\WmlPolynomialRootsDegN.inl
# End Source File
# End Group
# End Group
# Begin Group "Physics"

# PROP Default_Filter ""
# Begin Group "Source Files (Physics)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Physics\WmlBoxSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlBSplineVolume.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlIntersectingBoxes.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlIntersectingIntervals.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlIntersectingRectangles.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlLCPPolyDist.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlLCPSolver.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlMassSpringArbitrary.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlMassSpringCurve.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlMassSpringSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlMassSpringVolume.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlParticlePhysics.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlPolyhedralMassProperties.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlRectangleSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlRevolutionSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlRigidBody.cpp
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlTubeSurface.cpp
# End Source File
# End Group
# Begin Group "Header Files (Physics)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Physics\WmlBoxSurface.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlBSplineVolume.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlIntersectingBoxes.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlIntersectingIntervals.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlIntersectingRectangles.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlLCPPolyDist.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlLCPSolver.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlMassSpringArbitrary.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlMassSpringCurve.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlMassSpringSurface.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlMassSpringVolume.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlParticlePhysics.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlPolyhedralMassProperties.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlRectangleSurface.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlRevolutionSurface.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlRigidBody.h
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlTubeSurface.h
# End Source File
# End Group
# Begin Group "Inline Files (Physics)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Physics\WmlBoxSurface.inl
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlRectangleSurface.inl
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlRevolutionSurface.inl
# End Source File
# Begin Source File

SOURCE=.\Physics\WmlTubeSurface.inl
# End Source File
# End Group
# End Group
# Begin Group "RationalArithmetic"

# PROP Default_Filter ""
# Begin Group "Source Files (Rational)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RationalArithmetic\WmlRVector2.cpp
# End Source File
# Begin Source File

SOURCE=.\RationalArithmetic\WmlRVector3.cpp
# End Source File
# Begin Source File

SOURCE=.\RationalArithmetic\WmlTInteger.cpp
# End Source File
# Begin Source File

SOURCE=.\RationalArithmetic\WmlTRational.cpp
# End Source File
# End Group
# Begin Group "Header Files (Rational)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RationalArithmetic\WmlRVector2.h
# End Source File
# Begin Source File

SOURCE=.\RationalArithmetic\WmlRVector3.h
# End Source File
# Begin Source File

SOURCE=.\RationalArithmetic\WmlTInteger.h
# End Source File
# Begin Source File

SOURCE=.\RationalArithmetic\WmlTRational.h
# End Source File
# Begin Source File

SOURCE=.\RationalArithmetic\WmlTRVector.h
# End Source File
# End Group
# Begin Group "Inline Files (Rational)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RationalArithmetic\WmlRVector2.inl
# End Source File
# Begin Source File

SOURCE=.\RationalArithmetic\WmlRVector3.inl
# End Source File
# Begin Source File

SOURCE=.\RationalArithmetic\WmlTInteger.inl
# End Source File
# Begin Source File

SOURCE=.\RationalArithmetic\WmlTRational.inl
# End Source File
# Begin Source File

SOURCE=.\RationalArithmetic\WmlTRVector.inl
# End Source File
# End Group
# End Group
# Begin Group "Surfaces"

# PROP Default_Filter ""
# Begin Group "Source Files (Surfaces)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Surfaces\WmlBSplineRectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\WmlImplicitSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\WmlNURBSRectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\WmlParametricSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\WmlQuadricSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\WmlSurface.cpp
# End Source File
# End Group
# Begin Group "Header Files (Surfaces)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Surfaces\WmlBSplineRectangle.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\WmlImplicitSurface.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\WmlNURBSRectangle.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\WmlParametricSurface.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\WmlQuadricSurface.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\WmlSurface.h
# End Source File
# End Group
# End Group
# Begin Group "System"

# PROP Default_Filter ""
# Begin Group "Source Files (System)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\System\WmlCommand.cpp
# End Source File
# Begin Source File

SOURCE=.\System\WmlSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\System\WmlWinSystem.cpp
# End Source File
# End Group
# Begin Group "Header Files (System)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\System\WmlCommand.h
# End Source File
# Begin Source File

SOURCE=.\System\WmlSystem.h
# End Source File
# Begin Source File

SOURCE=.\System\WmlWinSystem.h
# End Source File
# End Group
# Begin Group "Inline Files (System)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\System\WmlSystem.inl
# End Source File
# End Group
# Begin Group "Macro Files"

# PROP Default_Filter "mcr"
# Begin Source File

SOURCE=.\System\WmlSystem.mcr
# End Source File
# End Group
# End Group
# Begin Group "Tessellation"

# PROP Default_Filter ""
# Begin Group "Source Files (Tessellation)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Tessellation\WmlDelaunay2.cpp
# End Source File
# Begin Source File

SOURCE=.\Tessellation\WmlDelaunay2a.cpp
# End Source File
# Begin Source File

SOURCE=.\Tessellation\WmlDelaunay3.cpp
# End Source File
# End Group
# Begin Group "Header Files (Tessellation)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Tessellation\WmlDelaunay2.h
# End Source File
# Begin Source File

SOURCE=.\Tessellation\WmlDelaunay2a.h
# End Source File
# Begin Source File

SOURCE=.\Tessellation\WmlDelaunay3.h
# End Source File
# End Group
# End Group
# End Target
# End Project

