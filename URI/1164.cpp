#include <stdio.h>

int main(){

    int x;

    int s;

    int n;

    scanf("%d", &x);

    for( int i = 0 ; i < x ; i++ ){

        scanf("%d", &n);

        s = 0;

        for (int i = 1; i <= n / 2; i++){

            if (n % i == 0){

                s += i;
            }

        }

        if (s == n)
            printf("%d eh perfeito\n", n);
        else
            printf("%d nao eh perfeito\n", n);

    }

    return 0;

}
