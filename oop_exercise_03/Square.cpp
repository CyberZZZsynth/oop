//
// Created by Кирилл on 15.10.2021.
//

#include "Square.h"
#include "Figure.h"
#include "Point.h"
#include "cmath"

double Square::get_Area(){
    double base = A.get_distance(B);
    double height = A.get_distance(C);
    return base*height;
}

Square::Square() : A(Point()), B(Point()), C(Point()), D(Point()){
};

Square::Square(Point a,  Point b, Point c, Point d) : A(a), B(b), C(c), D(d){
}

Square::Square(std::istream& in) {
    in >> A >> B >> C >> D;
}

size_t Square::get_Vertex() {
    return (size_t)(4);
}

void Square::Print(std::ostream &out) {
    out << A << " " << B << " " << C << " " << D << "\n";
}

std::istream &operator>>(std::istream &in, Square &S) {
    in >> S.A >> S.B >> S.C >> S.D;
    return in;
}

Point Square::get_center() {
    double x = (A.get_X()+B.get_X()+C.get_X()+D.get_X())/4.0;
    double y = (A.get_Y()+B.get_Y()+C.get_Y()+D.get_Y())/4.0;
    return Point(x,y);
}
