//
// Created by Кирилл on 29.10.2021.
//

#include "iostream"
#include "Array.h"
#include "Point.h"
#include "Figure.h"
#include "Triangle.h"

Array::Array(): size(0), count(0){

}

Array::Array(int n) {
    size = n;
    count = n;
    arr = new Triangle[n];
}

void Array::push_back(Triangle &S) {
    if(count==size){
        size++;
        count++;
        Triangle *newarr=new Triangle[size];
        for(int i=0;i<size-1;i++) {
            newarr[i] = arr[i];
        }
        newarr[size-1]=S;
        arr=newarr;
    }
    else if(count<size){
        arr[count]=S;
        count++;
    }
}

int Array::length() {
    return this->size;
}

void Array::resize(int new_size) {
    if (new_size == size) {
        return;
    }
    if (new_size > size) {
        Triangle *newarr = new Triangle[new_size];
        for (int i = 0; i < new_size; ++i) {
            newarr[i]=arr[i];
        }
        arr = newarr;
        size = new_size;
    } else {
        Triangle *newarr = new Triangle[new_size];
        for (int i = 0; i < new_size; ++i) {
            newarr[i]=arr[i];
        }
        arr = newarr;
        count = new_size;
    }
}

Array::~Array() {
    delete[]arr;
}

bool Array::is_empty() {
    return (size == 0);
}

void Array::insert(int index, Triangle &S) {
    Triangle *newarr = new Triangle[size+1];
    for (int i = 0; i < index-1; ++i){
        newarr[i] = arr[i];
    }
    newarr[index] = S;
    for (int i = index+1; i < size+1; ++i) {
        newarr[i] = arr[i-1];
    }
    size++;
    count++;
    arr = newarr;
}

Triangle& Array::operator[] (int i)
{
    if(i >= 0 && i < this->size) {
        return this->arr[i];
    } else {
        std::cout << "Something went wrong";
    }
}

std::ostream& operator<<(std::ostream &out,  Array &Arr){
    for(int i=0;i<Arr.count;i++){
        out << "Triangle " << i+1 << ": " << Arr[i] << '\n';
    }
    return out;
}

