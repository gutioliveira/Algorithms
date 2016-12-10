#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define EPS 1e-9

bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

class Point{

public:
	double x,y;

	Point(double xv = 0, double yv = 0) : x(xv) , y(yv) {}

};

double distance(const Point& P, const Point& Q)
{
    return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y));
}

int main(){

	int px,py,qx,qy;

	int n,k,v;

	int teste = 1;

	while( scanf("%d %d %d %d", &px, &py, &qx, &qy) != EOF ){

		scanf("%d %d", &n, &k);

		Point p = Point(px,py);
		Point q = Point(qx,qy);

		int x,y;

		int P = 0, Q = 0;

		for ( int i = 0; i < n; i++ ){

			scanf("%d %d %d", &x, &y, &v);

			Point c = Point(x,y);

			double dP = distance(c,p);
			double dQ = distance(c,q);

			if ( equals(dP,dQ) ){


			}else if ( dP < dQ ){

				P += v;
			}else{

				Q += v;
			}
		}

		printf("Caso %d: %s\n", teste++, fabs(P-Q) <= k ? "S" : "N");
	}

	return 0;
}