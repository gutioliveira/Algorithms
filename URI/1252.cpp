#include <stdio.h>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
 
using namespace std;
 
int m = 17;
 
class Value{
 
public:
    int numero;
 
 
};
 
 bool cmp(const Value &a, const Value &b){
 
    return ( a.numero % m  < b.numero % m ) ||
    ( ( a.numero % m  == b.numero % m ) && ( a.numero > b.numero) && ( a.numero & 1 )) ||
    ( ( a.numero % m  == b.numero % m ) && ( a.numero < b.numero) && !( b.numero & 1 ));
 
 }
 
int main(){ 
 
    vector < Value > valores;
 
    Value aux;
 
    int size1 = 0;
    int size2 = 2;
    int size3 = 0;
 
    int n;
 
    while (1){
 
        scanf("%d %d", &n , &m);
 
        if ( n == 0 && m == 0)
            break;
 
        for ( int i = 0 ; i < n ; i++ ){
 
            scanf("%d", &aux.numero);
            size1++;
 
            valores.push_back(aux);
        }
 
        size2 = valores.size();
 
        size3 = size2 - size1;
 
        sort(valores.begin() + size3, valores.end() , &cmp);
 
        printf("%d %d\n", n,m);
 
        int j = 0;
 
        for ( int i = size3, j = 0 ;  j < n ; i++ , j++)
            printf("%d\n",valores[i].numero);
 
        size1 = 0;
 
    }
    printf("0 0\n");

    return 0;
}