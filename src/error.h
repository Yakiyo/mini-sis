#include<exception>

using namespace std;

class DeserializeErr: public exception {
    private:
    string className;
    string message;
    public:
    DeserializeErr(const string& className, const string& message) : className(className), message(message) {}
    const char* what() const noexcept override {
        return ("Deserialize error in " + className + ": " + message).c_str();
    }
};

class FileErr: public exception {
    private:
    string filename;
    string message;
    public:
    FileErr(const string& filename, const string& message) : filename(filename), message(message) {}
    const char* what() const noexcept override {
        return ("File error for " + filename + ": " + message).c_str();
    }
};

class TransactionErr: public exception {
    private:
        string message;
    public:
        TransactionErr(const string& message) : message(message){}

        const char* what() const noexcept override{
            return ("Transaction error: " + message).c_str();
        }
};