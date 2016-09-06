#include <bits/stdc++.h>
#define MAX 10005
#define EPS 1e-7
using namespace std;

bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

class Point{

public:
	double x,y;

	Point(double xv, double yv){

		x = xv;
		y = yv;
	}

	bool operator < ( const Point &p ) const {

		if (equals(y, p.y))
			return x < p.x;
		else
			return y < p.y;
	}
};


bool same(Point p, Point q){

	return equals(p.x,q.x) and equals(p.y,q.y);
}

int main(){
	
	int c;

	scanf("%d", &c);

	while(c--){

		int t;
		int a,b;

		scanf("%d", &t);

		vector < Point > v;

		int flag[MAX];

		memset(flag, 0, sizeof flag);

		for ( int i = 0; i < t; i++ ){

			scanf("%d %d", &a, &b);

			v.push_back(Point(a,b));
		}

		sort(v.begin(), v.end());

		if ( t == 1 ){
			printf("yes\n");
			continue;
		}
		// else if ( t % 2 == 1 ){
		// 	printf("no\n");
		// 	continue;
		// }

		int cont = 0;

		Point p((v[0].x + v[v.size()-1].x)/2.0,(v[0].y + v[v.size()-1].y)/2.0);

		for ( int i = 1; i < v.size() - 1; i++ ){

			if ( flag[i] )
				continue;

			for ( int j = i + 1; j < v.size() - 1; j++ ){

				Point q((v[i].x + v[j].x)/2.0,(v[i].y + v[j].y)/2.0);

				if ( same(p,q) ){

					flag[i] = 1;
					flag[j] = 1;
					cont++;
					break;
				}	
			}
		}

		// if ( t % 2 == 1 ){

			// for ( int i = 1; i < v.size() - 1; i++ )
			// 	if ( flag[i] == 0 ){

			// 		Point aux(v[i].x, v[i].y);

			// 		printf("%d\n", t/2 + 1);

			// 		printf("%lf %lf\n", aux.x, aux.y);

			// 		if ( same(p, aux) )
			// 			printf("yes\n");
			// 		else
			// 			printf("no\n");

			// 		break;
			// 	}

		// }else 
		if ( cont + 1 == t/2 and t % 2 == 0  )
			printf("yes\n");
		else{

			for ( int i = 1; i < v.size() - 1; i++ )
				if ( flag[i] == 0 ){

					Point aux(v[i].x, v[i].y);

					// printf("%d\n", t/2 + 1);

					// printf("%lf %lf\n", aux.x, aux.y);

					if ( same(p, aux) )
						printf("yes\n");
					else
						printf("no\n");

					break;
				}

			// printf("no\n");
		}
	}

	return 0;
}