#include <bits/stdc++.h>

using namespace std;

int main(){

	double a,b,c,d,e;

	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

	double media = (( 2*a + 3*b + 4*c + 1*d )/10.0);

	double exame;

	if ( media >= 5.0 && media <= 6.9 ){

		scanf("%lf", &exame);

		printf("Media: %.1lf\n", media);
		printf("Aluno em exame.\n");
		printf("Nota do exame: %.1lf\n", exame);

		media = (media + exame)/2.0;

		if ( media >= 5.0 )
			printf("Aluno aprovado.\n");
		else
			printf("Aluno reprovado.\n");

		printf("Media final: %.1lf\n", media);
	}else if ( media > 6.9 ){
		printf("Media: %.1lf\n", media);
		printf("Aluno aprovado.\n");
	}else{
		printf("Media: %.1lf\n", media);
		printf("Aluno reprovado.\n");
	}

	return 0;
}