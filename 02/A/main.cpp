#include <iostream>

using namespace std;

struct Vector {
    double* elem;
    int sz;
};

void vectorInit(Vector& v, int size) {
    try {
        v.elem = new double[size];
    } catch (const bad_alloc& e) {
        size = 0;
        cerr << "Memory allocation for Vector failed: " << e.what() << endl;
    }
    v.sz = size;
}

double vectorSum(const Vector& v) {
    double ret = 0;
    for (int i = 0; i < v.sz; i++)
        ret += v.elem[i];
    return ret;
}

void vectorFree(Vector& v) {
    if (v.elem != nullptr)
        delete[] v.elem;
    v.sz = 0;
}

void printVector(const Vector& v) {
    cout << "[";
    for (int i = 0; i < v.sz - 1; i++)
        cout << v.elem[i] << ", ";
    if (v.sz > 0)
        cout << v.elem[v.sz -  1];
    cout << "] " << endl;
}

int main() {
    Vector v;
    int n;

    cout << "How many elements do you wish to input?" << endl;

    cin >> n;

    vectorInit(v, n);

    cout << "Please input the numbers: " << endl;
    
    for (int i = 0; i < v.sz; ++i) {
        cin >> v.elem[i];
    }

    printVector(v); 
    
    cout << "Sum of vector elements: " << vectorSum(v) << endl; // Output: 15.0
    vectorFree(v);
    printVector(v);
}

