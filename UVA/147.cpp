#include <bits/stdc++.h>

using namespace std;

int values[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

int cont = 0;

long long mapa[12][40005];

long long ways( int index , int value ){

	long long x;

	if ( value == 0 )
		return 1;

	if ( value < 0 )
		return 0;

	if ( index >= 11 )
		return 0;

	if ( mapa[index][value] == -1 ){
		x = ways(index, value - values[index]) + ways(index+1, value);
		mapa[index][value] = x;
	}else
		return mapa[index][value];

	return x;
}

int main(){

	double value;

	int part1, part2;

	char roubo;

	long long possibilities;

	int value_int;

	while(1){

		scanf("%d%c%d", &part1, &roubo, &part2);

		if ( part1 == 0 && part2 == 0 )
			break;

		value_int = part1*100 + part2;

		memset(mapa, -1, sizeof(mapa) );

		possibilities = ways(0, value_int);

		printf("%3d.%02d%17lld\n",part1 , part2, possibilities);
	}

	return 0;
}