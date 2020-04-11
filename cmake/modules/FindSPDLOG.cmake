# Try to find SPDLOG library
# Once done this will define
#  SPDLOG_FOUND - if system found SPDLOG library
#  SPDLOG_INCLUDE_DIRS - The SPDLOG include directories
#  SPDLOG_DEFINITIONS - Compiler switches required for using SPDLOG


if (SPDLOG_FOUND)
    return()
endif ()

find_path(SPDLOG_INCLUDE_DIRS
        NAMES spdlog/spdlog.h
        PATH /usr/local/include
        DOC "The SPDLOG include directory")


include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(SPDLOG DEFAULT_MSG SPDLOG_INCLUDE_DIRS)

if (SPDLOG_FOUND)
    set(SPDLOG_INCLUDE_DIRS ${SPDLOG_INCLUDE_DIRS})
    set(SPDLOG_DEFINITIONS)
endif ()

# Tell cmake GUIs to ignore the "local" variables.
# mark_as_advanced(SPDLOG_INCLUDE_DIRS SPDLOG_LIBRARIES)