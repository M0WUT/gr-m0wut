INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_M0WUT m0wut)

FIND_PATH(
    M0WUT_INCLUDE_DIRS
    NAMES m0wut/api.h
    HINTS $ENV{M0WUT_DIR}/include
        ${PC_M0WUT_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    M0WUT_LIBRARIES
    NAMES gnuradio-m0wut
    HINTS $ENV{M0WUT_DIR}/lib
        ${PC_M0WUT_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/m0wutTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(M0WUT DEFAULT_MSG M0WUT_LIBRARIES M0WUT_INCLUDE_DIRS)
MARK_AS_ADVANCED(M0WUT_LIBRARIES M0WUT_INCLUDE_DIRS)
