#include <bits/stdc++.h>

using namespace std;

int main(){

	int a,b,c;

	vector<int> padrao;
	vector<int> ordenado;

	scanf("%d %d %d", &a, &b, &c);

	padrao.push_back(a);
	padrao.push_back(b);
	padrao.push_back(c);

	ordenado = padrao;

	sort(ordenado.begin(), ordenado.end());

	for ( int i = 0; i < 3 ; i++ )
		printf("%d\n", ordenado[i]);

	printf("\n");

	for ( int i = 0; i < 3 ; i++ )
		printf("%d\n", padrao[i]);


	return 0;
}