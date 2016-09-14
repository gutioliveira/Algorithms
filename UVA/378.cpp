#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

class Point {
public:
    double x;
    double y;
    double z;

    Point(double xv = 0, double yv = 0, double zv = 0) : x(xv), y(yv), z(zv) {}

    bool operator==(const Point& b)
	{
	    return equals(x, b.x) && equals(y, b.y) && equals(z, b.z);
	}

};

using pp = pair<Point,Point>;

double distance(const Point& P, const Point& Q)
{
    return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y) + (P.z - Q.z)*(P.z - Q.z));
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

int main(){

	int n;

	scanf("%d", &n);

	int x1,y1,x2,y2,x3,y3,x4,y4;

	printf("INTERSECTING LINES OUTPUT\n");

	for ( int i = 0; i < n; i++ ){

		scanf("%d %d %d %d %d %d %d %d", &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);

		Line l1 = Line(Point(x1,y1), Point(x2,y2));
		Line l2 = Line(Point(x3,y3), Point(x4,y4));

		auto p = intersections(l1,l2);

		if ( p.first == INF ){

			printf("LINE\n");
		}else if ( p.first == 0 ){

			printf("NONE\n");
		}else{

			printf("POINT %.2f %.2lf\n", p.second.x, p.second.y);
		}
	}

	printf("END OF OUTPUT\n");
	
	return 0;
}