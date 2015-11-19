#include <bits/stdc++.h>
#define MAX 1300
using namespace std;
 
const double EPS = 0.0000001;
 
bool AreSame(double a, double b)
{
    return fabs(a - b) < EPS;
}
 
int main(){
 
    int contador = 0;
 
    int N, A;
 
    vector < int > numeros;
 
    int aux;
 
    float altura;
 
    float rangemin, rangemax;
 
    float altura1;
 
    float alturautilizavel;
 
    float altura_inicial;
 
    float soma = 0;
 
    float soma_first = 0;
 
    string s;
 
 
 
    while ( scanf("%d %d", &N , &A) ){
 
        cin.ignore();
 
        if ( N == 0 && A == 0 )
            break;
 
        soma = 0;
 
        getline(cin, s);
 
        std::stringstream ss(s);
        std::istream_iterator<int> begin(ss);
        std::istream_iterator<int> end;
        vector < int > numeros(begin, end);
 
        //std::vector<std::string> vstrings(begin, end);
        // printf("altura inicial %f\n", altura);
 
        // soma para ver se dá igual a área sem nenhum corte.
 
 
 
        sort(numeros.begin() , numeros.end() , greater<int>());
 
        altura_inicial = numeros[0];
 
        altura = altura_inicial/2;
 
        rangemin = altura;
 
        rangemax = altura;
 
        for ( int i = 0 ; i < N ; i++ )
            soma = soma + numeros[i];
 
        if ( A == 0 )
            printf("%.4f\n", altura_inicial );
        else if ( AreSame(A, soma) )
            printf(":D\n");
        else if ( A > soma )
            printf("-.-\n");
        else{ // faz a busca binária
 
            while ( 1 ){
 
//printf("entrou\n");
 
                soma = 0;
 
                for ( int i = 0 ; i < N ; i++ ){
 
                    if ( numeros[i] <= altura )
                        break;
 
                    float parcial = numeros[i] - altura;
                    if ( parcial > 0 )
                        soma = soma + parcial;
    // printf("%f\n", soma);
                }
 
                if ( AreSame(soma, A) ){
                    // printf("achou!\n");
                    printf("%.4f\n", altura );
                    break;
                }else if ( soma > A ){
 
                    if ( rangemin == rangemax ){
 
                        rangemax = rangemin + rangemin/2;
                    }else{
 
                        rangemin = (rangemin + rangemax)/2;
                    }
 
                    altura = (rangemin + rangemax)/2;
 
                    // printf("alturamin = %.4f\n", altura);
 
                }else if ( soma < A ){
 
                    if ( rangemin == rangemax ){
 
                        rangemin = rangemin - rangemin/2;
                    }else{
 
                        rangemax = (rangemin + rangemax)/2;
                    }
 
                    altura = (rangemin + rangemax)/2;
 
                    // printf("alturamax = %.4f\n", altura);
                }
 
                contador++;
 
                // contador++;
 
 
// printf("soma = %f\n", soma);
 
            }
 
        }
 
        contador = 0;
        altura_inicial = 0;
        numeros.clear();
    }
 
 
    return 0;
}