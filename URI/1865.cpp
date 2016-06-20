#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    string a;
    int b;
    int t;
    
    scanf("%d", &t);
    
    while(t--){
        
        cin >> a >> b;
        
        if ( a == "Thor" )
            printf("Y\n");
        else
            printf("N\n");
    }
 
    return 0;
}