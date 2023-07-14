#!bin/bash

# 编译选项
paramList=$@
paramNum=$#
add_option=""
delete_option=""
zero=0

# 获取系统架构
sys_arch=`arch`

PROJ_ROOT_PATH=`pwd`
PROJ_BUILD_PATH=${PROJ_ROOT_PATH}/output

# 环境变量
# export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:$(realpath ${PROJ_ROOT_PATH}/output/lib)

# 删除所有的构建中间文件
clean() {
    cd ${PROJ_ROOT_PATH}
    rm -rf ${PROJ_ROOT_PATH}/tmp_build
    rm -rf ${PROJ_ROOT_PATH}/output
    rm -rf ${PROJ_ROOT_PATH}/report
    mkdir output
}

parse_option() {
    for i in $paramList
    do
        case "$i" in
            "gcov")
                add_option="${add_option} -fno-omit-frame-pointer -fprofile-arcs -ftest-coverage -fdump-rtl-expand"
                ;;
            "debug")
                add_option="${add_option} -O0 -g"
                ;;
            "asan")
                add_option="${add_option} -fsanitize=address -fsanitize-address-use-after-scope -O0 -g3 -fno-stack-protector -fno-omit-frame-pointer -fgnu89-inline"
                delete_option="${delete_option} -fstack-protector-strong -fomit-frame-pointer -O2 -D_FORTIFY_SOURCE=2"
                ;;
            "help")
                printf "%-50s %30s\n" "Build Test" "sh build.sh"
                printf "%-50s %30s\n" "Build Test with debug" "sh build.sh debug"
                printf "%-50s %30s\n" "Build Test with asan" "sh build.sh asan"
                printf "%-50s %30s\n" "Build Test with gcov" "sh build.sh gcov"
                exit 0
                ;;
            *)
                echo "${i} option is not regcognized, Please run <sh build.sh help> get supported option"
        esac
    done
}

# 解析选项
step() {
    if [ $paramNum -eq 0 ]; then
        echo "build all"
        clean
        build_test
        echo "build test done, testing now"
        run_test
        exit 0
    fi

    for i in $paramList
    do
        case "$i" in
            "-clean")
                clean
                ;;
            "-lib")
                add_option="${add_option} -O0 -g"
                ;;
            "-exe")
                build_test
                ;;
            "-inc")
                cd ${PROJ_ROOT_PATH}/tmp_build
                make -j4
                ;;
            "-run_test")
                run_test
                ;;
            "-all")
                clean
                build_test
                echo "build test done, start runing test"
                run_test
                ;;
            "-help")
                printf "%-50s %10s\n" "Clean All" "sh build.sh -clean"
                printf "%-50s %10s\n" "Build Dynamic Lib" "sh build.sh -lib"
                printf "%-50s %10s\n" "Build Exe" "sh build.sh -exe"
                printf "%-50s %10s\n" "Incremental Build" "sh build.sh -inc"
                printf "%-50s %10s\n" "Run Gtest Main" "sh build.sh -run_test"
                printf "%-50s %10s\n" "Build Test All" "sh build.sh -all or sh build.sh"
                exit 0
                ;;
            *)
                echo "${i} option is not regcognized, Please run <sh build.sh -help> get supported option"
        esac
    done
}

# 构建库
build_lib() {
    cd ${PROJ_ROOT_PATH}/output
    if [[ $get_arch = "x86_64" ]]; then
        python3 ../configure.py --lib_type static --add_option="${add_option}" --delete_option="${delete_option}"
        cmake ..
    fi
    make -j4
}

# 构建测试
build_test() {
    cd ${PROJ_ROOT_PATH}
    mkdir ${PROJ_ROOT_PATH}/tmp_build
    cd ${PROJ_ROOT_PATH}/tmp_build
    cmake ..
    make -j4
}

# 构建增量
build_inc() {
    cd ${PROJ_ROOT_PATH}/tmp_build
    make -j4
}

run_test() {
    cd ${PROJ_ROOT_PATH}/output/bin
    ./run_test
}

step