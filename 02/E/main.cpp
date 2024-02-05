#include "VectorManager.h"
#include <iostream>
#include <ostream>

int main() {
    VectorManager vm;
    vm.fillVector(5, 10); // Fill vector with 10 instances of the number 5
    vm.printVector(); // Print the vector
    int value = vm.getElementAtIndex(3); // Get value at index 3
    std::cout << "Value at index 3: " << value << std::endl;
    return 0;
}

