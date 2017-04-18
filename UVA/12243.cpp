#include <iostream>
#include <sstream>

using namespace std;

int main(){

	string line, l;

	while ( getline(cin, line), line != "*" ){

		istringstream s(line);

		bool t = true;

		char f = (char) tolower(line[0]);

		while ( s >> l ){

			if ( (char) tolower(l[0]) != f ){
				
				t = false;
			}
		}

		printf("%s\n", t ? "Y" : "N");
	}

	return 0;
}