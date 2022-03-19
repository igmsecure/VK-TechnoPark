#!/usr/bin/env bash


set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}


print_header "RUN cppcheck"
cppcheck project/include project/src --enable=all --error-exitcode=1 -I project/include --suppress=missingIncludeSystem --check-config

print_header "RUN cpplint.py"
python2.7 ./ci/cpplint.py --extensions=c --root=.. --headers=h --linelength=120 --filter=-whitespace/tab,-runtime/int,-legal/copyright,-build/include_subdir,-build/include,-readability/casting project/include/* project/src/*

print_header "SUCCESS"
