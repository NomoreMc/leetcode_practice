#!bin/bash

PROJ_ROOT_PATH=`pwd`

run_test() {
    cd ${PROJ_ROOT_PATH}/output/bin
    ./run_test
}

run_test