#include <cstring>
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class AssertionFailedException : public std::exception {
public:
    AssertionFailedException(const std::string& message) {
        this->message = new char[message.size()+ 1];
        std::strcpy(this->message, message.c_str());
    }

    ~AssertionFailedException() {
        delete[] message;
    }

    virtual const char* what() const noexcept override {
        return message;
    }

private:
    char* message;
};

namespace CustomAssert {
    void assertOrThrow(bool condition, const std::string& errorMessage) {
        if (!condition)
            throw AssertionFailedException(errorMessage);
    }

    template <typename T>
    void assertNotNull(T* ptr, const std::string& errorMessage) {
        if (ptr == nullptr)
            throw AssertionFailedException(errorMessage);
    }

    template <typename T>
    void assertEquals(T expected, T actual, const std::string& errorMessage) {
        if (!(expected == actual))
            throw AssertionFailedException(errorMessage);
    }
}

class SomeClass {
    // SomeClass definition
};

int main() {
    CustomAssert::assertOrThrow(true, "This should pass without an exception.");

    int x = 10;
    CustomAssert::assertNotNull(&x, "x should not be nullptr.");

    SomeClass* obj = new SomeClass();
    CustomAssert::assertNotNull(obj, "obj should not be nullptr.");

    CustomAssert::assertEquals(10, x, "x should be equal to 10.");
    
    try {
        CustomAssert::assertOrThrow(false, "This should throw an exception.");
    } catch (const AssertionFailedException& e) {
        std::cout << e.what() << std::endl;
    }

    // Ensure proper cleanup
    delete obj;
}

