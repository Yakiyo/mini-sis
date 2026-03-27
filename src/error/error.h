#pragma once
#include <string>
#include <stdexcept>


using namespace std;

class DsrlzExcept: public exception {
    private:
    // the class failed to be deserialized
    string cls;
    // the line that caused the error
    string content;

    public:
    DsrlzExcept(const string& className, const string& line) : cls(className), content(line) {}

    const char* what() const noexcept override {
        // convert `string` to `const char*` by using `c_str()`
        return ("Failed to deserialize " + cls + ": " + content).c_str();
    }
};

class FileExcept: public exception {
    private:
    string filename;

    public:
    FileExcept(const string& filename) : filename(filename) {}

    const char* what() const noexcept override {
        return ("Failed to open file: " + filename).c_str();
    }
};

class TransactionExcept: public exception {
    private:
    string message;

    public:
    TransactionExcept(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return ("Transaction error: " + message).c_str();
    }
};
