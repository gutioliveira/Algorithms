#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

bool equals(double a, double b){

    return fabs(a - b) < EPS;
}

bool is_triangle(long long int a,long long int b,long long int c){

	if ( a + b <= c and a + c <= b and b + c <= a )
		return false;
	else
		return true;
}

int main(){

	int teste;

	scanf("%d", &teste);

	for ( int t = 1; t <= teste; t++ ){

		string tipo;

		long long int a,b,c;

		scanf("%lld %lld %lld", &a, &b, &c);

		if ( a <= 0 || b <= 0 || c <= 0 )
			tipo = "Invalid";
		else if ( is_triangle(a,b,c) )
			tipo = "Invalid";
		else if ( a == b and b == c )
			tipo = "Equilateral";
		else if ( a != b and b != c )
			tipo = "Scalene";
		else
			tipo = "Isosceles";

		printf("Case %d: %s\n", t, tipo.c_str());
	}

	return 0;
}