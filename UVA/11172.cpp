#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int teste;
	
	scanf("%d", &teste);
	
	int a, b;
	
	for ( int i = 0 ; i < teste ; i++ ){
		
		scanf("%d %d", &a, &b);
		
		if ( a < b )
			printf("<\n");
		else if ( a > b )
			printf(">\n");
		else
			printf("=\n");
	
	}

	return 0;
}
