# Things Covered

1. CMake Simple Project
2. CMake + Gtest (via Git Submodule)
3. CMake + Boost Http Server (via Git Submodule)
4. CMake + Boost + GTest (via Git Submodule) <--- Most common.
5. CMake + Gtest (via FetContent)

# Commands

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