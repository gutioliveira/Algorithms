#include <bits/stdc++.h>
#define EPS 1e-6

using namespace std;

double const pi = acos(-1);

bool equals(double a, double b){

	return fabs(a - b) < EPS;
}

bool is_triangle(double a, double b, double c){

	if ( a < b + c and b < a + c and c < a + b  )
		return true;

	return false;
}

class Point {
public:
    double x;
    double y;

    Point(double xv = 0, double yv = 0) : x(xv), y(yv) {}
};

Point rotate(const Point& P, double angle)
{
    auto x = cos(angle) * P.x - sin(angle) * P.y;
    auto y = sin(angle) * P.x + cos(angle) * P.y;

    return Point { x, y };
}

double distance(const Point& P, const Point& Q)
{
    return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y));
}

class Line {
public:
    double a;
    double b;
    double c;

    Line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

    Line(const Point& p, const Point& q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - p.y * q.x;

        auto k = a ? a : b;

        a /= k;
        b /= k;
        c /= k;
    }

    bool operator==(const Line& r) const
    {
        return equals(a, r.a) && equals(b, r.b) && equals(c, r.c);
    }

    bool parallel(const Line& r) const
    {
        return equals(a, r.a) && equals(b, r.b) && !equals(c, r.c);
    }

    bool orthogonal(const Line& r) const
    {
        return equals(a * r.a + b * r.b, 0);
    }

    double distance(const Point& p) const
    {
        return fabs(a*p.x + b*p.y + c)/hypot(a, b);
    }
};

#define INF -1

pair<int, Point> intersections(const Line& r, const Line& s)
{
    auto det = r.a * s.b - r.b * s.a;

    if (equals(det, 0))
    {
        // Coincidentes ou paralelas
        int qtd = (r == s) ? INF : 0;

        return pair<int, Point>(qtd, Point()); 
    } else  
    {
        // Concorrentes
        auto x = (-r.c * s.b + s.c * r.b) / det;
        auto y = (-s.c * r.a + r.c * s.a) / det;

        return pair<int, Point>(1, Point(x, y));
    }
}

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
};

bool is_triangle(const Point& av, const Point& bv, const Point& cv){

	if ( distance(av,bv) < distance(av,cv) + distance(bv,cv) and
	distance(bv,cv) < distance(av,cv) + distance(av,bv) and
	distance(av,cv) < distance(av,bv) + distance(bv,cv)  )
		return true;

	return false;
}

class Segment {
public:
    Point A, B;

    Segment(const Point& Av, const Point& Bv) : A(Av), B(Bv) {}

    double length() const
    {
        return hypot(A.x - B.x, A.y - B.y);
    }

    bool contains(const Point& P) const
    {
        if (equals(A.x,B.x))
            return min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y);
        else
            return min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
    }
};

int main(){

	int l, w, h, t;

	while( scanf("%d %d %d %d", &l, &w, &h, &t) != EOF ){

		double a = pi * t / 180.0;

		// double hipo = (double)l/cos(a);

		// double h2 = hipo * sin(a);

// printf("%lf %lf %lf\n",(double)l, hipo, h2);

		// Triangle triangle = Triangle(hipo,h2,l);

		// if ( is_triangle(triangle.a, triangle.b, triangle.c) ){

		// 	double result = abs(l*h*w - triangle.area()*w);
		// 	printf("%.3lf mL\n", result);
		// }

		Point p1 = Point(0,h);
		Point p2 = Point(l,h);
		Point p3 = Point(l,0);

		p1 = rotate(p1, a);
		p2 = rotate(p2, a);
		p3 = rotate(p3, a);

		Segment segment = Segment(p2,p3);

		Line horizontal = Line(p1, Point(9999, p1.y));
		Line check = Line(p2,p3);

		auto p = intersections(check, horizontal);

		if ( segment.contains(p.second) ){

			Triangle t1 = Triangle(distance(p1,p2), distance(p2,p.second),
				distance(p1,p.second));

			printf("%.3lf mL\n", l*h*w - t1.area()*w);
		}else{

			Line horizontal = Line(p1, Point(9999, p1.y));
			Line check = Line(p3,Point());

			auto p = intersections(check, horizontal);

			Triangle t = Triangle(distance(p1, p.second),
				distance(p1, Point()), distance(p.second, Point()));

			printf("%.3lf mL\n", t.area()*w);
		}
		// printf("%d\n", p.first);
		// if ( is_triangle(p1,p2,p.second) )
		// 	printf("ok\n");
		// else
		// 	printf("not ok\n");
		// printf("%lf %lf\n%lf %lf\n%lf %lf\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
		// printf("%lf %lf\n", p.second.x, p.second.y);
		// if ( equals(distance(p1,p2),l) )
		// 	printf("hue\n");
	}

	return 0;
}