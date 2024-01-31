#include <iostream>

using namespace std;

namespace MemoryInspector {
    void displayMemoryAddress(int& variable) {
        cout << "The address is " << &variable << endl;
    }
    void displayMemoryAddress(int* pointer) {
        cout << "The address is " << pointer << endl;
    }
    void modifyValue(int& variable, int newValue) {
        variable = newValue;
    }
    void modifyValueThroughPointer(int* variablePtr, int newValue) {
        *variablePtr = newValue;
    }
}

int main() {
    int x = 10;
    int y = 20;
    int* ptrX = &x;

    MemoryInspector::displayMemoryAddress(x); 
    MemoryInspector::displayMemoryAddress(ptrX);
    
    cout << "x before modifyValue(x, 15) is " << x << endl;
    MemoryInspector::modifyValue(x, 15); 
    cout << "x after modifyValue(x, 15) is " << x << endl;

    cout << "y before modifyValueThroughPointer(&y, 25) is " << y << endl;
    MemoryInspector::modifyValueThroughPointer(&y, 25); 
    cout << "y after modifyValueThroughPointer(&y, 25) is " << y << endl;
    
    // Demonstration of Assignment vs Initialization
    int &r {x}; // initialized r to x (10)
    cout << "The address of r before r = y is " << &r << endl;
    r = y; // now x is also 10 -- note that the address of r didn't change
    cout << "The address of r after r = y is " << &r << endl;

    int* p {&x}; // now p points to x's address
    cout << "The address of p before p = &y is " << p << endl;
    p = &y; // now p points to y's address (which is different from x)
    cout << "The address of p after p = &y is " << p << endl;
}

