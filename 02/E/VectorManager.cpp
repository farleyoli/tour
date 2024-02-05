#include "VectorManager.h"
#include <iostream>

void VectorManager::fillVector(int value, int count) {
    while (count--)
        VectorManager::vec.push_back(value);
}

int VectorManager::getElementAtIndex(int index) {
    if (index < 0 || index >= VectorManager::vec.size())
        return -1;
    return VectorManager::vec[index];
}

void VectorManager::printVector() {
    std::cout << "{";
    for (int i = 0; i < VectorManager::vec.size() - 1; i++)
        std::cout << VectorManager::vec[i] << ", ";
    if (VectorManager::vec.size() > 0)
        std::cout << VectorManager::vec[VectorManager::vec.size() - 1];
    std::cout << "}" << std::endl;
}
