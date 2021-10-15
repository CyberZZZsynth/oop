#include <iostream>
#include <vector>
#include "Point.h"
#include "Triangle.h"
#include "Figure.h"
#include "Square.h"

using namespace std;

int main() {
    Square S;
    cin >> S;
    double Area = S.get_Area();
    S.Print(cout);
}
