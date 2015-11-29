#include <bits/stdc++.h>

using namespace std;

int top = 0;
int right2 = 0;
int up2 = 0;
int left2 = 0;
int down = 0;
int down2 = 0;

void south(int t, int u, int d){

    top = u;

    up2 = down2;

    down = t;

    down2 = d;
}

void north(int t, int u , int d){

    top = d;

    up2 = t;

    down = down2;

    down2 = u;
}

void west(int t, int l, int r){

    top = r;

    right2 = down2;

    left2 = t;

    down2 = l;

}

void east(int t, int r, int l){

    top = l;

    left2 = down2;

    right2 = t;

    down2 = r;

}

int main(){

    int teste;

    top = 1;

    string comando;

    while(1){

        top = 1;
        right2 = 4;
        up2 = 2;
        left2 = 3;
        down = 5;
        down2 = 6;

        scanf("%d", &teste);

        if ( teste == 0 )
            break;

        for ( int i = 0 ; i < teste ; i++ ){

            cin >> comando;

            if ( comando == "north" )
                    north(top, up2, down);
             
            if ( comando == "east" )
                    east(top, right2 , left2);

            if ( comando == "west" )
                    west(top, left2 , right2);

            if ( comando == "south" )
                    south(top,up2, down);

        }

        printf("%d\n", top );





    }

    return 0;
}