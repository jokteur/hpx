# Copyright (c) 2020 The STE||AR-Group
#
# SPDX-License-Identifier: BSL-1.0
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Default location is $HPX_ROOT/libs/checkpoint_base/include
set(checkpoint_base_headers hpx/checkpoint_base/checkpoint_data.hpp)

# Default location is $HPX_ROOT/libs/checkpoint_base/include_compatibility
set(checkpoint_base_compat_headers)

set(checkpoint_base_sources)

include(HPX_AddModule)
add_hpx_module(
  checkpoint_base
  COMPATIBILITY_HEADERS OFF
  DEPRECATION_WARNINGS
  GLOBAL_HEADER_GEN ON
  SOURCES ${checkpoint_base_sources}
  HEADERS ${checkpoint_base_headers}
  DEPENDENCIES hpx_config hpx_serialization
  CMAKE_SUBDIRS tests
)
