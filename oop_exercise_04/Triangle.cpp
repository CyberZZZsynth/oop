//
// Created by Кирилл on 15.10.2021.
//

#include "Figure.h"
#include "Triangle.h"
#include "Point.h"
#include "cmath"


double Triangle::get_Area() {
    double Ox1 = B.get_X() - A.get_X();
    double Oy1 = B.get_Y() - A.get_Y();
    double Ox2 = C.get_X() - A.get_X();
    double Oy2 = C.get_Y() - A.get_Y();
    double Area = 0.5*(Ox1*Oy2-Oy1*Ox2);
    return std::abs(Area);
}

Point Triangle::get_center() {
    double x, y;
    x = (A.get_X()+B.get_X()+C.get_X())/3.0;
    y = (A.get_Y()+B.get_Y()+C.get_Y())/3.0;
    Point center(x,y);
    return center;
}

Triangle::Triangle() : A(Point()), B(Point()), C(Point()){
};

Triangle::Triangle(Point a,  Point b, Point c) : A(a), B(b), C(c) {
}

Triangle::Triangle(std::istream& in) {
    in >> A >> B >> C;
}

size_t Triangle::get_Vertex() {
    return (size_t)(3);
}

std::ostream &operator<<(std::ostream &out, Triangle &S){
    out << S.A << S.B << S.C;
}

std::istream &operator>>(std::istream &in, Triangle &S) {
    in >> S.A >> S.B >> S.C;
    return in;
}
