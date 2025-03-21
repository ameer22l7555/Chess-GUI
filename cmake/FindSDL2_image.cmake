# Distributed under the OSI-approved BSD 3-Clause License. See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

#.rst:
# FindSDL2_image
# -------------
#
# Locate SDL2_image library
#
# This module defines
#
# ::
#
# SDL2_IMAGE_LIBRARIES, the name of the library to link against
# SDL2_IMAGE_INCLUDE_DIRS, where to find the headers
# SDL2_IMAGE_FOUND, if false, do not try to link against
# SDL2_IMAGE_VERSION_STRING - human-readable string containing the version of SDL2_image
#
#
#
# For backward compatibility the following variables are also set:
#
# :::
#
# SDL2IMAGE_LIBRARY (same value as SDL2_IMAGE_LIBRARIES)
# SDL2IMAGE_INCLUDE_DIR (same value as SDL2_IMAGE_INCLUDE_DIRS)
# SDL2IMAGE_FOUND (same value as SDL2_IMAGE_FOUND)
#
#
#
# $SDLDIR is an environment variable that would correspond to the
# ./configure --prefix=$SDLDIR used in building SDL.
#
# Created by Eric Wing. This was influenced by the FindSDL.cmake
# module, but with modifications to recognize OS X frameworks and
# additional Unix paths (FreeBSD, etc).

# Define options for searching SDL2_image Library in a custom path

set(SDL2_IMAGE_PATH "" CACHE STRING "Custom SDL2_image Library path")

set(_SDL2_IMAGE_NO_DEFAULT_PATH OFF)
if(SDL2_IMAGE_PATH)
  set(_SDL2_IMAGE_NO_DEFAULT_PATH ON)
endif()

set(SDL2_IMAGE_NO_DEFAULT_PATH ${_SDL2_IMAGE_NO_DEFAULT_PATH}
    CACHE BOOL "Disable search SDL2_image Library in default path")
unset(_SDL2_IMAGE_NO_DEFAULT_PATH)

set(SDL2IMAGE_NO_DEFAULT_PATH ${SDL2_IMAGE_NO_DEFAULT_PATH})
unset(SDL2_IMAGE_NO_DEFAULT_PATH)

if(NOT SDL2_IMAGE_INCLUDE_DIR AND NOT SDL2IMAGE_INCLUDE_DIR)
  find_path(SDL2_IMAGE_INCLUDE_DIR SDL_image.h
    HINTS
      ENV SDL2IMAGEDIR
      ENV SDL2DIR
      ${SDL2_IMAGE_NO_DEFAULT_PATH}
    PATH_SUFFIXES SDL2
                  include/SDL2 include
    PATHS ${SDL2_IMAGE_PATH}
    DOC "Where the SDL2_image headers can be found"
  )
  set(SDL2IMAGE_INCLUDE_DIR ${SDL2_IMAGE_INCLUDE_DIR})
endif()
unset(SDL2_IMAGE_NO_DEFAULT_PATH)

if(NOT SDL2_IMAGE_LIBRARY AND NOT SDL2IMAGE_LIBRARY)
  # Construct search paths for includes and libraries from a SDL2_IMAGE_PATH variable
  find_library(SDL2_IMAGE_LIBRARY
    NAMES SDL2_image
    HINTS
      ENV SDL2IMAGEDIR
      ENV SDL2DIR
      ${SDL2_IMAGE_NO_DEFAULT_PATH}
    PATH_SUFFIXES lib ${VC_LIB_PATH_SUFFIX}
    PATHS ${SDL2_IMAGE_PATH}
    DOC "Where the SDL2_image Library can be found"
  )
  set(SDL2IMAGE_LIBRARY ${SDL2_IMAGE_LIBRARY})
endif()
unset(SDL2_IMAGE_NO_DEFAULT_PATH)

# Read SDL2 version
if(SDL2_IMAGE_INCLUDE_DIR AND EXISTS "${SDL2_IMAGE_INCLUDE_DIR}/SDL_image.h")
  file(STRINGS "${SDL2_IMAGE_INCLUDE_DIR}/SDL_image.h" SDL2_IMAGE_VERSION_MAJOR_LINE REGEX "^#define[ \t]+SDL_IMAGE_MAJOR_VERSION[ \t]+[0-9]+$")
  file(STRINGS "${SDL2_IMAGE_INCLUDE_DIR}/SDL_image.h" SDL2_IMAGE_VERSION_MINOR_LINE REGEX "^#define[ \t]+SDL_IMAGE_MINOR_VERSION[ \t]+[0-9]+$")
  file(STRINGS "${SDL2_IMAGE_INCLUDE_DIR}/SDL_image.h" SDL2_IMAGE_VERSION_PATCH_LINE REGEX "^#define[ \t]+SDL_IMAGE_PATCHLEVEL[ \t]+[0-9]+$")
  string(REGEX REPLACE "^#define[ \t]+SDL_IMAGE_MAJOR_VERSION[ \t]+([0-9]+)$" "\1" SDL2_IMAGE_VERSION_MAJOR "${SDL2_IMAGE_VERSION_MAJOR_LINE}")
  string(REGEX REPLACE "^#define[ \t]+SDL_IMAGE_MINOR_VERSION[ \t]+([0-9]+)$" "\1" SDL2_IMAGE_VERSION_MINOR "${SDL2_IMAGE_VERSION_MINOR_LINE}")
  string(REGEX REPLACE "^#define[ \t]+SDL_IMAGE_PATCHLEVEL[ \t]+([0-9]+)$" "\1" SDL2_IMAGE_VERSION_PATCH "${SDL2_IMAGE_VERSION_PATCH_LINE}")
  set(SDL2_IMAGE_VERSION_STRING ${SDL2_IMAGE_VERSION_MAJOR}.${SDL2_IMAGE_VERSION_MINOR}.${SDL2_IMAGE_VERSION_PATCH})
  unset(SDL2_IMAGE_VERSION_MAJOR_LINE)
  unset(SDL2_IMAGE_VERSION_MINOR_LINE)
  unset(SDL2_IMAGE_VERSION_PATCH_LINE)
  unset(SDL2_IMAGE_VERSION_MAJOR)
  unset(SDL2_IMAGE_VERSION_MINOR)
  unset(SDL2_IMAGE_VERSION_PATCH)
endif()

set(SDL2_IMAGE_LIBRARIES ${SDL2_IMAGE_LIBRARY})
set(SDL2_IMAGE_INCLUDE_DIRS ${SDL2_IMAGE_INCLUDE_DIR})
set(SDL2IMAGE_LIBRARIES ${SDL2_IMAGE_LIBRARIES})
set(SDL2IMAGE_INCLUDE_DIRS ${SDL2_IMAGE_INCLUDE_DIRS})

include(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_image
                                  REQUIRED_VARS SDL2_IMAGE_LIBRARIES SDL2_IMAGE_INCLUDE_DIRS
                                  VERSION_VAR SDL2_IMAGE_VERSION_STRING)

# for backward compatibility
set(SDL2IMAGE_FOUND ${SDL2_image_FOUND})

mark_as_advanced(SDL2_IMAGE_LIBRARY SDL2_IMAGE_INCLUDE_DIR)
