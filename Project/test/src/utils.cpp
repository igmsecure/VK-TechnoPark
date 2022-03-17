#include <fstream>
#include <streambuf>
#include "utils.h"

const std::string OUT_STREAM_FILE = "custom_out.txt";
const std::string IN_STREAM_FILE = "custom_in.txt";

std::string file2string(const std::string &path) {
    std::ifstream in(path);
    std::string testOutput;
    in.seekg(0, std::ios::end);
    testOutput.reserve(in.tellg());
    in.seekg(0, std::ios::beg);
    testOutput.assign({std::istreambuf_iterator<char>(in)}, std::istreambuf_iterator<char>());
    return testOutput;
}

void IO_TEST::SetUp() {
    Test::SetUp();
    _originalOutDescriptor = switchStreamToFile(OUT_STREAM_FILE, stdout, "w");
    _originalInDescriptor = switchStreamToFile(IN_STREAM_FILE, stdin, "r");
}

void IO_TEST::TearDown() {
    Test::TearDown();
    switchBackStream(_originalOutDescriptor, stdout);
    switchBackStream(_originalInDescriptor, stdin);
}

int IO_TEST::switchStreamToFile(const std::string &file, FILE *stream, const std::string &mode) {
    fflush(stream);
    /* Get file descriptor, associated with original stdout */
    int currentStreamDescriptor = fileno(stream);
    if (currentStreamDescriptor == -1) {
        throw std::runtime_error("fileno");
    }
    /* Get copy of file descriptor, associated with original stream */
    int originalDescriptor = dup(currentStreamDescriptor);
    if (originalDescriptor == -1) {
        throw std::runtime_error("dup");
    }
    /* Close original stdout, open custom stream and associate stream with it: */
    FILE *filePtr = freopen(file.c_str(), mode.c_str(), stream);
    if (!filePtr) {
        perror("freopen");
        if (close(originalDescriptor)) {
            throw std::runtime_error("close + freopen");
        }
        throw std::runtime_error("freopen");
    }
    return originalDescriptor;
}

void IO_TEST::switchBackStream(int originalDescriptor, FILE *stream) {
    if (originalDescriptor < 0) {
        throw std::runtime_error("originalDescriptor");
    }
    fflush(stream);
    /* Get file descriptor, associated with current stream */
    int currentStreamDescriptor = fileno(stream);
    if (currentStreamDescriptor == -1) {
        throw std::runtime_error("fileno");
    }
    /* Close the current descriptor associated with stream and
     * associate it with the original descriptor */
    if (dup2(originalDescriptor, currentStreamDescriptor) == -1) {
        throw std::runtime_error("dup2");
    }
    if (close(originalDescriptor) == -1) {
        throw std::runtime_error("close");
    }
    clearerr(stream);
}

void IO_TEST::flush() {
    if (fflush(stdout) || fflush(stdin)) {
        throw std::runtime_error("fflush");
    }
}

void IO_TEST::setTestInput(const std::string &filePath) {
    switchBackStream(_originalInDescriptor, stdin);
    std::ifstream in(filePath);
    std::fstream out(IN_STREAM_FILE, std::ios::trunc | std::ios::out);
    if (!in || !out) {
        throw  std::runtime_error("can't open file");
    }
    char ch = 0;
    while (in.get(ch)) {
        out << ch;
    }
    std::cerr << std::endl;
    out.flush();
    out.close();
    _originalInDescriptor = switchStreamToFile(IN_STREAM_FILE, stdin, "r");
}

void IO_TEST::clearTestOutput() {
    flush();
    if (fseek(stdout, 0, SEEK_SET)) {
        throw std::runtime_error("fseek");
    }
    std::fstream out(OUT_STREAM_FILE, std::ios::trunc | std::ios::out);
    if (!out) {
        throw std::runtime_error("can't clear file");
    }
    out.close();
}

std::string IO_TEST::getTestOutput() {
    flush();
    return file2string(OUT_STREAM_FILE);
}

size_t TestConfig::testSeed;
std::string TestConfig::testDataPath;
