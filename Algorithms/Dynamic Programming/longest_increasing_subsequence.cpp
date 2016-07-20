#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int array[] = {3,4,-1,0,6,2,3};

	int actual_solution[] = {-1,-1,-1,-1,-1,-1,-1}; // stores the actual subsequence.

	int values[] = {1,1,1,1,1,1,1};

	// LIS
	for ( int i = 1; i < 7; i++ )
		for ( int j = 0; j < i; j++ ){

			if ( array[i] > array[j] )
				if ( values[j]+1 > values[i] ){

					actual_solution[i] = j;

					values[i] = values[j]+1;
				}
		}
	//
	printf("\n");

	map < int, vector<int> > mapa;

	for ( int i = 0; i < 7; i++ ){
		printf("LIS size = %d\n", values[i]); // prints size of LIS.

		int te = i;

		while(1){ // puts on a map the solution.

			if ( te == -1 )
				break;

			mapa[i].push_back(array[te]);

			te = actual_solution[te];
		}
	
		printf("numbers on the subsequence.");
		// for ( int i = 0; i < 7; i++ ){
			for ( int j = 0; j < mapa[i].size(); j++ )
				printf(" %d", mapa[i][j]);

			printf("\n");
		// }
	}
		

	return 0;
}