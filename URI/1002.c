#include <stdio.h>

int main() {

    double a;
    const double pi = 3.14159;

    double r;

    scanf("%lf", &r);

    a = pi*r*r;

    printf("A=%.4f\n", a);

    return 0;
}
1