#include <stdio.h>
#include <stdlib.h>

int main(){

    char p[52];
    int n , i,t,j;
    scanf("%d", &t);



    for ( j = 0 ; j < t ; j++ ){

        scanf(" %s", p);
        scanf("%d", &n);

        for (i=0; i<50; i++){

            if ( p[i] == '\0' )
                break;

            p[i] = p[i] - n;

            if ( p[i] < 65 )
                p[i] = p[i] + 26;

        }

        printf("%s\n", p);
    }
    return 0;
}

1