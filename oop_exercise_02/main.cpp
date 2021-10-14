/* Зайцев К. М8О-201Б-20
Вариант 16
Реализовать класс Position(Долгота и широта)
 */
#include <iostream>

using namespace std;

int mod(int a, int b) {
    return (b+a%b)%b;
}

class Position{ //Создание класса Позиций

public:

    int longitude, latitude; // Переменные, отвечающие за широту и долготу

    Position() {
        longitude = 0;
        latitude = 0;
    }

    Position(int d, int c) { // Конструктор класса
        if (d > 90) {
            d = 90-(d%90);
            c+=180;
        } else if (d < -90) {
            d = 90+d%90;
            c+=180;
        }
        if (180 < c) {
            c = -c%180;
        } else if (c < -180) {
            c = mod(c, 180);
        }
        longitude = c;
        latitude = d;
    }

    void PrintPosition(){ // Функция вывода координат
        cout << "Latitude:" << latitude << '\t' << "Longitude" << longitude << '\n';
    }

    friend ostream& operator<< (ostream  &out, const Position &position);
};

Position operator + (Position a, Position b) { // Перегрузка оператора +
    int t, k;
    t = a.longitude+b.longitude;
    k = a.latitude+b.latitude;
    if (k > 90 || k < -90) {
        int tmp = k%90;
        k = 90-tmp;
        t+=180;
    }
    if (t<-180) {
        t = mod(t, 180);
    } else if (t > 180) {
        t = -180+mod(t, 180);
    }
    return Position(t, k);
}

ostream& operator<< (ostream &out, const Position &position) {
    out << "Latitude:" << position.latitude << '\t' << "Longitude" << position.longitude;
    return out;
}

Position operator - (Position a, Position b) { // Перегрузка оператора -
    int t, k;
    t = a.longitude-b.longitude;
    k = a.latitude-b.latitude;
    if (k > 90 || k < -90) {
        int tmp = k%90;
        k = 90-tmp;
        t+=180;
    }
    if (t <- 180) {
        t = mod(t, 180);
    } else if (t > 180) {
        t = -180+mod(t, 180);
    }
    return Position(t, k);
}

Position operator / (Position a, int k) { // Перегрузка оператора деления
    int t, q;
    t = a.longitude / k;
    q = a.latitude / k;
    return Position(q, t);
}

bool operator == (Position a, Position b) {
    if(a.latitude==b.latitude && (a.longitude==180 || a.longitude == -180)  && (b.longitude == -180 || b.longitude == 180)) {
        return true;
    } else  {
        return a.longitude == b.longitude  && a.latitude == b.latitude;
    }
}

bool operator != (Position a, Position b) {
    if (a.latitude == b.latitude && (a.longitude == 180 || a.longitude == -180) &&
        (b.longitude == -180 || b.longitude == 180)) {
        return false;
    } else {
        return a.longitude != b.longitude || a.latitude != b.latitude;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int c = 0;
    Position A, B;
    while(1)
    {
        cout << "1. Input Position" << '\t' << "2. Print Position" << '\t' << "3. Input Position B"  << '\t' << "4.A+B &  A-B & A/k"  << '\t' << "5. A=B?" << '\t' << "6. A!=B?" << '\t' << "7. Exit" << "\n";
        scanf("%d", &c);
        if (c==1) {
            cout << "Input Position A" << '\n';
            int a, b;
            cin >> a >> b;
            Position Q(a, b);
            A = Q;
        }
        if (c==2) {
            cout << A << '\n';
        }
        if (c==3) {
            cout << "Input Position B" << '\n';
            int m, n;
            cin >> m >> n;
            Position L(m,n);
            B=L;
        }
        if (c==4) {
            cout << "Enter k:" << '\n';
            int k;
            cin >> k;
            Position Result1 = A+B;
            cout << "Position A+B=" << Result1 << '\n';
            Position Result2 = A-B;
            cout << "Position A-B=" << Result2 << "\n";
            Position Result3 = A/k;
            cout << "Position A/k=" << Result3 << '\n'
        }
        if (c==5) {
            if(A == B) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        }
        if (c==6) {
            if(A!=B) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        }
        if (c==7) {
            break;
        }
    }
    return 0;
}
