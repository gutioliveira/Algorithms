#include <stdio.h>
#include <stdlib.h>

int main(){

    int a,b,c,d;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if ( a > b ){

        d = a;
    }else{

        d = b;
    }

    if ( d > c ){

        printf("%d eh o maior\n", d);
    }else{

        printf("%d eh o maior\n", c);
    }


}

1