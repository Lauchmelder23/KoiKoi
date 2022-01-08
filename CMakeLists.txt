# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("KoiKoi")


# Include sub-projects.
add_subdirectory ("vendor/spdlog")
add_subdirectory ("vendor/glfw")
add_subdirectory ("src")
