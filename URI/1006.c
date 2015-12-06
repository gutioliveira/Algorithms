#include <stdio.h>

int main(){

    double a,b,c,d;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &d);

    c = (a*2 + b*3 + d*5)/10;

    printf("MEDIA = %.1f\n", c);

    return 0;
}
1