#include <bits/stdc++.h>
#define EPS 1e-8

using namespace std;

bool equals(double a, double b){

	return fabs(a-b) < EPS;
}

class Point{

public:
	double x, y;

	Point(double xv = 0, double yv = 0) : x(xv) , y(yv) {}

};

double distance(const Point& P, const Point& Q)
{
    return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y));
}

bool inside(Point &p, Point &a, Point &b) {
 return fabs(distance(a,b) - distance(p,a) - distance(p,b)) < 1e-6;
}

class Triangle{

public:
	Point A,B,C;

	double a,b,c;

    Triangle(const double& av, const double& bv, const double& cv) : a(av), b(bv), c(cv) {}

	Triangle(const Point& av, const Point& bv, const Point& cv) : A(av), B(bv), C(cv) {
		a = distance(A,B);
		b = distance(A,C);
		c = distance(C,B);
	}

	double area() const{

        double det = (A.x * B.y + A.y * C.x + B.x * C.y) - (C.x * B.y + C.y * A.x + B.x * A.y);

        return 0.5 * fabs(det);
    }

    double perimeter() const
    {
        return a + b + c;
    }

    double _area() const
    {
        auto s = perimeter() / 2.0;

        return sqrt(s*(s - a)*(s - b)*(s - c));
    }

    bool is_inside(const Point& p){

    	Triangle pAB = Triangle(p,A,B);
    	Triangle pBC = Triangle(p,B,C);
    	Triangle pAC = Triangle(p,A,C);

    	double sum_areas = pAB.area() + pBC.area() + pAC.area();

    	if ( equals(area(), sum_areas) )
    		return true;

    	return false;
    }

    double inradius() const
    {
        auto p = perimeter()/2.0 + EPS;

        return sqrt( (p-a)*(p-b)*(p-c)/p );

        // double p = (a+b+c)/2+1e-8;
        // double r = sqrt((p-a)*(p-b)*(p-c)/p);
    }

    // Centro do círculo inscrito
    Point incenter() const
    {
        auto p = perimeter();
        auto x = (a*A.x + b*B.x + c*C.x)/p;
        auto y = (a*A.y + b*B.y + c*C.y)/p;

        return Point(x, y);
    }

    double circumradius() const
    {
        return (a * b * c)/(4 * _area());
    }

};

bool is_triangle(const Point& av, const Point& bv, const Point& cv){

	if ( distance(av,bv) < distance(av,cv) + distance(bv,cv) and
	distance(bv,cv) < distance(av,cv) + distance(av,bv) and
	distance(av,cv) < distance(av,bv) + distance(bv,cv)  )
		return true;

	return false;
}

bool is_triangle(double a, double b, double c){

    if ( a < b+c and b < a+c and c < b+a )
        return true;
    
    return false;
}

bool is_between(Point a, Point c, Point b){

    return equals(distance(a,c) + distance(b,c),distance(a,b));
}

int main(){
	
	double a,b,c;

    while ( scanf("%lf %lf %lf", &a, &b, &c) != EOF ){

        double p = (a+b+c)/2+1e-8;
        double r = sqrt( (p-a)*(p-b)*(p-c)/p );

        printf("The radius of the round table is: %.3lf\n", Triangle(a,b,c).inradius());
    }

	return 0;
}