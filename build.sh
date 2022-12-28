#!bin/bash

PROJ_ROOT_PATH=`pwd`
PROJ_BUILD_PATH=${PROJ_ROOT_PATH}/build

build_test() {
    cd ${PROJ_ROOT_PATH}
    if [[! -d ${PROJ_BUILD_PATH}]]; then
        mkdir build
    else
        rm -rf build
        mkdir build
    fi
    cd build
    cmake ..
    make -j4
}

build_test