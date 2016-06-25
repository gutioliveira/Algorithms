#include <bits/stdc++.h>
using namespace std;

#define MAX 1001
#define ull unsigned long long
ull U[MAX][MAX];
bool visited[MAX][MAX];
ull primes[7];
ull groups[7];

ull search(ull N, ull i, ull j, ull prime) {
	visited[i][j] = true;
	ull ans = 1;
	if(i>0) { // cima
		if(not visited[i-1][j] && U[i][j]%prime == U[i-1][j]%prime)
			ans += search(N,i-1,j,prime);
	}
	if(i<N-1) { // baixo
		if(not visited[i+1][j] && U[i][j]%prime == U[i+1][j]%prime)
			ans += search(N,i+1,j,prime);
	}
	if(j>0) { // esquerda
		if(not visited[i][j-1] && U[i][j]%prime == U[i][j-1]%prime)
			ans += search(N,i,j-1,prime);
	}
	if(j<N-1) { // direita
		if(not visited[i][j+1] && U[i][j]%prime == U[i][j+1]%prime)
			ans += search(N,i,j+1,prime);
	}
	return ans;
}

ull find_groups(ull N, ull prime) {
	for(ull i=0; i<N; i++)
		for(ull j=0; j<N; j++)
			visited[i][j] = false;
	
	ull count = 0;
	for(ull i=0; i<N; i++)
		for(ull j=0; j<N; j++)
			if(not visited[i][j])
				if(search(N,i,j,prime) > 1)
					count++;

	return count;
}

ull best_prime() {
	ull best=0;
	for(ull i=1; i<7; i++)
		if(groups[i] > groups[best])
			best = i;
	
	for(ull i=0; i<7; i++)
		if(groups[i] == groups[best] && primes[i] < primes[best])
			best = i;
		
	return best;	
}

int main() {
	ull N;
	cin >> N;
	for(ull i=0; i<N; i++)
		for(ull j=0; j<N; j++)
			cin >> U[i][j];
	
	for(ull i=0; i<7; i++) {
		if(scanf("%llu", &primes[i]) != 1) {
			if(i>0) primes[i] = primes[i-1];
			else primes[i] = 97;
		}
	}
	
	for(ull i=0; i<7; i++)
		groups[i] = find_groups(N, primes[i]);
	
	ull idx = best_prime();
	cout << primes[idx] << " " << groups[idx] << endl;
	
	return 0;
}

