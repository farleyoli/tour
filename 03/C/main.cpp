#include <iostream>
#include <ostream>
#include <utility>
#include <vector>
namespace VectorTransformation {
    std::pair<int, int> calculateSumAndProduct(const std::vector<int>& vec) {
        int sum = 0;
        int product = 1;
        for (int e : vec) {
            sum += e;
            product *= e;
        }
        return {sum, product};
    }

    std::vector<int> copyIfGreaterThan(const std::vector<int>& vec, int threshold) {
        std::vector<int> ret;
        for (int e : vec)
            if (e > threshold)
                ret.push_back(e);

        return ret;
    }

    void incrementAllBy(std::vector<int>& vec, int increment) {
        for (auto& e : vec)
            e += increment;
    }

    void demonstrateStructuredBinding(const std::vector<int>& vec) {
        auto [sum, product] = calculateSumAndProduct(vec);
        std::cout << "The sum is " << sum << " and the product is " << product << std::endl;
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    VectorTransformation::demonstrateStructuredBinding(vec);

    auto filtered = VectorTransformation::copyIfGreaterThan(vec, 2);
    for (int val : filtered) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    VectorTransformation::incrementAllBy(vec, 5);
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

