//
// Created by Кирилл on 14.10.2021.
//

#ifndef OOP_EXERCISE_03_FIGURE_H
#define OOP_EXERCISE_03_FIGURE_H

#include "Point.h"

class Figure {
public:
    virtual size_t get_Vertex() = 0;
    virtual double get_Area()=0;
    virtual void Print(std::ostream &out) = 0;
    ~Figure() {
    };
};


#endif //OOP_EXERCISE_03_FIGURE_H
