#include <bits/stdc++.h>
#define pi 3.141592653589793

using namespace std;

class Point{

public:
	double x;
	double y;

	int k;
	double d;

	Point(double xv = 0, double yv = 0, int kv = 0, double dv = 0) : x(xv), y(yv)
	, k(kv), d(dv) {}
};

double radians(double angle){

	return pi * angle / 180.0;
}

double days(double completa, double volta){

	return 360.0 * volta / completa;
}

Point rotate(const Point& P, double angle, int k, double d)
{
    auto x = cos(angle) * P.x - sin(angle) * P.y;
    auto y = sin(angle) * P.x + cos(angle) * P.y;

    return Point { x, y , k, d};
}

int main(){

	int n, T;

	while ( scanf("%d %d", &n, &T) != EOF) {

		int d, k;

		vector < Point > v;

		for ( int i = 0; i < n; i++ ){

			scanf("%d %d", &d, &k);

			if ( i > 0 )
				v.push_back(Point((double)d + v[i-1].x, 0.0, k, d));
			else
				v.push_back(Point((double)d, 0.0, k, d));
		}

		vector < Point > rotated = v;

		rotated[0] = rotate(v[0], radians(days(v[0].k, T % v[0].k)), v[0].k, v[0].d);

		for ( int i = 1; i < v.size(); i++ ){

			Point aux = v[i];
			double p1 = rotated[i-1].x - v[i-1].x;
			double p2 = rotated[i-1].y - v[i-1].y;

			aux.x = p1 + aux.x;
			aux.y = p2 + aux.y;

			aux.x = aux.x - rotated[i-1].x;
			aux.y = aux.y - rotated[i-1].y;

			aux = rotate(aux, radians(days(aux.k, T % aux.k)), aux.k, aux.d);

			aux.x = aux.x + rotated[i-1].x;
			aux.y = aux.y + rotated[i-1].y;

			rotated[i] = aux;
		}

		bool checa = false;

		for ( int i = 0; i < rotated.size(); i++ ){

			if ( checa )
				printf(" ");

			printf("%.4lf", hypot(rotated[i].x, rotated[i].y));

			checa = true;
		}

		printf("\n");
	}
		
	return 0;
}