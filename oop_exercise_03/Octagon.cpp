//
// Created by Кирилл on 15.10.2021.
//

#include "Octagon.h"
#include "Point.h"
#include "Figure.h"
#include "vector"
#include "cmath"

double Octagon::get_Area(){
     double Area = A.get_X()*B.get_Y()*C.get_X()*D.get_Y()*E.get_X()*F.get_Y()*G.get_X()*H.get_Y()-A.get_Y()*B.get_X()*C.get_Y()*D.get_X()*E.get_Y()*F.get_X()*G.get_Y()*H.get_X();
     return 0.5*std::abs(Area);
}

Point Octagon::get_center() {
    double x = (A.get_X()+B.get_X()+C.get_X()+D.get_X()+E.get_X()+F.get_X()+G.get_X()+H.get_X())/8.0;
    double y = (A.get_Y()+B.get_Y()+C.get_Y()+D.get_Y()+E.get_Y()+F.get_Y()+G.get_Y()+H.get_Y())/8.0;
    return Point(x,y);
}

Octagon::Octagon() : A(Point()), B(Point()), C(Point()), D(Point()){
};

Octagon::Octagon(Point a,  Point b, Point c, Point d, Point e, Point f, Point g, Point h) : A(a), B(b), C(c), D(d), E(e), F(f), G(g), H(h){
}

Octagon::Octagon(std::istream& in) {
    in >> A >> B >> C >> D >> E >> F >> G >> H;
}

size_t Octagon::get_Vertex() {
    return (size_t)(8);
}

void Octagon::Print(std::ostream &out) {
    out << A << " " << B << " " << C << " " << D << " " << E << " " << F << " " << H << "\n";
}

std::istream &operator>>(std::istream &in, Octagon &S) {
    in >> S.A >> S.B >> S.C >> S.D >> S.E >> S.F >> S.G >> S.H;
    return in;
}
