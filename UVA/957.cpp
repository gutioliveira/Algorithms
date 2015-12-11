#include <bits/stdc++.h>
using namespace std;

int main(){

	int Y;

	while( cin >> Y ){

		int P;

		cin >> P;

		vector<int> Ps;

		int a;

		while(P--){

			cin >> a;
			Ps.push_back(a);
		}
		
		int be=0, en=0, numP=0, begin = 0;

		for( int end = 0; end < Ps.size(); end++ ){

			while( Ps[end] - Ps[begin] >= Y ) 
				begin++;

			if( end - begin + 1 > numP ){
				
				numP = end - begin + 1;
				be = Ps[begin];
				en = Ps[end];
			}
		}
		
		cout << numP << " " << be << " " << en << endl;
	}

	return 0;
}
