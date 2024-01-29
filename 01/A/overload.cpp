#include <iostream>
#include <string>

using namespace std;

void displayInfo(const string& name) {
    cout << "Name: " << name << "\n";
}

void displayInfo(const string& name, int age) {
    cout << "Name: " << name << ", Age: " << age << "\n";
}

void displayInfo(const string& name, int age, double gpa) {
    cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << "\n";
}

int main() {
    displayInfo("Alice"); 
    displayInfo("Bob", 20); 
    displayInfo("Charlie", 21, 3.7);
    displayInfo("Diana", 0, 3.9);
}
