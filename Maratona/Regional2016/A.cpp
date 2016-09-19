#include <bits/stdc++.h>

using namespace std;

int main(){

	int a,b,c;

	scanf("%d %d %d", &a, &b, &c);

	if ( a - b == 0 ){
		printf("S\n");
		return 0;
	}

	if ( a - c == 0 ){
		printf("S\n");
		return 0;
	}

	if ( a + b - c == 0 ){
		printf("S\n");
		return 0;
	}

	if ( a + c - b == 0 ){
		printf("S\n");
		return 0;
	}

	if ( c - b == 0 ){
		printf("S\n");
		return 0;
	}

	if ( c + b -a == 0 ){
		printf("S\n");
		return 0;
	}

	printf("N\n");
	
	return 0;
}