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

    # 生成零覆盖率基线文件
    lcov --rc lcov_branch_coverage=1 --capture --initial --directory ./ --output-file base.info
    # 生成运行用例后的源码覆盖率数据
    lcov --rc lcov_branch_coverage=1 --capture --base-directory ./ --directory ./ --output-file test.info --test-name full
    # 删除依赖的系统库、标准库、以及测试代码的覆盖率数据
    lcov --remove base.info --base-directory ./ '/usr/*' '*main.cpp' -o base.info
    lcov --remove test.info --base-directory ./ '/usr/*' '*main.cpp'  -o test.info

    if [ -s test.info ]; then
        lcov -a base.info -a test.info -o main_test.info
        genhtml main_test.info --branch-coverage --title "FULL Cov Test" >> gcov.txt
    else
        genhtml base.info --branch-coverage --title "Zero Cov, No Test Run" >> gcov.txt
    fi

    rm -f *.gcno
    rm -f *.gcda
}

gen_coverage