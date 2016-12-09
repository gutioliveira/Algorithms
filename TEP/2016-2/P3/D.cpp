#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Point{

public:
	double x,y;

	Point(double xv = 0, double yv = 0) : x(xv) , y(yv) {}

};

using interval = pair<double, double>;

class Rectangle {

public:
    Point P, Q;
    double b, h;

    Rectangle(const Point& p, const Point& q) : P(p), Q(q){

        b = fabs(P.x - Q.x);
        h = fabs(P.y - Q.y);
    }

    double area() const{

        return b * h;
    }

    bool intersection(const Rectangle& r, Rectangle& inter) const {

        auto I = interval(min(P.x, Q.x), max(P.x, Q.x));
        auto U = interval(min(r.P.x, r.Q.x), max(r.P.x, r.Q.x));

        auto a = max(I.first, U.first);
        auto b = min(I.second, U.second);

        if (b < a)
            return false;

        I = interval(min(P.y, Q.y), max(P.y, Q.y));
        U = interval(min(r.P.y, r.Q.y), max(r.P.y, r.Q.y));

        auto c = max(I.first, U.first);
        auto d = min(I.second, U.second);

        if (d < c)
            return false;

        inter = Rectangle(Point(a, c), Point(b, d));

        return true;
    }
};

int main(){

	int teste;

	scanf("%d", &teste);

	int c;

	int x1,y1,x2,y2;

	int area = 0;

	for ( int t = 1; t <= teste; t++ ){

		scanf("%d", &c);

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		Rectangle r1 = Rectangle(Point(x1,y1), Point(x2,y2));

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		Rectangle r2 = Rectangle(Point(x1,y1), Point(x2,y2));

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		Rectangle r3 = Rectangle(Point(x1,y1), Point(x2,y2));

		Rectangle inter = Rectangle(Point(), Point());

		double a1 = r1.area(),a2 = r2.area(), a3 = r3.area();

		if ( r2.intersection(r3, inter) ){

			a2 = a2 - inter.area();
		}

		a1 = a1 - a2 - a3;

		if ( c == 1 )
			area = a2 + a3;
		else if ( c == 2 )
			area = a1 + a3;
		else
			area = a1 + a2;

		printf("Caso %d: %d\n", t, area);
	}

	return 0;
}