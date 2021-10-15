//
// Created by Кирилл on 15.10.2021.
//

#ifndef OOP_EXERCISE_03_SQUARE_H
#define OOP_EXERCISE_03_SQUARE_H

#include "Point.h"
#include "Figure.h"

class Square {
private:
    Square(Point a, Point b, Point c, Point d);

    Point A, B, C, D;
public:
    Square(std::istream &in);
    size_t get_Vertex();
    double get_Area();
    Square();
    void Print(std::ostream &out);
    Square(Point a, Point b, Point c);
    friend std::istream& operator>> (std::istream &in, Square &S);
};



#endif //OOP_EXERCISE_03_SQUARE_H
