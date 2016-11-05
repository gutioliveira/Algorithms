#include <bits/stdc++.h>

const double PI = acos(-1);

using namespace std;

class Point{

public:
	double x,y;

	Point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

};

class Circle {
public:
    Point C;
    double r;

    Circle(const Point& Cv = Point(0, 0), double rv = 1.0) : C(Cv), r(rv) {}

    double area() const{

    	return PI * r * r;
	}

	double chord(double a) const{

	    return 2 * r * sin(a/2);
	}

	double sector(double a) const{

        return a * r * r / 2.0;
    }

    double segment(double a) const
    {
        auto c = chord(a);
        auto s = (r + r + c)/2.0;
        auto T = sqrt(s*(s - r)*(s - r)*(s - c));

        return sector(a) - T;
    }
};

int main(){

	double r,k,d;

	const double pi = acos(-1);

	int t = 1;

	while( scanf("%lf %lf %lf", &r, &k, &d) != EOF ){

		double massa = 0.0;

		double r1 = r * k;

		double area_menor = r1 * r1 * pi;

		Circle c = Circle(Point(0,0), r1);

		double segmento = c.segment(2.0*pi/3.0) * 3.0;

		double triangulos = area_menor - segmento;

		triangulos = triangulos/4.0 * 3.0;

		double area_maior = r * r * pi;

		massa = (area_maior - area_menor + triangulos) * 0.5;

		printf("Caso %d: %.6lf\n", t++, massa * d);
	}

	return 0;
}