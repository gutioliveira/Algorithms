#include <bits/stdc++.h>

using namespace std;

int main(){

	int T;

	scanf("%d", &T);

	const double pi = acos(-1);

	while(T--){

		int r;

		scanf("%d", &r);

		double lado = sin(pi/4.0) * r * 2.0;

		double area = pi * r * r - lado * lado;

		printf("%.3lf %.3lf\n", lado, area);
	}

	return 0;
}