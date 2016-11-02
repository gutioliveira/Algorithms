#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

double equals(double a, double b){

	return fabs(a-b) < EPS;
}

class Point {
public:
    double x;
    double y;

    Point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

 //    double distance(const Point& Q)
	// {
 //    	return sqrt((x - Q.x)*(x - Q.x) + (y - Q.y)*(y - Q.y));
	// }
};

class Circle {
public:
    Point C;
    double r;

    Circle(const Point& Cv = Point(0, 0), double rv = 1.0) : C(Cv), r(rv) {}

    double chord(double a) const
    {
        return 2 * r * sin(a/2);
    }
	double sector(double a) const
    {
        return a * r * r / 2.0;
    }
    double segment(double a) const
    {
        auto c = chord(a);
        auto s = (r + r + c)/2.0;                   // Semiperímetro
        auto T = sqrt(s*(s - r)*(s - r)*(s - c));   // Área do triângulo

        return sector(a) - T;
    }
};

double distance(const Point& P, const Point& Q)
{
    return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y));
}

#define INF -1

using pp = pair<Point, Point>;
using ipp = pair<int, pp>;

ipp intersection(const Circle& c1, const Circle& c2)
{
    double d = distance(c1.C,c2.C);

    if (d > c1.r + c2.r or d < fabs(c1.r - c2.r))
        return ipp(0, pp(Point(), Point()));

    if (equals(d, 0) and equals(c1.r, c2.r))
        return ipp(INF, pp(Point(), Point()));

    auto a = (c1.r * c1.r - c2.r * c2.r + d * d)/(2 * d);
    auto h = sqrt(c1.r * c1.r - a * a);

    auto x = c1.C.x + (a/d)*(c2.C.x - c1.C.x);
    auto y = c1.C.y + (a/d)*(c2.C.y - c1.C.y);

    auto P = Point(x, y);

    x = P.x + (h/d)*(c2.C.y - c1.C.y);
    y = P.y - (h/d)*(c2.C.x - c1.C.x);
    auto P1 = Point(x, y);

    x = P.x - (h/d)*(c2.C.y - c1.C.y);
    y = P.y + (h/d)*(c2.C.x - c1.C.x);

    auto P2 = Point(x, y);

    return ipp(equals(d, c1.r + c2.r) ? 1 : 2, pp(P1, P2));
}

int main(){

	double a;

	const double pi = acos(-1);

	double strip, dot, rest, area;

	while ( scanf("%lf", &a) != EOF ){

		Point A = Point(0.0, 0.0);
		Point B = Point(a, 0.0);

		Circle cA = Circle(A, a);
		Circle cB = Circle(B, a);

		ipp doispontos = intersection(cA,cB);

		// printf("x1 %lf y1 %lf\nx2 %lf y2 %lf\n", doispontos.second.first.x, 
		// 	doispontos.second.first.y,
		// 	doispontos.second.second.x,
		// 	doispontos.second.second.y );

		double angleChord = atan(doispontos.second.second.y/doispontos.second.second.x);

		double parteATirar = cA.segment(angleChord);

		double angleRodar = pi/2 - angleChord;

		double pizza = angleRodar/2.0 * a * a - parteATirar;

		double areaParcial = pi/4 * a * a;

		double areaQuadrado = a * a;

		// printf("%lf %lf\n", areaaQuadrado, areaParcial);

		double a3 = areaQuadrado - areaParcial - pizza;

		double a2 = areaQuadrado - areaParcial - 2.0*a3;

		double a1 = areaQuadrado - a2*4.0 - a3*4.0;
		if ( !equals(a,0) )
			printf("%.3lf %.3lf %.3lf\n", a1, a2 * 4.0, a3 * 4.0);
		else
			printf("0.000 0.000 0.000\n");
	}

	return 0;
}