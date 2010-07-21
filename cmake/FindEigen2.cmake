# - Try to find Eigen2
# Once done, this will define
#
#  EIGEN2_FOUND - system has Eigen2
#  EIGEN2_INCLUDE_DIRS - the Eigen2 include directories

include(LibFindMacros)

find_path(Eigen2_INCLUDE_DIR
  NAMES Eigen
  PATH_SUFFIXES eigen2
)

find_library(Eigen2_LIBRARY
  NAMES Eigen2
)

# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(Eigen2_PROCESS_INCLUDES Eigen2_INCLUDE_DIR)
set(Eigen2_PROCESS_LIBS Eigen2_LIBRARY)
libfind_process(Eigen2)
