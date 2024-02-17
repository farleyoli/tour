#include <cstring>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

class IndexOutOfBoundsException : public std::out_of_range {
public:
    IndexOutOfBoundsException(int _index, int _maxIndex, std::string errorMessage) : std::out_of_range(errorMessage) {
        index = _index;
        maxIndex = _maxIndex;
    }
    virtual const char* what() const noexcept override {
        std::ostringstream stream;
        stream << "The index " << index << " is not contained between the min index (inclusive) 0 and the max index (exclusive) " << maxIndex <<  std::endl;
        std::string retStr = stream.str();
        char* ret = new char[retStr.size() + 1];
        std::strcpy(ret, retStr.c_str());
        return ret;
    }
private:
    int index;
    int maxIndex;
};

class SafeIntArray {
public:
    void add(int n) {
        if (i < 100) {
            arr[i++] = n;
        }
    }

    int& operator[](int j) {
        if (j < 0 || j >= i)
            throw IndexOutOfBoundsException(j, i, "");
        return arr[j];
    }
private:
    int i = 0;
    int arr[100] = {0};
};


int main() {
    SafeIntArray safearray; // Initialize a SafeIntArray with a fixed capacity
    try {
        safearray.add(10);
        safearray.add(20);
        std::cout << "Accessing element at index 1: " << safearray[1] << std::endl;
        // This should throw an exception
        std::cout << "Accessing element at index 10: " << safearray[10] << std::endl;
    } catch (const IndexOutOfBoundsException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
