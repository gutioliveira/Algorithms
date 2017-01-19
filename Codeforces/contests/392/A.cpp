#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){

	int n, aux;

	cin >> n;

	int soma = 0;

	vector < int > v;

	for ( int i = 0; i < n; i++ ){

		cin >> aux;

		v.push_back(aux);

		soma = max(soma, aux);
	}

	int total = 0;

	for ( int i = 0; i < n; i++ ){

		total += soma - v[i];
	}

	cout << total << endl;

	return 0;
}