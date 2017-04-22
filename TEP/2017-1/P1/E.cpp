#include <iostream>
#include <map>

using namespace std;

int main(){

  string t;

  cin >> t;

  int c = 0;

  int comando = 1;



  while(c < t.size()){

    if ( t[c] == '\0' )
      return 0;

    if ( t[c] == 'o' ){

      printf("Comando %d: (ox)", comando++);

      int contador = 0;

      while( t[c] == 'o' ){
        c+=2;
        contador++;
      }

      // c--;

      printf("%d\n", contador);
    }else if ( t[c] == 'x' ){

      printf("Comando %d: (x)", comando++);

      int contador = 0;
      while( t[c] == 'x' ){
        c++;
        contador++;
      }

      // c--;

      printf("%d\n", contador);
    }else if ( t[c] == '.' ){

      int contador = 0;
      printf("Comando %d: (.)", comando++);
      string x = "";
      while(t[++c] != '.'){
        contador++;
        x += t[c];
// printf("k\n");
      };
      c++;
      printf("[%s]\n", x.c_str());
    }
  }

  return 0;
}
