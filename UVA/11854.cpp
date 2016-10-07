#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

bool equals(double a, double b){

    return fabs(a - b) < EPS;
}

class Point {
public:
    double x;
    double y;

    Point(double xv = 0, double yv = 0) : x(xv), y(yv) {}
};

double distance(const Point& P, const Point& Q)
{
    return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y));
}

int main(){

	int a,b,c;

	while(scanf("%d %d %d", &a, &b, &c), a+b+c){

		int maxi = max(a,max(b,c));

		if ( maxi == a )
			swap(a,c);
		else if ( maxi == b )
			swap(b,c);

		Point origem = Point();
		Point p = Point(a,b);

		if ( equals(distance(origem, p), maxi) )
			printf("right\n");
		else
			printf("wrong\n");

	}

	return 0;
}