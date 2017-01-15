#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<int, int> mapa;

void printDivisors(int n)
{
    // Note that this loop runs till square root
    for (int i=2; i<=sqrt(n)+1; i++)
    {
        if (n%i==0)
        {
            // If divisors are equal, print only one
            mapa[i]++;
        }
    }
}
  
void printDivisors2(int n)
{
    set < int > s;

    for (int i=1; i<=sqrt(n)+1; i++)
    {
        if (n%i==0)
        {
        	s.insert(n/i);
        	s.insert(i);
        }
    }

    for ( auto it = s.begin(); it != s.end(); it++ ){

    	if ( (*it) != 1 )
    		mapa[(*it)]++;
    }
}

int main(){

	int n, aux;

	cin >> n;

	vector < int > v;

	while(n--){

		cin >> aux;

		// printDivisors(aux);
		printDivisors2(aux);
	}

	int m = 0;
	int key = 0;

	for ( auto it = mapa.begin(); it != mapa.end(); it++ ){

// printf("%d -> %d\n", (*it).first, (*it).second);

		if ( (*it).second > m ){

			m = (*it).second;
		}
	}

	printf("%d\n", m == 0 ? 1 : m);

	return 0;
}