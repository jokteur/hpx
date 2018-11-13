# Copyright (c) 2014 Thomas Heller
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

include(CMakeParseArguments)

# on startup, this is unset, but we'll set it to an empty string anyway
set_property(GLOBAL PROPERTY HPX_TARGET_COMPILE_DEFINITIONS "")
set_property(GLOBAL PROPERTY HPX_TARGET_COMPILE_OPTIONS "")

function(hpx_add_target_compile_option FLAG)
  set(options PUBLIC)
  set(one_value_args)
  set(multi_value_args CONFIGURATIONS)
  cmake_parse_arguments(HPX_ADD_TARGET_COMPILE_OPTION "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  if(HPX_ADD_TARGET_COMPILE_OPTION_PUBLIC)
    set(_dest HPX_TARGET_COMPILE_OPTIONS_PUBLIC)
  else()
    set(_dest HPX_TARGET_COMPILE_OPTIONS_PRIVATE)
  endif()
  set(_configurations "none")
  if(HPX_ADD_TARGET_COMPILE_OPTION_CONFIGURATIONS)
    set(_configurations "${HPX_ADD_TARGET_COMPILE_OPTION_CONFIGURATIONS}")
  endif()

  foreach(_config ${_configurations})
    set(_conf "${FLAG}")
    if(NOT _config STREQUAL "none")
      set(_conf "$<$<CONFIG:${_config}>:${FLAG}>")
    endif()
    set_property(GLOBAL APPEND PROPERTY ${_dest} "${_conf}")
  endforeach()

#  if(HPX_WITH_CUDA AND (NOT MSVC))
#      hpx_add_compile_flag(${FLAG})
#  endif()
endfunction()

function(hpx_remove_target_compile_option FLAG)
  set(options PUBLIC)
  set(one_value_args)
  set(multi_value_args CONFIGURATIONS)
  cmake_parse_arguments(HPX_ADD_TARGET_COMPILE_OPTION "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  set(_configurations "none")
  if(HPX_ADD_TARGET_COMPILE_OPTION_CONFIGURATIONS)
    set(_configurations "${HPX_ADD_TARGET_COMPILE_OPTION_CONFIGURATIONS}")
  endif()

  get_property(HPX_TARGET_COMPILE_OPTIONS_PUBLIC_VAR GLOBAL PROPERTY HPX_TARGET_COMPILE_OPTIONS_PUBLIC)
  get_property(HPX_TARGET_COMPILE_OPTIONS_PRIVATE_VAR GLOBAL PROPERTY HPX_TARGET_COMPILE_OPTIONS_PRIVATE)
  set_property(GLOBAL PROPERTY HPX_TARGET_COMPILE_OPTIONS_PUBLIC "")
  set_property(GLOBAL PROPERTY HPX_TARGET_COMPILE_OPTIONS_PRIVATE "")

  foreach(_config ${_configurations})
    set(_conf "${FLAG}")
    if(NOT _config STREQUAL "none")
      set(_conf "$<$<CONFIG:${_config}>:${FLAG}>")
    endif()
    foreach(_flag ${HPX_TARGET_COMPILE_OPTIONS_PUBLIC_VAR})
      if(NOT ${_flag} STREQUAL ${_conf})
        set_property(GLOBAL APPEND PROPERTY HPX_TARGET_COMPILE_OPTIONS_PUBLIC "${_flag}")
      endif()
    endforeach()
    foreach(_flag ${HPX_TARGET_COMPILE_OPTIONS_PRIVATE_VAR})
      if(NOT ${_flag} STREQUAL ${_conf})
        set_property(GLOBAL APPEND PROPERTY HPX_TARGET_COMPILE_OPTIONS_PRIVATE "${_flag}")
      endif()
    endforeach()
  endforeach()
endfunction()

function(hpx_add_target_compile_definition FLAG)
  set(options PUBLIC)
  set(one_value_args)
  set(multi_value_args CONFIGURATIONS)
  cmake_parse_arguments(HPX_ADD_TARGET_COMPILE_DEFINITION "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  if(HPX_ADD_TARGET_COMPILE_DEFINITION_PUBLIC)
    set(_dest HPX_TARGET_COMPILE_DEFINITIONS_PUBLIC)
  else()
    set(_dest HPX_TARGET_COMPILE_DEFINITIONS_PRIVATE)
  endif()
  set(_configurations "none")
  if(HPX_ADD_TARGET_COMPILE_DEFINITION_CONFIGURATIONS)
    set(_configurations "${HPX_ADD_TARGET_COMPILE_DEFINITION_CONFIGURATIONS}")
  endif()

  foreach(_config ${_configurations})
    set(_conf "${FLAG}")
    if(NOT _config STREQUAL "none")
      set(_conf "$<$<CONFIG:${_config}>:${FLAG}>")
    endif()
    set_property(GLOBAL APPEND PROPERTY ${_dest} "${_conf}")
  endforeach()

#  if(HPX_WITH_CUDA AND (NOT MSVC))
#    hpx_add_compile_flag(-D${FLAG})
#  endif()
endfunction()

function(hpx_add_compile_flag)
  set(one_value_args)
  set(multi_value_args CONFIGURATIONS LANGUAGES)
  cmake_parse_arguments(HPX_ADD_COMPILE_FLAG "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  set(_languages "CXX")
  if(HPX_ADD_COMPILE_FLAG_LANGUAGES)
    set(_languages ${HPX_ADD_COMPILE_FLAG_LANGUAGES})
  endif()

  set(_configurations "none")
  if(HPX_ADD_COMPILE_FLAG_CONFIGURATIONS)
    set(_configurations ${HPX_ADD_COMPILE_FLAG_CONFIGURATIONS})
  endif()

  # convert multiple flags into a list
  set(_flags ${HPX_ADD_COMPILE_FLAG_UNPARSED_ARGUMENTS})
  separate_arguments(_flags)

  foreach(_lang ${_languages})
    foreach(_config ${_configurations})
      set(_conf)
      if(NOT _config STREQUAL "none")
        string(TOUPPER "${_config}" _conf)
        set(_conf "${_conf}")
      endif()
      foreach(_flag ${_flags})
        set_property(GLOBAL APPEND PROPERTY HPX_CMAKE_FLAGS_${_lang}_${_conf} "${_flag}")
        get_property(TEMP_VAR GLOBAL PROPERTY HPX_CMAKE_FLAGS_${_lang}_${_conf})
      endforeach()
    endforeach()
  endforeach()
endfunction()


include(CheckCCompilerFlag)
include(CheckCXXCompilerFlag)

function(hpx_add_compile_flag_if_available FLAG)
  set(one_value_args NAME)
  set(multi_value_args CONFIGURATIONS LANGUAGES)
  cmake_parse_arguments(HPX_ADD_COMPILE_FLAG_IA "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  if(HPX_ADD_COMPILE_FLAG_IA_NAME)
    string(TOUPPER ${HPX_ADD_COMPILE_FLAG_IA_NAME} _name)
  else()
    string(TOUPPER ${FLAG} _name)
  endif()

  string(REGEX REPLACE "^-+" "" _name ${_name})
  string(REGEX REPLACE "[=\\-]" "_" _name ${_name})
  string(REGEX REPLACE "," "_" _name ${_name})
  string(REGEX REPLACE "\\+" "X" _name ${_name})

  set(_languages "CXX")
  if(HPX_ADD_COMPILE_FLAG_IA_LANGUAGES)
    set(_languages ${HPX_ADD_COMPILE_FLAG_IA_LANGUAGES})
  endif()

  foreach(_lang ${_languages})
    if(_lang STREQUAL "CXX")
      check_cxx_compiler_flag(${FLAG} HPX_WITH_${_lang}_FLAG_${_name})
    elseif(_lang STREQUAL "C")
      check_c_compiler_flag(${FLAG} HPX_WITH_${_lang}_FLAG_${_name})
    elseif(_lang STREQUAL "Fortran")
      ## Assuming the C compiler accepts the same flags as the fortran one ...
      check_c_compiler_flag(${FLAG} HPX_WITH_${_lang}_FLAG_${_name})
    else()
      hpx_error("Unsupported language ${_lang}.")
    endif()
    if(HPX_WITH_${_lang}_FLAG_${_name})
      hpx_add_compile_flag(${FLAG} CONFIGURATIONS ${HPX_ADD_COMPILE_FLAG_IA_CONFIGURATIONS} LANGUAGES ${_lang})
    else()
      hpx_info("\"${FLAG}\" not available for language ${_lang}.")
    endif()
  endforeach()

endfunction()
