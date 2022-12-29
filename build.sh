#!bin/bash

# 编译选项
paramList=$@
paramNum=$#
add_option=""
delete_option=""

# 获取系统架构
sys_arch=`arch`

PROJ_ROOT_PATH=`pwd`
PROJ_BUILD_PATH=${PROJ_ROOT_PATH}/build

# 删除所有的构建中间文件
clean() {
    cd ${PROJ_ROOT_PATH}
    rm -rf ${PROJ_ROOT_PATH}/build
    mkdir build
}

# 解析选项
# parse_option() {
#     for i in $paramList
#     do
#         case "$i" in
#             "gcov")
#                 add_option="${add_option} -fno-omit-frame-pointer -fprofile-arcs -ftest-coverage -fdump-rtl-expand"
#                 ;;
#             "debug")
#                 add_option="${add_option} -O0 -g"
#                 ;;
#             "asan")
#                 add_option="${add_option} -fsanitize=address -fsanitize-address-use-after-scope -O0 -g3 -fno-stack-protector -fno-omit-frame-pointer -fgnu89-inline"
#                 delete_option="${delete_option} -fstack-protector-strong -fomit-frame-pointer -O2 -D_FORTIFY_SOURCE=2"
#                 ;;
#             "help")
#                 printf "%-50s %30s\n" "Build Test" "sh build.sh"
#                 printf "%-50s %30s\n" "Build Test with debug" "sh build.sh debug"
#                 printf "%-50s %30s\n" "Build Test with asan" "sh build.sh asan"
#                 printf "%-50s %30s\n" "Build Test with gcov" "sh build.sh gcov"
#                 ;;
# }

# 构建测试
build_test() {
    cd ${PROJ_ROOT_PATH}/build
    cmake ..
    make -j4
}

clean
build_test