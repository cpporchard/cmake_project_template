<!-- TOC -->
* [Topics Covered](#topics-covered)
* [Commands](#commands)
  * [Add Library](#add-library-)
    * [Via Git Submodule](#via-git-submodule)
      * [Adding New Library - Google Test and Boost](#adding-new-library---google-test-and-boost)
      * [Removing Previous Sub Module - Google Test in this case (Optional)](#removing-previous-sub-module---google-test-in-this-case-optional)
      * [If the code already has the Sub Module -- Fetching the library](#if-the-code-already-has-the-sub-module----fetching-the-library)
    * [Via CMake FetchContent](#via-cmake-fetchcontent)
  * [Build](#build)
  * [Run](#run-)
    * [Run Unit Test](#run-unit-test)
    * [Run Executable](#run-executable)
* [FAQ](#faq)
    * [If CLion doesn't detect the Project as CMake.](#if-clion-doesnt-detect-the-project-as-cmake)
<!-- TOC -->

# Topics Covered

1. CMake Simple Project [Link](https://github.com/cpporchard/cmake_project_template/tree/feature/basic)
2. CMake + Gtest (via Git Submodule) [Link](https://github.com/cpporchard/cmake_project_template/tree/feature/gtest)
3. CMake + Boost Simple + GTest (via Git Submodule) [Link*](https://github.com/cpporchard/cmake_project_template/tree/feature/boost-simple) 
4. CMake + Boost Http Server Executable  (via Git Submodule) [Link*](https://github.com/cpporchard/cmake_project_template/tree/feature/boost-http-server)
5. CMake + Gtest (via FetchContent) [Link](https://github.com/cpporchard/cmake_project_template/tree/feature/cmake-FetchContent)

> 'Link*' means popular project template.

# Commands

## Add Library 

### Via Git Submodule

#### Adding New Library - Google Test and Boost

- Google Test
```shell
git submodule add https://github.com/google/googletest.git third_party/googletest
git submodule update --init --recursive
```

- Boost
> we noticed that we might need to download whole boost library to include just a subset of boost.
> We cd into boost and do `--init --recursive` to pull all the submodules inside boost.
```shell
git submodule add https://github.com/boostorg/boost.git third_party/boost
cd third_party/boost
git submodule update --init --recursive

```

#### Removing Previous Sub Module - Google Test in this case (Optional)

```shell
# commit or stash your changes b
git submodule deinit -f third_party/googletest
rm -rf .git/modules/third_party/googletest
rm -rf third_party/googletest

git config --file=.gitmodules --remove-section submodule.third_party/googletest
git config --file=.git/config --remove-section submodule.third_party/googletest
git rm --cached third_party/googletest

rm -rf .git/modules/*
rm -rf third_party
rm -rf .gitmodules
```

#### If the code already has the Sub Module -- Fetching the library

TODO

### Via CMake FetchContent

Only changes in CMakeList.txt files. Rest all are the same.

## Build

- Remove Previous Build (You won't make use of incremental build)
```shell
rm -rf build
```

- Build `third_party`, `src` and `test`.
```shell
mkdir build && cd build
cmake ..
make -j$(nproc --all)
```

## Run 

### Run Unit Test
```shell
cd build
./unittest/VectorTest
```

### Run Executable
```shell

./build/src/HttpServer
🚀 Starting HTTP server on http://localhost:8080 ...


curl "http://localhost:8080/split?text=hi,there,test&delim=,"
["hi", "there", "test"]
```

# FAQ

### If CLion doesn't detect the Project as CMake.
Remove the .idea folder and reopen the CMake Project.

