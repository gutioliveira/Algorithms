#include <bits/stdc++.h>

using namespace std;

long long numberOfSolutionsOnSpace(int total, int arr[]){
        
        long long *temp = new long long[total+1];
        
        temp[0] = 1;

        for( int i = 0 ; i < 21 ; i++ ){

            for( int j = 1 ; j <= total ; j++ ){

                if( j >= arr[i] )
                    temp[j] += temp[j-arr[i]];

            }
        }

        return temp[total];
}
int main(){

	int coins[] = {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
	
    int total;	

	while( scanf("%d", &total ) != EOF ){

		printf("%lld\n", numberOfSolutionsOnSpace(total, coins));
	}

	return 0;
}