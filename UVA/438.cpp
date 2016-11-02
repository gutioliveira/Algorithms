#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

bool equals(double a, double b){

	return fabs(a-b) < EPS;
}

class Point{

public:
	double x, y;

	Point(double xv, double yv) : x(xv) , y(yv) {}

};

double distance(const Point& P, const Point& Q){

    return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y));
}

class Triangle{

public:

	double a,b,c;

    Point A, B, C;

    Triangle(const Point& P, const Point& Q, const Point& R) : A(P), B(Q), C(R) {

        a = distance(A,B);
        b = distance(A,C);
        c = distance(B,C);
    }

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
	
	double x1,y1,x2,y2,x3,y3;

    const double pi = acos(-1);

    while ( scanf("%lf %lf %lf %lf %lf %lf", &x1,&y1,&x2,&y2,&x3,&y3) != EOF ){

        Triangle t = Triangle(Point(x1,y1),Point(x2,y2),Point(x3,y3));

        double circun = 2.0 *  t.circumradius() * pi;

        printf("%.2lf\n", circun);
    }

	return 0;
}