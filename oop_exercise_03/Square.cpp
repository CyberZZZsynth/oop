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
