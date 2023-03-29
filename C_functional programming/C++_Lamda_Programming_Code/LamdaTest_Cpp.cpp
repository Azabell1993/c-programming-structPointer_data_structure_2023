#include <iostream>

int main() {
    auto add = [](int x, int y) -> int {
        return x + y;
    };

    int sum = add(2, 3);
    std::cout << "The sum is " << sum << std::endl;

    return 0;
}