#include <gtest/gtest.h>
#include "utils.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    if (argc < 3) {
        std::cout << "Please specify root path and test seed in arguments.." << std::endl;
        return -1;
    }
    TestConfig::testDataPath = argv[1];
    TestConfig::testSeed = std::stoul(argv[2]);
    return RUN_ALL_TESTS();
}