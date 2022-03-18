#ifndef ADVANCED_C_CPP_IZ1_UTILS_H
#define ADVANCED_C_CPP_IZ1_UTILS_H

#include <gtest/gtest.h>

extern const std::string OUT_STREAM_FILE;
extern const std::string IN_STREAM_FILE;

class IO_TEST : public testing::Test {
public:

    /**
     * Перенаправляет поток в файл.
     * Параметр file — имя файла, на который будет перенаправлен текущий поток.
     * Параметр stream - перенаправленный поток.
     * Возвращаетсяисходный дескриптор перенаправленного потока.
     */
    int switchStreamToFile(const std::string &file, FILE *stream, const std::string &mode);

    /**
     * Привязка потока к переданному дескриптору
     */
    void switchBackStream(int originalDescriptor, FILE *stream);
    void flush();
    std::string getTestOutput();
    /**
     * Настройка стандартного ввода для чтения filePath из переданного пути
     * Парметр filePath - путь к новому содержимому stdin
     */
    void setTestInput(const std::string &filePath);
    void clearTestOutput();
    void clearTestInput();

protected:
    void SetUp() override;
    void TearDown() override;

private:
    int _originalOutDescriptor = -1;
    int _originalInDescriptor = -1;
};

struct TestConfig {
    static size_t testSeed;
    static std::string testDataPath;
};

std::string file2string(const std::string &path);

#endif //ADVANCED_C_CPP_IZ1_UTILS_H
