#include <stdio.h>

int main(){

    double a,b;

    char nome[90];

    double c;

    scanf("%s", nome);
    scanf("%lf", &a);
    scanf("%lf", &b);

    printf("TOTAL = R$ %.2f\n", a+b*0.15);


    return 0;
}
1