#include <bits/stdc++.h>

using namespace std;

int main(){

	int N;

	scanf("%d", &N);

	double d,l;

	const double pi = acos(-1);

	while(N--){

		scanf("%lf %lf", &d, &l);

		double angle = acos((d/2.0)/(l/2.0));

		double h = sin(angle) * (l/2.0);

		double area = pi * h * l/2.0;

		printf("%.3lf\n", area);
	}

	return 0;
}