//
// Created by Кирилл on 14.10.2021.
//

#ifndef OOP_EXERCISE_03_POINT_H
#define OOP_EXERCISE_03_POINT_H

#include <iostream>

class Point {
private:
    double x;
    double y;
public:
    Point();
    double get_X();
    double get_Y();
    double get_distance(Point& point2);
    friend std::ostream& operator<< (std::ostream &out, Point& point);
    friend std::istream& operator>> (std::istream &in, Point& point);
};


#endif //OOP_EXERCISE_03_POINT_H
