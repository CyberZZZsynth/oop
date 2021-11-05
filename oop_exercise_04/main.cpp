/*
 Лабораторная работа 4
 Вариант 6
 Выполнил студент группы М8О-201Б-20
 Зайцев Кирилл
 */
#include <iostream>
#include "Point.h"
#include "Figure.h"
#include "Triangle.h"
#include "Array.h"

using namespace std;

int main() {
    int c=0;
    Array vector;
    while (1) {
        cout << "1. Create vector" << "\t" << "2. Push back element" <<  "\t" <<"3. Insert element via index" << "\t" << "4. Print vector's length" << "\t" <<
                                                                           "5. Print vector" << "\t" << "6. Resize vector" << '\t' <<  "7. Delete element via index" << '\t' << "8. Remove vector"  << '\t' << "9. Exit" << '\n';
        cin >> c;
        if (c == 1) {
            cout << "vector created" << '\n';
        }
        if (c == 2) {
            cout << "Enter triangle" << '\n';
            Triangle tmp;
            cin >> tmp;
            vector.push_back(tmp);
        }
        if (c == 3) {
            cout << "Enter index" << '\n';
            int index;
            cin >> index;
            if (index > vector.length() - 1) {
                cout << "Something went wrong" << '\n';
            } else {
                cout << "Enter triangle" << '\n';
                Triangle tmp;
                cin >> tmp;
                vector.insert(index, tmp);
            }
        }
        if (c == 4) {
            cout << vector.length() << '\n';
        }
        if (c == 5) {
            cout << vector << '\n';
        }
        if (c == 6) {
            cout << "Enter new size" << '\n';
            int n;
            cin >> n;
            vector.resize(n);
        }
        if (c == 8) {
            vector.delete_vector();
        }
        if (c == 7) {
            cout << "Enter index" << '\n';
            int k;
            cin >> k;
            vector.remove(k);
        }
        if (c == 9) {
            exit(1);
        }
    }
}
