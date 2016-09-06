#include <bits/stdc++.h>

#define INF 429496729

using namespace std;

class Point{

public:
	double x,y,z;

	Point(double xv = 0, double yv = 0, double zv = 0) : x(xv), y(yv), z(zv) {}

};

double distance(const Point& P, const Point& Q)
{
    return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y) + (P.z - Q.z)*(P.z - Q.z));
}

int main(){
	
	double x,y,z;

	vector <Point> v;

	while(scanf("%lf %lf %lf", &x, &y, &z), (int)(x+y+z)){

		Point p(x,y,z);

		v.push_back(p);
	}

	int d[11];

	memset(d, 0, sizeof d);

	double minimum = INF;
	int aux;
	int index;

	int flags[5005];

	memset(flags, 0, sizeof flags);

	for ( int i = 0; i < v.size(); i++ ){
		for ( int j = 0; j < v.size(); j++ ){

			if ( i != j ){

				if ( ( distance(v[i], v[j]) < minimum ) ){

					minimum = distance(v[i],v[j]);
					index = j;
				}
			}
		}

		if ( minimum < 1.0 )
			d[1]++;
		else if ( minimum < 2.0 )
			d[2]++;
		else if ( minimum < 3.0 )
			d[3]++;
		else if ( minimum < 4.0 )
			d[4]++;
		else if ( minimum < 5.0 )
			d[5]++;
		else if ( minimum < 6.0 )
			d[6]++;
		else if ( minimum < 7.0 )
			d[7]++;
		else if ( minimum < 8.0 )
			d[8]++;
		else if ( minimum < 9.0 )
			d[9]++;
		else if ( minimum < 10.0 )
			d[10]++;

		minimum = INF;
	}

	for ( int i = 1; i <= 10; i++ )
		printf("%4d", d[i]);

	printf("\n");

	return 0;
}

/*

10 10 0 -> inf
10 10 15
10 10 1 -> inf
10 10 3
10 10 36
10 10 45
10 10 6
10 10 10 -> inf
10 10 21
10 10 28 -> inf
10 10 0 -> inf

20 20 0
20 20 0
20 20 2
20 20 6
20 20 12
20 20 20
20 20 30
20 20 42
20 20 56
20 20 72
20 20 90

1 = 2
2 = 1
3 = 
4 = 
5 = 1
6 = 
7 = 
8 = 1
9 = 
*/