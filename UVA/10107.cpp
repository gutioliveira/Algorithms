#include <bits/stdc++.h>

using namespace std;

int main(){
		
	vector <int> vetor;

	int i;

	while( cin >> i ){

		vetor.push_back(i);

		sort(vetor.begin(), vetor.end());

		if ( vetor.size() % 2 == 0 )

			printf("%d\n", (vetor[vetor.size()/2-1] + vetor[vetor.size()/2])/2);
		else
			printf("%d\n", vetor[(int)vetor.size()/2]);
		
	}

	return 0;
}