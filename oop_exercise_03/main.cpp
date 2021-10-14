#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

int main() {
    Point point1, point2;
    cin >> point1;
    cin >> point2;
    double a = point1.get_distance(point2);
    cout << a;
}
