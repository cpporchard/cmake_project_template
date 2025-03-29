cmake_minimum_required(VERSION 3.10)
project(VectorPlusPlus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(unittest)

include(FetchContent) # important line.

# ========================
# 📦 Fetch Boost (header-only + required libs)
# ========================
FetchContent_Declare(
        boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.83.0
        GIT_SHALLOW TRUE
)

set(BOOST_INCLUDE_LIBRARIES algorithm asio beast)  # Only what we use
set(BOOST_ENABLE_CMAKE ON CACHE BOOL "Enable CMake for Boost" FORCE)
FetchContent_MakeAvailable(boost)


# ========================
# ✅ Fetch GoogleTest
# ========================
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)



include_directories(include)
