#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    
    scanf("%d", &n);
    
    string nome;
    
    while(n--){
    
        cin >> nome;
        
        if ( nome == "grafo" )
            cout << "Certo" << endl;
        else if ( nome == "grafico" )
            cout << "Haja paciencia...\n";
        else
            cout << "Errado\n";
    }
    
    
    
    return 0;
}
