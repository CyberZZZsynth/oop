#include <iostream>
#include "cmath"
#define _USE_MATH_DEFINES

using namespace std;

int mod(int a, int b) {
    return (b+a%b)%b;
}

class angle{

private:

    int rgrad, rminutes;
    double rrad;

public:

    int grad;
    int minutes;

    angle(int c, int d) {
        grad = c+d/60;
        minutes = mod(d, 60);
        if(c > 0) {
            minutes = -minutes;
        }
    }

    void printangle() {
        cout << grad+minutes/60 << '*' << mod(minutes, 60) << "'" << '\n';
    }

    void sum_angle(angle a, angle b) {
        rgrad = a.grad+b.grad+(a.minutes+b.minutes)/60;
        rminutes = mod((a.minutes+b.minutes), 60);
    }

    void subt_angle(angle a, angle b) {
        rgrad = a.grad-b.grad-(a.minutes-b.minutes)/60;
        rminutes = mod((a.minutes-b.minutes), 60);
    }

    angle get_sum() {
        angle result(rgrad, rminutes);
        return result;
    }

    angle get_subt() {
        angle result(rgrad, rminutes);
        return result;
    }

    double to_rad() {
        rrad = grad*M_PI/180.0+minutes*M_PI/(60.0*180.0);
        return rrad;
    }

    void to_360(angle a) {
        int p=a.grad, q=a.minutes;
        rgrad = mod(p, 360);
        rminutes = mod(q, 60);
    }

    angle get_360form() {
        angle res(rgrad, rminutes);
        return res;
    }

    bool is_equal(angle a, angle b) {
        a.to_360(a);
        angle alpha = a.get_360form();
        b.to_360(b);
        angle beta = b.get_360form();
        if ((alpha.minutes == beta.minutes) && (beta.grad == alpha.grad)) {
            return true;
        }
        else {
            return false;
        }
    }

    float angle_cos(angle a) {
        a.to_rad();
        double alpha = rrad;
        return cos(alpha);
    }

    float angle_sin(angle a) {
        a.to_rad();
        double alpha = rrad;
        return sin(alpha);
    }

    float angle_tan(angle a) {
        a.to_rad();
        double alpha = rrad;
        return tan(alpha);
    }

    float angle_cot(angle a) {
        a.to_rad();
        double alpha = rrad;
        return 1/tan(alpha);
    }

};
int main() {
    setlocale(LC_ALL, "Russian");
    int c = 0;
    angle alpha(0, 0);
    while(1)
    {
        cout << "1. Input angle" << "\t" << "2. Print angle" << "\t" << "3. Print angle in radians" << "\t" << "4. Print angle in 360 form" << "\t" << "5. Sum and substraction"
        << "\t" << "6. Compare angles" <<  "\t" << "7. Trigonometric functions" << "\t" << "8. Exit" << "\n";
        scanf("%d", &c);
        if (c==1)
        {
            int a, b;
            cout << "Enter angle alpha" << '\n';
            cin >> a >> b;
            angle p(a,b);
            alpha = p;
        }
        if (c==2)
        {
            alpha.printangle();
        }
        if (c==3)
        {
            cout << alpha.to_rad() << "\n";
        }
        if (c==4)
        {
            alpha.to_360(alpha);
            alpha.get_360form();
        }
        if (c==5)
        {
            cout << "Enter angle beta" << "\n";
            int c, d;
            cin >> c >> d;
            angle beta(c,d);
            alpha.sum_angle(alpha, beta);
            cout << "alpha+beta = ";
            (alpha.get_sum()).printangle();
            alpha.subt_angle(alpha, beta);
            cout << '\t' << "alpha-beta = ";
            (alpha.get_subt()).printangle();
        }
        if (c==6)
        {
            cout << "Enter angle beta" << "\n";
            int c, d;
            cin >> c >> d;
            angle beta(c,d);
            if(alpha.is_equal(alpha, beta)) {
                cout << "alpha = beta";
            } else {
                cout << "alpha != beta";
            }
        }
        if (c==7)
        {
            cout << "sin(alpha) = " << alpha.angle_sin(alpha) << '\t' << "cos(alpha) = " << alpha.angle_cos(alpha) << '\t' << "ctg(alpha) = " << alpha.angle_tan(alpha) << '\t' <<
            "ctg(alpha) = " << alpha.angle_cot(alpha) << '\n';
        }
        if (c==8)
        {
            break;
        }
    }
    return 0;
}
