//
// Created by Кирилл on 15.10.2021.
//

#ifndef OOP_EXERCISE_03_TRIANGLE_H
#define OOP_EXERCISE_03_TRIANGLE_H

#include "Point.h"
#include "Figure.h"

class Triangle: Figure {
private:
    Point A, B, C;
public:
    Triangle(std::istream &in);
    size_t get_Vertex();
    double get_Area();
    Triangle();
    void Print(std::ostream &out);
    Triangle(Point a, Point b, Point c);
    Point get_center();
    friend std::istream& operator>> (std::istream &in, Triangle &S);
};


#endif //OOP_EXERCISE_03_TRIANGLE_H
