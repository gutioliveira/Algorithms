#include <iostream>
#include <map>
#include <cstring>

using namespace std;

bool isv(char x){

	if ( x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u' or x == 'y' )
		return true;
	return false;
}

int main(){

	string str;

	while ( getline(cin, str), str != "e/o/i" ){

		char s[205];

		int wrong = 0;

		for ( int i = 0; i < str.size(); i++ )
			s[i] = str[i];
		s[str.size()] = '\0';

		char *l1 = strtok(s, "/");
		char *l2 = strtok(NULL, "/");
		char *l3 = strtok(NULL, "\0");

		int aux = 0;
		bool last = false;

		for ( int i = 0; i < strlen(l1); i++ ){

			if ( isv(l1[i]) ){

				if ( last == false ){

					aux++;
					last = true;
				}
			}else{

				last = false;
			}
		}

		if ( aux != 5 ){

			printf("1\n");
			continue;
		}

		aux = 0;

		last = false;

		for ( int i = 0; i < strlen(l2); i++ ){

			if ( isv(l2[i]) ){

				if ( last == false ){

					aux++;
					last = true;
				}
			}else{

				last = false;
			}
		}

		if ( aux != 7 ){

			printf("2\n");
			continue;
		}

		aux = 0;
		last = false;

		for ( int i = 0; i < strlen(l3); i++ ){

			if ( isv(l3[i]) ){

				if ( last == false ){

					aux++;
					last = true;
				}
			}else{

				last = false;
			}
		}

		if ( aux != 5 ){

			printf("3\n");
			continue;
		}

		printf("Y\n");
	}

	return 0;
}