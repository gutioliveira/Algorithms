#include <bits/stdc++.h>

using namespace std;

using dd = pair<double,double>;

map <string, dd> rosa_ventos;

void distance(dd *treasure, int peso, string dir){

	(*treasure).first = (*treasure).first + ( peso * rosa_ventos[dir].first );
	(*treasure).second = (*treasure).second + ( peso * rosa_ventos[dir].second );
}

int main(){

	rosa_ventos["N"] = dd(0.0, 1.0);
	rosa_ventos["NE"] = dd(sqrt(2)/2, sqrt(2)/2);
	rosa_ventos["E"] = dd(1.0, 0.0);
	rosa_ventos["SE"] = dd(sqrt(2)/2, -sqrt(2)/2);
	rosa_ventos["S"] = dd(0.0, -1.0);
	rosa_ventos["SW"] = dd(-sqrt(2)/2, -sqrt(2)/2);
	rosa_ventos["W"] = dd(-1.0, 0.0);
	rosa_ventos["NW"] = dd(-sqrt(2)/2, sqrt(2)/2);

	char input[210];

	int peso;
	string teste;

	int test = 1;

	dd treasure = dd(0.0, 0.0);

	while ( scanf("%s", input) and strcmp(input, "END") ){

		char *token = strtok(input, ",.");

		while( token != NULL ){

			peso = atoi(token);

			if ( strstr(token, "NE") != NULL )
				distance(&treasure, peso, "NE");
			else if ( strstr(token, "SE") != NULL )
				distance(&treasure, peso, "SE");
			else if ( strstr(token, "SW") != NULL )
				distance(&treasure, peso, "SW");
			else if ( strstr(token, "NW") != NULL )
				distance(&treasure, peso, "NW");
			else if ( strstr(token, "N") != NULL )
				distance(&treasure, peso, "N");
			else if ( strstr(token, "S") != NULL )
				distance(&treasure, peso, "S");
			else if ( strstr(token, "W") != NULL )
				distance(&treasure, peso, "W");
			else if ( strstr(token, "E") != NULL )
				distance(&treasure, peso, "E");

			token = strtok(NULL, ",.");
		}

		printf("Map #%d\n", test++);
		printf("The treasure is located at (%.3lf,%.3lf).\n", treasure.first, treasure.second);
		printf("The distance to the treasure is %.3lf.\n\n", hypot(treasure.first, treasure.second));

		treasure = dd(0.0,0.0);
	}

	// while( getline(cin, token, ',') ){

	// 	cout << token << endl;

	// 	istringstream s(token);
		
	// 	while ( s >> peso >> teste ){

	// 		if ( teste == "END" )
	// 			return 0;

	// 		if ( teste[teste.size() - 1] == '.' ){

	// 			teste.pop_back();

	// 			distance(&treasure, peso, teste);

	// 			printf("Map #%d\n", test++);
	// 			printf("The treasure is located at (%.3lf,%.3lf).\n", treasure.first, treasure.second);
	// 			printf("The distance to the treasure is %.3lf.\n", 0.0);

	// 			treasure = dd(0.0,0.0);
	// 		}

	// 		distance(&treasure, peso, teste);
	// 	}
	// }

	return 0;
}