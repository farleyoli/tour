#pragma once

#include <vector>
class VectorManager {
public:
    void fillVector(int value, int count);
    int getElementAtIndex(int index);
    void printVector();
private:
    std::vector<int> vec;
};
