#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using edge = pair<int, ii>;

int main(){

	int n,m;

	while( scanf("%d %d", &n, &m) , n | m ){

		priority_queue<edge> pq;
		int total = 0;
		while(n--){

			int x,y,z;

			scanf("%d %d %d", &x, &y, &z);
			total += z;
			pq.push(edge(-z, ii(x,y)));
		}

	}


	return 0;
}