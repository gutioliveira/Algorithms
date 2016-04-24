#include <iostream>
#include <cstdio>

using namespace std;

int ganhou = 0;

int campo[5][5];
int marcado[5][5];

void busca(int i, int j){

    if ( i == 4 && j == 4 )
        ganhou = 1;
    else{

        marcado[i][j] = 1;

        if ( i >= 0 && j <= 4 && i <= 4 && j >= 0 ){

            if ( i+1 <= 4 && campo[i+1][j] == 0 && !marcado[i+1][j] && ganhou == 0 )
                busca(i+1,j);
            if ( i-1 >= 0 && campo[i-1][j] == 0 && !marcado[i-1][j] && ganhou == 0 )
                busca(i-1,j);
            if ( j+1 <= 4 && campo[i][j+1] == 0 && !marcado[i][j+1] && ganhou == 0 )
                busca(i,j+1);
            if ( j-1 >= 0 && campo[i][j-1] == 0 && !marcado[i+1][j] && ganhou == 0 )
                busca(i,j-1);

        }
    }
}

int main(){

    int teste;

    cin >> teste;

    for ( int k = 1 ; k <= teste ; k++ ){

        for ( int i = 0 ; i < 5 ; i++ ){

            for ( int j = 0 ; j < 5 ; j++ ){

                scanf("%d", &campo[i][j]);
                marcado[i][j] = 0;
            }
        }

        busca(0,0);

        if (ganhou)
            cout << "COPS" << endl;
        else
            cout << "ROBBERS" << endl;

        ganhou = 0;

    }

}