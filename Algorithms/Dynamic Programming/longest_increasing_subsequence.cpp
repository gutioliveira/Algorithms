#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int array[] = {3,4,-1,0,6,2,3};

	int values[] = {1,1,1,1,1,1,1};

	map < int, vector<int> > mapa; // stores every number on the LIS not sorted.

	for ( int i = 0; i < 7; i++ )
		mapa[i].push_back(array[i]); 

	// LIS
	for ( int i = 1; i < 7; i++ )
		for ( int j = 0; j < i; j++ ){

			if ( array[i] > array[j] )
				if ( values[j]+1 > values[i] ){

					mapa[i].push_back(array[j]); //

					values[i] = values[j]+1;
				}
		}
	//
	printf("\n");

	for ( int i = 0; i < 7; i++ ){
		printf("LIS size = %d\n", values[i]); // prints size of LIS.
	
		printf("numbers on the subsequence.");
		// for ( int i = 0; i < 7; i++ ){
			for ( int j = 0; j < mapa[i].size(); j++ )
				printf(" %d", mapa[i][j]);

			printf("\n");
		// }
	}
		

	return 0;
}