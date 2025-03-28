# TODO

1. ~~CMake Simple Project~~
2. CMake + Gtest (via Git Submodule)
3. CMake + Boost Http Server (via Git Submodule)
4. CMake + Boost + GTest (via Git Submodule) <--- Most common.
5. CMake + Gtest (via FetContent)

# Commands

## Add Library

```shell
git submodule add https://github.com/google/googletest.git third_party/googletest
git submodule update --init --recursive
```

## Removing Previous Sub Module

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

## Build

```shell
rm -rf build
mkdir build && cd build
cmake ..
make
```

## Run 
```shell
cd build
./unittest/VectorTest
```