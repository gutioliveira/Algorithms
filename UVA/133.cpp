#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, k, m;

	while(cin >> N >> k >> m, N && k && m){

		vector<int> app;

		for( int i = 0; i < N ; i++ ) 
			app.push_back(i+1);

		int count = 0, cw = N-1, ccw = 0;

		while( count != N ){

			int ks = k;

			while(ks){

				cw = ( cw + 1 ) % N;

				if( app[cw] != -1 )	
					ks--;

			}

			int ms = m;

			while(ms){

				ccw = ( N + ccw - 1 ) % N;

				if( app[ccw] != -1 )	
					ms--;

			}
			
			if( ccw != cw ){

				printf("%3d%3d", app[cw], app[ccw]);

				count += 2;
				app[ccw] = -1;
				app[cw] = -1;

			}else{

				printf("%3d", app[cw]);
				count++;
				app[cw] = -1;
			}
			
			if(count < N) 
				cout << ",";

		}

		cout << endl;
		
	}
	
	return 0;
}
