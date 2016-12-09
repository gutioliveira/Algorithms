#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	int n;
	int teste = 1;

	while(scanf("%d", &n),n){

		double x = 0.0;
		double y = 0.0;

		double a,b;

		for( int i = 0; i < n; i++ ){

			scanf("%lf %lf", &a, &b);

			x += a;
			y += b;
		}

		printf("Caso %d: %.6lf %.6lf\n", teste++, x/n, y/n);
	}

	return 0;
}