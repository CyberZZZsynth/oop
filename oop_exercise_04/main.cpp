#include <iostream>
#include "Point.h"
#include "Figure.h"
#include "Triangle.h"
#include "Array.h"

int main() {
    Array A;
    for (int i = 0; i < 3; ++i) {
        Triangle tmp;
        std::cin >> tmp;
        A.push_back(tmp);
    }
    Triangle S;
    std::cin >> S;
    A.insert(1, S);
    std::cout << A;
}
