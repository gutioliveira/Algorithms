#include <bits/stdc++.h>
using namespace std;

int main(){

	int T;

	cin >> T;

	while(T--) {

		vector<int> numbers;
		
		int num;
		
		char c = ' ';

		while(c != '\n') {

			cin >> num;

			c = getchar();

			numbers.push_back(num);
		}		
		
		int a = 0;
		int b = 0;

		sort( numbers.begin() , numbers.end() , greater<int>() );

		for ( auto n : numbers ) {

			if( b > a ) 
				a += n;
			else 
				b += n;
		}
		
		if( a == b ) 
			cout << "YES\n";
		else 
			cout << "NO\n";
	}

	return 0;
}
