#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

using ll = long long;

class Point {
public:
    ll x;
    ll y;

    Point(ll xv = 0, ll yv = 0) : x(xv), y(yv) {}

    bool operator<(const Point& P) const
    {
        return x == P.x ? y < P.y : x < P.x;
    }

    bool operator==(const Point& P) const{

    	return x == P.x and y == P.y;
    }
};

ll D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

vector<Point> monotone_chain_ch(vector<Point>& P)
{
    sort(P.begin(), P.end());

    vector<Point> L, U;

    for (auto p : P)
    {
        while (L.size() >= 2 and D(L[L.size() - 2], L[L.size() -1], p) < 0)
            L.pop_back();

        L.push_back(p);
    }

    reverse(P.begin(), P.end());

    for (auto p : P)
    {
        while (U.size() >= 2 and D(U[U.size() - 2], U[U.size() -1], p) < 0)
            U.pop_back();

        U.push_back(p);
    }

    L.pop_back();

    return U;
}


int main(){

	int n;

	int teste = 1;

	bool pula = false;

	while( scanf("%d", &n) != EOF ){

		if ( pula )
			printf("\n");

		pula = true;

		int x,y;

		vector < Point > v;

		map <Point, int> mapa;

		for ( int i = 0; i < n; i++ ){

			scanf("%d %d", &x, &y);

			v.push_back(Point(x,y));

			mapa[Point(x,y)] = i+1;
		}

		printf("Caso %d:\n", teste++);

		vector<Point> mono = monotone_chain_ch(v);
		reverse(mono.begin(), mono.end());

		for ( int i = 0; i < mono.size(); i++ ){
			printf("%d", mapa[mono[i]]);

			if ( i <= mono.size() - 2 )
				printf(" ");
		}

		printf("\n");
	}

	return 0;
}