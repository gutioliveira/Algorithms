#include <iostream>
#include <map>

using namespace std;

int main(){

  string t;

  while ( cin >> t ){

    map < char , int > mapa;

    for ( auto s : t ){

      mapa[s]++;
    }

    bool one = true;
    bool ans = true;

    for ( auto it = mapa.begin(); it != mapa.end(); ++it ){

      if ( (*it).second % 2 == 1 ){

        if ( one )
          one = false;
        else{
          ans = false;
          break;
        }
      }
    }

    if ( ans )
      printf("Sim\n");
    else
      printf("Nao\n");
  }

  return 0;
}
