#include <fstream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

class FileOpenException : public std::runtime_error {
public:
    FileOpenException(const std::string& message) : std::runtime_error(message) {
        // this->what() will use message
    }
};
class WriteException : public std::runtime_error {
public:
    WriteException(const std::string& message) : std::runtime_error(message) {
        // this->what() will use message
    }
};

class FileLogger {
public:
    FileLogger(const std::string& fileName) : fileName(fileName), of(fileName, std::ios::out | std::ios::app) {
        if (!of.is_open())
            throw FileOpenException("could not open " + fileName);
    }
    void log(const std::string& message) {
        of << message << std::endl;
        if (of.good())
            throw WriteException("could not write to " + fileName);
    }
    ~FileLogger() {
        of.close();
    }
private:
    std::ofstream of;
    std::string fileName;
};

int main() {
    try {
        FileLogger logger("log.txt");
        logger.log("Application started");
        // Additional logging
    } catch (const FileOpenException& e) {
        std::cerr << "Failed to open log file: " << e.what() << '\n';
    } catch (const WriteException& e) {
        std::cerr << "Failed to write to log file: " << e.what() << '\n';
    }
}

