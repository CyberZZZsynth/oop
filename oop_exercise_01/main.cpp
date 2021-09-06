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
    int a, b, c, d;
    cout  << "Input angle alpha:" << '\n';
    cin >> a >> b;
    angle alpha(a,  b);
    cout  << "Input angle beta:" << '\n';
    cin >> c >> d;
    angle beta(c, d);
    alpha.printangle();
    beta.printangle();
    cout << "Is alpha equal beta?" << '\t' <<  alpha.is_equal(alpha, beta)  << '\n';
    cout <<  "get alpha in rad:" << '\n' << alpha.to_rad() << '\n';
    cout <<  "get beta in rad:" << '\n' << beta.to_rad() << '\n';
    cout  << "alpha+beta is" <<  '\n';
    alpha.sum_angle(alpha, beta);
    (alpha.get_sum()).printangle();
    cout << "alpha-beta is" << '\n';
    alpha.subt_angle(alpha, beta);
    (alpha.get_subt()).printangle();
    cout << "alpha in 360* form:" << '\n';
    alpha.to_360(alpha);
    (alpha.get_360form()).printangle();
    cout << "cos(alpha) = "  << alpha.angle_cos(alpha) << '\t' << "sin(alpha) = "  << alpha.angle_sin(alpha) << '\t' << "tg(alpha) = "
         << alpha.angle_tan(alpha) << '\t' << "ctg(alpha) = "  << alpha.angle_cot(alpha) << '\n';
    cout << "cos(beta) = "  << beta.angle_cos(beta) << '\t' << "sin(beta) = "  << beta.angle_sin(beta) << '\t' << "tg(beta) = "
         << beta.angle_tan(beta) << '\t' << "ctg(beta) = "  << beta.angle_cot(beta) << '\n';
}
