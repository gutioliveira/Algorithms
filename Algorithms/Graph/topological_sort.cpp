#include <bits/stdc++.h>

#define MAX 10005

using namespace std;

int in[MAX]; // number of vertices that are coming in. 1 -> 2 , 1 points to 2, in[1] = 0, in[2] = 1
int out[MAX]; // number of vertices that are coming out. 1 -> 2, 1 points to 2, out[1] = 1, out[2] = 0

vector <int> sorted; // graph sorted topologically

int topological_sort(int N, vector<int> v[]){ // N = number of vertices being used, v is the graph

	while ( sorted.size() != N ){ // condition can vary

		for ( int i = 1; i <= N; i++ ){

			if ( in[i] == 0 ){

				sorted.push_back(i);
				in[i] = -1; // flag that this vertex is not used anymore

				for ( int j = 0; j < out[i]; j++ ){

					in[v[i][j]]--; // clear the vertices who were being pointed.
				}

				break;
			}
		}
	}
}

int main(){

	vector<int> v[MAX];

	in[1] = 0;
	v[1].push_back(2);
	in[2] = 1;
	v[1].push_back(3);

	out[1] = 2;
	v[2].push_back(3);

	out[2] = 1;

	in[3] = 2;
	v[3].push_back(4);

	out[3] = 1;

	in[4] = 1;
	out[4] = 0;

	topological_sort(4, v);

	for ( auto i : sorted )
		cout << i << endl;

	return 0;
}