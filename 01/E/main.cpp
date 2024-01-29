#include <cassert>
#include <iostream>

class CharAnalyzer {
public:
    CharAnalyzer(const char* inputString) {
        assert(str != nullptr);
        str = inputString;
    }
    bool isPalindrome() {
        int sz = size();
        if (sz == 0)
            return true;
        int left = 0, right = sz - 1;
        while (left < right) {
            if (str[left] != str[right])
                return false;
            left++; right--;
        }
        return true;
    }
    int countChar(char c) {
        int ret = 0;
        for (auto p = str; *p != 0; p++) {
            if (*p == c)
                ret++;
        }
        return ret;
    }
private:
    const char* str;
    int size() {
        // We could write a cache here if we expected string to be very large
        int ret = 0;
        for (auto p = str; *p != 0; p++)
            ret++;
        return ret;
    }
};

int main() {
    const char* sampleStr = "level";
    CharAnalyzer analyzer(sampleStr);

    std::cout << analyzer.countChar('e') << '\n'; // Outputs 2
    std::cout << std::boolalpha << analyzer.isPalindrome() << '\n'; // Outputs true
}
