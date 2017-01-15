#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){

	string word;

	cin >> word;

	map < char, int > mapa;

	mapa['B'] = 0;
	mapa['u'] = 0;
	mapa['l'] = 0;
	mapa['b'] = 0;
	mapa['a'] = 0;
	mapa['s'] = 0;
	mapa['r'] = 0;

	for ( int i = 0; i < word.size(); i++ ){
		//B u l b a s a u r
		if ( word[i] == 'B' || word[i] == 'u' || word[i] == 'l' || word[i] == 'b' 
			|| word[i] == 'a' || word[i] == 'r' || word[i] == 's' )
			mapa[word[i]]++;
	}

	int n = -1;
	int anterior = 0;

	for ( auto it = mapa.begin(); it != mapa.end(); it++ ){

		if ( (*it).first == 'r' || (*it).first == 'l' || (*it).first == 'B' 
			|| (*it).first == 's' || (*it).first == 'b' ){

			if ( n == -1 )
				n = (*it).second;
			else
				n = min(n, ((*it).second));

		}else{

			if ( n == -1 )
				n = (*it).second/2;
			else
				n = min(n, ((*it).second)/2);
		}
	}

	printf("%d\n", n);

	return 0;
}