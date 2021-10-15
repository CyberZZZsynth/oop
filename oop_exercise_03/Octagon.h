//
// Created by Кирилл on 15.10.2021.
//

#ifndef OOP_EXERCISE_03_OCTAGON_H
#define OOP_EXERCISE_03_OCTAGON_H

#include "Point.h"
#include "Figure.h"

class Octagon {
private:
    Point A, B, C, D, E, F, G, H;
public:
    Octagon(Point a, Point b, Point c, Point d);
    Octagon(std::istream &in);
    size_t get_Vertex();
    double get_Area();
    Octagon();
    void Print(std::ostream &out);
    Point get_center();
    Octagon(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h);
    friend std::istream& operator>> (std::istream &in, Octagon &S);
};


#endif //OOP_EXERCISE_03_OCTAGON_H
