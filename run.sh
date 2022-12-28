#!bin/bash

PROJ_ROOT_PATH=`pwd`

run_test() {
    cd ${PROJ_ROOT_PATH}/build/bin
    ./run_test
}

run_test