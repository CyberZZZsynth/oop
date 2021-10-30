//
// Created by Кирилл on 29.10.2021.
//

#ifndef OOP_EXERCISE_04_ARRAY_H
#define OOP_EXERCISE_04_ARRAY_H

#include <iostream>
#include "Triangle.h"
#include <ctime>


class Array {
private:
    Triangle *arr;
    int count;
    int size;
public:
    Array();
    Array(const Array& other);
    Array(int n);
    ~Array();
    Triangle& operator[](int index);
    friend std::ostream& operator<< (std::ostream &out, Array &Arr);
    int length();
    bool is_empty();
    void resize(int new_size);
    void insert(int index, Triangle &S);
    void push_back(Triangle &S);
};


#endif //OOP_EXERCISE_04_ARRAY_H
