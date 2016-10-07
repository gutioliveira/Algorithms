#include <bits/stdc++.h>

using namespace std;

double const pi = acos(-1);

class Triangle {
public:
    double a, b, c;

    Triangle(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

    double perimeter() const{

        return a + b + c;
    }

    double area() const{

        auto s = perimeter() / 2.0;

        return sqrt(s*(s - a)*(s - b)*(s - c));
    }

    double circumradius() const{

        return (a * b * c)/(4 * area());
    }

    double inradius() const{

        return (2 * area()) / perimeter();
    }
};

int main(){

	int a,b,c;

    while ( scanf("%d %d %d", &a, &b, &c) != EOF ){

        Triangle t = Triangle(a,b,c);

        double radius1 = t.circumradius();
        double radius2 = t.inradius();

        printf("%.4lf %.4lf %.4lf\n", pi * radius1 * radius1 - t.area(),
            t.area() - pi * radius2 * radius2, pi * radius2 * radius2);
    }

	return 0;
}