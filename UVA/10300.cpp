#include <bits/stdc++.h>

using namespace std;

int main(){

	int T;

	cin >> T;

	while(T--) {

		long long f, sum = 0;

		cin >> f;

		long long a, b, c;

		while(f--) {

			cin >> a >> b >> c;

			sum += a*c;
		}
		
		cout << sum << endl;		
	}

	return 0;
}
