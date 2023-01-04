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

    lcov --rc lcov_branch_coverage=1 --capture --initial --directory ./ --output-file base.info
    lcov --rc lcov_branch_coverage=1 --capture --base-directory ./ --directory ./ --output-file test.info --test-name full

    if [ -s test.info ]; then
        lcov  -a base.info -a test.info -o main_test.info
        genhtml main_test.info --branch-coverage --title "FULL Cov Test" >> gcov.txt
    else
        genhtml base.info --branch-coverage --title "FULL Cov Test" >> gcov.txt
    fi

    rm -f *.gcno
    rm -f *.gcda
}

gen_coverage