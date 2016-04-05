#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int visited[MAX];

int inverse(int a){

	int n = a;

	int reverse = 0;

	while( n % 10 == 0 )
		n = n/10;

	while(n != 0) {
        int remainder = n%10;
        reverse = reverse*10 + remainder;
        n/=10;
    }

    return reverse;
}

int bfs( pair<int,int> a, int b ){

	queue < pair<int,int> > q;

	q.push(a);

	while ( !q.empty() ){

		// printf("visited %d\n", q.front().first);

		visited[q.front().first] = 1;

		if ( q.front().first + 1 == b || inverse(q.front().first) == b )
			return q.front().second + 1;

		if ( !visited[q.front().first+1] )
			q.push(make_pair( q.front().first +1, q.front().second + 1));
		

		if ( !visited[inverse(q.front().first)] )
			q.push(make_pair( inverse(q.front().first), q.front().second + 1));

		q.pop();
	}

}

int main(){

	int t;

	int a,b;

	scanf("%d", &t);

	while(t--){

		scanf("%d %d", &a, &b);

		memset(visited,0,sizeof visited);	

		printf("%d\n", bfs(make_pair(a,0), b));

	}
	
	return 0
	;
}