#include <gtest/gtest.h>
#include <experimental/filesystem>
#include <fstream>
#include "utils.h"

extern "C" {
#include "ListOperationIO.h"
}
const std::string ERROR_COUNTRY_NAME = "0 0 0.00 error_country_name\n";
namespace fs = std::experimental::filesystem;

TEST_F(IO_TEST, RRINT_ERROR_COUNTRY) {
    auto node = std::make_shared<CountryNode>();
    node->data.square = 0;
    node->data.population = 0;
    node->data.PopulationDensity = 0;
    node->next = nullptr;
    node->data.CountryName = nullptr;
    PrintList(node.get());
    ASSERT_EQ(getTestOutput(), ERROR_COUNTRY_NAME);
}

TEST_F(IO_TEST, COMPLEX_TEST) {
    CountryNode *head = nullptr;
    for (auto &entity : fs::directory_iterator(TestConfig::testDataPath)) {
        setTestInput(entity / "in.txt");
        errno = 0;
        head = OrderedList();
        ASSERT_TRUE(!head == (errno == ENOMEM));
        PrintList(head);
        FreeList(head);
        ASSERT_EQ(getTestOutput(), file2string(entity / "out.txt"));
        clearTestOutput();
    }
}
