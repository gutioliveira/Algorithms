#include <bits/stdc++.h>

using namespace std;

int main(){

	int T;

	const double pi = acos(-1);

	scanf("%d", &T);

	while(T--){

		double L;

		scanf("%lf", &L);

		double h = L - 2*(L/5);

		double area_circle = pi * (L/5) * (L/5);

		double area_rectangle = L*h - area_circle;

		printf("%.2lf %.2lf\n", area_circle, area_rectangle);
	}

	return 0;
}