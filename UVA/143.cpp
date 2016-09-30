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

	Triangle(const Point& av, const Point& bv, const Point& cv) : A(av), B(bv), C(cv) {}

	double area() const{

        double det = (A.x * B.y + A.y * C.x + B.x * C.y) - (C.x * B.y + C.y * A.x + B.x * A.y);

        return 0.5 * fabs(det);
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

};

bool is_triangle(const Point& av, const Point& bv, const Point& cv){

	if ( distance(av,bv) < distance(av,cv) + distance(bv,cv) and
	distance(bv,cv) < distance(av,cv) + distance(av,bv) and
	distance(av,cv) < distance(av,bv) + distance(bv,cv)  )
		return true;

	return false;
}

bool is_between(Point a, Point c, Point b){

    return equals(distance(a,c) + distance(b,c),distance(a,b));
}

int main(){
	
	double x1,y1,x2,y2,x3,y3;

	while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) ){

		if ( equals((x1+y1+x2+y2+x3+y3), 0.0) )
			return 0;

		Triangle t = Triangle(Point(x1,y1), Point(x2,y2), Point(x3,y3));

		int count = 0;

		double x_max = max(x1, max(x2,x3));
		double y_max = max(y1, max(y2,y3));

		double x_min = min(x1, min(x2,x3));
		double y_min = min(y1, min(y2,y3));		

		if ( is_triangle(Point(x1,y1), Point(x2,y2), Point(x3,y3)) )
			for ( int i = 1; i <= 99; i++ )
				for ( int j = 1; j <= 99; j++ )
					if ( t.is_inside(Point(i,j)) )
						count++;
		else
			for ( int i = 1; i <= 99; i++ )
				for ( int j = 1; j <= 99; j++ )
					if ( is_between(Point(x_min, y_min),Point(i,j),Point(x_max, y_max)) )
						count++;


		printf("%4d\n", count);
	}

	return 0;
}