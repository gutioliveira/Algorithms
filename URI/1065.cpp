#include <bits/stdc++.h>

using namespace std;

int main(){

	int a,b,c,d,e;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	int i = 0;

	if ( a % 2 == 0 )
		i++;
	if ( b % 2 == 0 )
		i++;
	if ( c % 2 == 0 )
		i++;
	if ( d % 2 == 0 )
		i++;
	if ( e % 2 == 0 )
		i++;

	printf("%d valores pares\n", i);

	return 0;
}