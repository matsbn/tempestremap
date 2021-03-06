# Don't require GNU-standard files (Changelog, README, etc.)
AUTOMAKE_OPTIONS = foreign subdir-objects

# Don't loose the autoconf include path
ACLOCAL_AMFLAGS = -I config

##############################################################################
lib_LTLIBRARIES = libTempestRemap.la

libTempestRemap_la_includedir = $(includedir)

# The list of source files, and any header files that do not need to be installed
libTempestRemap_la_SOURCES = \
	src/Announce.cpp \
	src/PolynomialInterp.cpp \
	src/GridElements.cpp \
	src/MeshUtilities.cpp \
	src/MeshUtilitiesFuzzy.cpp \
	src/MeshUtilitiesExact.cpp \
	src/GaussQuadrature.cpp \
	src/GaussLobattoQuadrature.cpp \
	src/LegendrePolynomial.cpp \
	src/FiniteElementTools.cpp \
	src/NetCDFUtilities.cpp \
	src/OfflineMap.cpp \
	src/TriangularQuadrature.cpp

# The list of header files which are to be installed 
libTempestRemap_la_include_HEADERS = \
	src/Announce.h \
	src/DataVector.h \
	src/FixedPoint.h \
	src/GridElements.h \
	src/LinearRemapSE0.h \
	src/MeshUtilities.h \
	src/OverlapMesh.h \
	src/TriangularQuadrature.h \
	src/CommandLine.h \
	src/Defines.h \
	src/GaussLobattoQuadrature.h \
	src/kdtree.h \
	src/MathHelper.h \
	src/NetCDFUtilities.h \
	src/PolynomialInterp.h \
	src/DataMatrix3D.h \
	src/Exception.h \
	src/GaussQuadrature.h \
	src/LegendrePolynomial.h \
	src/MeshUtilitiesExact.h \
	src/OfflineMap.h \
	src/SparseMatrix.h \
	src/DataMatrix.h \
	src/FiniteElementTools.h \
	src/GridElementsExact.h \
	src/LinearRemapFV.h \
	src/MeshUtilitiesFuzzy.h \
	src/OverlapFace.h \
	src/STLStringHelper.h \
	src/TempestConfig.h

# Load system-specific defaults
AM_CPPFLAGS = -I$(srcdir)/src -I$(builddir) -I$(builddir)/src ${NETCDF_CPPFLAGS}
AM_LDFLAGS = ${LDFLAGS} ${NETCDF_LDFLAGS}
LDADD = libTempestRemap.la ${NETCDF_LIBS} ${HDF5_LIBS} ${LAPACK_LIBS} ${BLAS_LIBS} ${LIBS}

GenerateRLLMesh_SOURCES = src/GenerateRLLMesh.cpp
GenerateCSMesh_SOURCES = src/GenerateCSMesh.cpp
GenerateICOMesh_SOURCES = src/GenerateICOMesh.cpp
GenerateLambertConfConicMesh_SOURCES = src/GenerateLambertConfConicMesh.cpp
GenerateOverlapMesh_SOURCES = src/GenerateOverlapMesh.cpp src/OverlapMesh.cpp src/kdtree.c
GenerateOverlapMesh_v1_SOURCES = src/GenerateOverlapMesh_v1.cpp src/OverlapMesh.cpp src/kdtree.c
GenerateGLLMetaData_SOURCES = src/GenerateGLLMetaData.cpp
MeshToTxt_SOURCES = src/MeshToTxt.cpp
GenerateTestData_SOURCES = src/GenerateTestData.cpp
CalculateDiffNorms_SOURCES = src/CalculateDiffNorms.cpp
ApplyOfflineMap_SOURCES = src/ApplyOfflineMap.cpp
GenerateOfflineMap_SOURCES = src/GenerateOfflineMap.cpp src/LinearRemapSE0.cpp src/LinearRemapFV.cpp src/OverlapMesh.cpp src/kdtree.c
#GenerateOfflineMap_v1_SOURCES = src/GenerateOfflineMap_v1.cpp src/LinearRemapSE0.cpp src/LinearRemapFV.cpp

bin_PROGRAMS = GenerateRLLMesh GenerateCSMesh GenerateICOMesh \
							 GenerateLambertConfConicMesh GenerateOverlapMesh \
							 GenerateOverlapMesh_v1 GenerateGLLMetaData MeshToTxt$(EXEEXT) \
							 GenerateTestData CalculateDiffNorms \
							 ApplyOfflineMap GenerateOfflineMap # GenerateOfflineMap_v1$(EXEEXT)

# Utility target: build but don't run tests
build-check:
	$(MAKE) 'TESTS_ENVIRONMENT=: ' check

doc_DATA = README.md doc/GreatCircleArcIntersections.mw doc/GreatCircleLatitudeIntersections.mw

nobase_dist_bin_SCRIPTS = \
	test/areaint.m \
	test/run.sh \
	test/run_fvtogll_cs.sh \
	test/run_fvtogll_ico_diffnorms.sh \
	test/run_glltofv_rll_diffnorms.sh \
	test/testdata_diffnorms_mono.sh \
	test/generate_testdata.sh \
	test/run_fvtofv_ico.sh \
	test/run_fvtogll_cs_diffnorms.sh \
	test/run_fvtogll_rll.sh \
	test/run_glltofv_rll_m.sh \
	test/optimtest.m \
	test/run_fvtofv_ico_diffnorms.sh \
	test/run_fvtogll_cs_m.sh \
	test/run_fvtogll_rll_diffnorms.sh \
	test/run_glltofv_rll_m_diffnorms.sh \
	test/plot_meshes.m \
	test/run_fvtofv_rll.sh \
	test/run_fvtogll_cs_m_diffnorms.sh \
	test/run_glltofv_ico.sh \
	test/run_glltogll_cs.sh \
	test/plot_nodes.m \
	test/run_fvtofv_rll_diffnorms.sh \
	test/run_fvtogll_ico.sh \
	test/run_glltofv_rll.sh \
	test/run_glltogll_cs_diffnorms.sh

EXTRA_DIST = $(doc_DATA)

CLEANFILES = configs.sed

