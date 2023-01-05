#!bin/bash

# 还在编写中
paramList=$@
paramNum=$#

testcast_list=()
option_list=()

# 解析测试工程选项以及输入的
parse_option() {
    for i in $paramList; do
        case "$i" in
            "gcov")
                option_list=("${option_list[@]}" "gcov")
                ;;
            "asan")
                option_list=("${option_list[@]}" "asan")
                ;;
            *)
                testcast_list[${#testcast_list[@]}]=$i
                ;;
        esac
    done

    echo ${option_list[@]}
    echo ${testcast_list[@]}
}

# 构建用于执行测试用例的框架和 exe
build_llt_dep() {
    echo build_llt_dep
}

gen_test_case() {
    echo gen_test_case
}

parse_option
build_llt_dep
gen_test_case