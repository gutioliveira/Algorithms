#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

const double pi = acos(-1);

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
    double arc(double a) const
    {
        return a * r;
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
    double perimeter() const {

        return 2.0 * pi * r;
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

	double s;
    double angle;
    double radians;
    string type;

    while ( cin >> s >> angle >> type ){

        if ( type == "min" ){

            angle = angle / 60.0;

            radians = pi * angle / 180.0;
        }else{

            angle = (long long) angle % 360;

            radians = pi * angle / 180.0;
        }

        Circle earth = Circle(Point(0,0), s + 6440.0);

        double arc = angle > 180 ? earth.perimeter() - earth.arc(radians) : earth.arc(radians);

        printf("%.6lf %.6lf\n",arc, earth.chord(radians));
    }

	return 0;
}