#include <bits/stdc++.h>
#define pi 3.141592653589793
using namespace std;

using dd = pair<double,double>;

void rotate(dd *direction, double angle){

	auto x = cos(angle) * (*direction).first - sin(angle) * (*direction).second;
    auto y = sin(angle) * (*direction).first + cos(angle) * (*direction).second;

    (*direction).first = x;
    (*direction).second = y;
}

int main(){

	int t, n;

	scanf("%d", &t);

	string comando;
	int argumento;

	while(t--){

		dd direction = dd(1.0,0.0);
		dd position = dd(0.0,0.0);

		scanf("%d", &n);

		while(n--){

			cin >> comando >> argumento;

			if ( comando == "lt" ){

				double radians = pi * (double) ( argumento % 360 ) / 180.0;
				rotate(&direction, radians);
			}else if ( comando == "rt" ){

				double radians = pi * (double) ( argumento % 360 ) / 180.0;
				rotate(&direction, -radians);	
			}else if ( comando == "fd" ){

				position.first = position.first + ( direction.first * argumento );
				position.second = position.second + ( direction.second * argumento );

			}else if ( comando == "bk" ){

				position.first = position.first - ( direction.first * argumento );
				position.second = position.second - ( direction.second * argumento );
			}
		}

		printf("%d\n", (int) (hypot(position.first, position.second) + 0.5) );

		direction = dd(1.0,0.0);
		position = dd(0.0,0.0);
	}
	return 0;
}