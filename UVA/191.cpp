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

	bool operator < (const Point& p) const{

		if ( x > p.x )
			return true;
		else
			return false;
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

    Point A;
    Point B;

    Line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

    Line(const Point& p, const Point& q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - p.y * q.x;

        A = p;
        B = q;

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

    Point closest(const Point& p) const // Ponto da reta mais próximo de p
    {
        auto den = a*a + b*b;
        auto x = (b*(b*p.x - a*p.y) - a*c)/den;
        auto y = (a*(-b*p.x + a*p.y) - b*c)/den;

        return Point(x, y);
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

double D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
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
        if (A.x == B.x)
            return min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y);
        else
            return min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
    }

    bool intersect(const Segment& s) const
    {
        auto d1 = D(A, B, s.A);
        auto d2 = D(A, B, s.B);

        if ((equals(d1, 0) && contains(s.A)) || (equals(d2, 0) && contains(s.B)))
            return true;

        auto d3 = D(s.A, s.B, A);
        auto d4 = D(s.A, s.B, B);

        if ((equals(d3, 0) && s.contains(A)) || (equals(d4, 0) && s.contains(B)))
            return true;

        return (d1 * d2 < 0) && (d3 * d4 < 0);
    }

    Point closest(const Point& P)
    {
        Line r(A, B);

        auto Q = r.closest(P);

        if (this->contains(Q))
            return Q;

        auto distA = distance(P,A); 
        auto distB = distance(P,B);

        if (distA <= distB)
            return A;
        else
            return B;
    }
};

bool is_between(Point a, Point c, Point b){

	return equals(distance(a,b) + distance(c,b), distance(a,b));
}

using id=pair<int,double>;

int main(){

	int n;

	scanf("%d", &n);

	int xstart,ystart,xend,yend;

	int xleft,ytop,xright,ybottom;

	for ( int i = 0; i < n; i++ ){

		scanf("%d %d %d %d %d %d %d %d",&xstart,&ystart,&xend,&yend,&xleft,&ytop,&xright,&ybottom);

		if ( xleft > xright )
			swap(xleft,xright);

		if ( ybottom > ytop )
			swap(ybottom,ytop);

		Segment l = Segment(Point(xstart, ystart),Point(xend,yend));

		vector < Segment > segments;

		segments.push_back(Segment(Point(xleft,ytop),Point(xright,ytop)));
		segments.push_back(Segment(Point(xleft,ybottom),Point(xright,ybottom)));
		segments.push_back(Segment(Point(xleft,ytop),Point(xleft,ybottom)));
		segments.push_back(Segment(Point(xright,ytop),Point(xright,ybottom)));

		int aux = false;

		for ( int i = 0; i < segments.size(); i++ )
			if ( segments[i].intersect(l) ){
				aux = true;
				break;
			}

		if ( xleft <= xstart and xstart <= xright and ybottom <= ystart and ystart <= ytop
			 and xleft <= xend and xend <= xright and ybottom <= yend and yend <= ytop )
			aux = true;

		if ( aux )
			printf("T\n");
		else
			printf("F\n");
	}

	return 0;
}