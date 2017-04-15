#include <iostream>
#include <vector>

using namespace std;

using ii = pair<int,int>;

int main(){

	string line;

	vector < string > v;

	double biggest = -1;

	while ( getline(cin, line) ){

		biggest = max( (double) line.size(), biggest);
		v.push_back(line);
	}

	bool left = true;

	for ( int i = 0; i < biggest + 2; i++ )
		printf("*");
	printf("\n");

	for ( auto i : v ){

		double l = (biggest + 2.0 - (double)i.size())/2.0;

		// cout << l << endl;

		printf("*");

		if ( l - (int) l == 0 ){
			
			for ( int j = 0; j < l - 1; j++ )
				printf(" ");
			cout << i;

			for ( int j = 0; j < l - 1; j++ )
				printf(" ");

			printf("*\n");
		}
		else{
			
			if ( left ){

				for ( int j = 0; j < l - 2; j++ )
					printf(" ");
				cout << i;

				for ( int j = 0; j < l - 1; j++ )
					printf(" ");

				printf("*\n");
				left = false;
			}else{

				for ( int j = 0; j < l - 1; j++ )
					printf(" ");
				cout << i;

				for ( int j = 0; j < l - 2; j++ )
					printf(" ");

				printf("*\n");
				left = true;
			}
		}
	}

	for ( int i = 0; i < biggest + 2; i++ )
			printf("*");
		printf("\n");

	return 0;
}