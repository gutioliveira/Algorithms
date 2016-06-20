#include <bits/stdc++.h>

using namespace std;

int main(){

	double d;

	scanf("%lf", &d);

	int cem = 0, cinquenta = 0, vinte = 0, dez = 0, cinco = 0, dois = 0;

	int um = 0, cinquenta2 = 0, vintecinco = 0, dez2 = 0, cinco2 = 0, um2 = 0; 

	if ( d >= 100.0 ){

		cem = (int) d/100;
		d = d - cem*100;
	}

	if ( d >= 50.0 ){

		cinquenta  = (int) d/50;
		d = d - cinquenta*50;
	}

	if ( d >= 20.0 ){

		vinte  = (int) d/20;
		d = d - vinte*20;
	}

	if ( d >= 10.0 ){

		dez  = (int) d/10;
		d = d - dez*10;
	}

	if ( d >= 5.0 ){

		cinco  = (int) d/5;	
		d = d - cinco*5;
	}

	if ( d >= 2.0 ){

		dois  = (int) d/2;
		d = d - dois*2;
	}

	if ( d != 0 ){

		d = d*100;

		if ( d >= 100.0 ){

			um = (int) d/100;
			d = d - um*100;
		}

		if ( d >= 50.0 ){

			cinquenta2 = (int)d/50;
			d = d - cinquenta2*50;
		}


		if ( d >= 25.0 ){

			vintecinco = (int)d/25;
			d = d - vintecinco*25;
		}

		if ( d >= 10.0 ){

			dez2 = (int)d/10;
			d = d - dez2*10;
		}

		if ( d >= 5.0 ){

			cinco2 = (int)d/5;
			d = d - cinco2*5;
		}

		if ( d >= 1.0 ){

			um2 = (int)d;
		}
	}

	printf("NOTAS:\n");
	printf("%d nota(s) de R$ 100.00\n", cem);
	printf("%d nota(s) de R$ 50.00\n", cinquenta);
	printf("%d nota(s) de R$ 20.00\n", vinte);
	printf("%d nota(s) de R$ 10.00\n", dez);
	printf("%d nota(s) de R$ 5.00\n", cinco);
	printf("%d nota(s) de R$ 2.00\n", dois);
	printf("MOEDAS:\n");
	printf("%d moeda(s) de R$ 1.00\n", um);
	printf("%d moeda(s) de R$ 0.50\n",cinquenta2);
	printf("%d moeda(s) de R$ 0.25\n",vintecinco);
	printf("%d moeda(s) de R$ 0.10\n",dez2);
	printf("%d moeda(s) de R$ 0.05\n",cinco2);
	printf("%d moeda(s) de R$ 0.01\n",um2);

	return 0;
}