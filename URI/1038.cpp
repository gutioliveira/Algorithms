#include <bits/stdc++.h>

using namespace std;

int main(){

	map <int, double> mapa;

	mapa[1] = 4.00;
	mapa[2] = 4.50;
	mapa[3] = 5.00;
	mapa[4] = 2.00;
	mapa[5] = 1.50;

	int a, b;

	scanf("%d %d", &a, &b);

	printf("Total: R$ %.2lf\n", mapa[a]*b);

	return 0;
}