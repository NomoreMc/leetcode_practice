#!bin/bash

paramList=$@
paramNum=$#

PROJ_ROOT_PATH=`pwd`
PROJ_BUILD_PATH=${PROJ_ROOT_PATH}/output

gen_coverage(){
    cd ${PROJ_ROOT_PATH}
    rm -rf report
    mkdir report

    cd ${PROJ_BUILD_PATH}
    find ./ -name "*.gcno" -type f -exec cp {} ../report \;
    find ./ -name "*.gcda" -type f -exec cp {} ../report \;

    cd ${PROJ_ROOT_PATH}/report

    lcov --rc lcov_branch_coverage=1 --capture --initial --directory ./ --base-directory ./ --output-file base.info
    lcov --rc lcov_branch_coverage=1 --capture --directory ./ --test-name full --output-file test.info

    genhtml base.info test.info

    rm -rf *.gcno
    rm -rf *.gcda
}

gen_coverage