set(EXE_NAME TP-TESTING-HW1)
set(TEST_SEED 42)
set(TEST_DATA_DIR ${CMAKE_SOURCE_DIR}/project/testing/data)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

add_executable(${EXE_NAME} src/main.cpp ${HW_SRC}
               src/io_tests.cpp src/utils.cpp src/managements_tests.cpp)
target_link_libraries(${EXE_NAME} ${GTEST_BOTH_LIBRARIES} pthread stdc++fs)

add_test(NAME IOTest COMMAND ${EXE_NAME} ${TEST_DATA_DIR} ${TEST_SEED} --gtest_filter=IO_TEST.*)
add_test(NAME ManageTest COMMAND ${EXE_NAME} ${TEST_DATA_DIR} ${TEST_SEED} --gtest_filter=MANAGEMENT_TEST.*)
