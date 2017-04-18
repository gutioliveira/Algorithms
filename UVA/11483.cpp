#include <iostream>

using namespace std;

int main(){

	int n;

	int t = 1;

	while( scanf("%d", &n), n ){

		string line;

		printf("Case %d:\n", t++);
		printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");

		cin.ignore();

	// printf("%d\n", n);

		for ( int i = 0; i < n; i++ ){

			printf("printf(\"");

			getline(cin, line);

			for ( int j = 0; j < line.size(); j++ ){
				if ( line[j] == '"' or line[j] == '\\' ){

					printf("\\");
				}

				printf("%c", line[j]);
			}

			printf("\\n\");\n");
		}
		printf("printf(\"\\n\");\nreturn 0;\n}\n");
	}

	return 0;
}