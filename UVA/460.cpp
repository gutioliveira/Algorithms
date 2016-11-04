#include <bits/stdc++.h>

using namespace std;

class Point{
public:
	double x,y;

	Point(const double xv = 0.0, const double yv = 0.0) : x(xv) , y(yv) {}

};

using interval = pair<double, double>;

class Rectangle {
public:
    Point P, Q;
    double b, h;

    Rectangle(const Point& p, const Point& q) : P(p), Q(q)
    {
        b = fabs(P.x - Q.x);
        h = fabs(P.y - Q.y);
    }

    Rectangle(double base, double height)
        : P(0, 0), Q(base, height), b(base), h(height) {}

    bool operator == (const Rectangle& a) const{

    	if ( P.x == a.P.x and Q.x == a.Q.x and P.y == a.P.y and Q.y == a.Q.y )
    		return true;
    	else
    		return false;
    }

    double perimeter() const
    {
        return 2 * b * h;
    }

    double area() const
    {
        return b * h;
    }

    bool intersection(const Rectangle& r, Rectangle& inter) const
    {
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

	int n;

	scanf("%d", &n);

	int xll, yll, xur, yur;

	int xll2, yll2, xur2, yur2;

	bool pula = false;

	while(n--){

		scanf("%d %d %d %d", &xll, &yll, &xur, &yur);
		scanf("%d %d %d %d", &xll2, &yll2, &xur2, &yur2);

		Rectangle r = Rectangle(Point(xll,yll), Point(xur,yur));
		Rectangle r1 = Rectangle(Point(xll2,yll2), Point(xur2,yur2));
		Rectangle inter = Rectangle(Point(), Point());

		if ( pula )
			printf("\n");

		pula = true;

		if ( r.intersection(r1, inter) ){
			
			if ( inter.area() == 0.0 )
				printf("No Overlap\n");
			else
				printf("%.0lf %.0lf %.0lf %.0lf\n", inter.P.x, inter.P.y, inter.Q.x, inter.Q.y);
		}else{

			printf("No Overlap\n");
		}
	}

	return 0;
}