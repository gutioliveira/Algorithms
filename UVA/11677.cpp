#include <bits/stdc++.h>

using namespace std;

int time(int h1, int h2, int m1, int m2){

	int minutes;

	if ( h1 == h2 ){

		if ( m1 == m2 ){

			minutes = 0;

		}else if ( m1 < m2 ){

			minutes = m2 - m1;

		}else{

			minutes = 23*60 + 60 - m1 + m2;
		}

	}else if ( h1 > h2 ){

		if ( m1 == m2 ){

			minutes = (23 - h1)*60 + h2*60 + 60 - m1 + m2;

		}else if ( m1 < m2 ){

			minutes = (23 - h1)*60 + h2*60 + 60 - m1 + m2;

		}else{

			minutes = (23 - h1)*60 + h2*60 + 60 - m1 + m2;
		}

	}else if ( h1 < h2 ){


		if ( m1 == m2 ){

			minutes = ( h2 - h1 )*60;
		}else if ( m1 < m2 ){

			minutes = ( h2 - h1 )*60 + m2 - m1;
		}else{

			minutes = ( h2 - h1 )*60 + m2 - m1;
		}

	}


	return minutes;
}

int main(){

	int h1, m1, h2, m2;

	int hours;

	int minutes;

	while(1){

		scanf("%d %d %d %d", &h1 ,&m1 ,&h2 ,&m2 );

		if ( h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0 )
			break;

		printf("%d\n",time(h1, h2, m1, m2));

	}

	return 0;
}