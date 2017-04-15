#include <iostream>

using namespace std;

int main(){

	string a;

	cin >> a;

	char k[] = {'h', 'e', 'l', 'l', 'o'};

	int j = 0;

	for ( int i = 0; i < a.size(); i++ ){

		if ( j == 5 ){

			cout << "YES\n";
			return 0;
		}

		if ( a[i] == k[j] ){

			j++;
		}
	}

	if ( j == 5 )
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}