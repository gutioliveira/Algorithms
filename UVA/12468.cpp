#include <bits/stdc++.h>

using namespace std;

int retorna(int c, int b){

    int sobe = 0;
    int desce = 0;

    int c_aux = c;
    int b_aux = c;

    while( c_aux != b ){

        c_aux++;

        sobe++;

        if ( c_aux >= 100 )
            c_aux = 0;

    }

    while( b_aux != b ){

        b_aux--;

        desce++;

        if ( b_aux < 0 )
            b_aux = 99;

    }

    return min(desce, sobe);



}

int main(){

    int channel;

    int to_be;

    while(1){

        scanf("%d %d", &channel, &to_be);

        if ( channel == -1 && to_be == -1 )
            break;

        printf("%d\n", retorna(channel, to_be)  );
    }

    return 0;
}