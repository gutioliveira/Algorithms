#include <bits/stdc++.h>

using namespace std;

char horas[4];

char minutos[6];

int muda_minutos(int minuto){

	minutos[0] = ' ';minutos[1] = ' ';minutos[2] = ' ';minutos[3] = ' ';minutos[4] = ' ';minutos[5] = ' ';

	if ( minuto >= 32 ){

		minuto = minuto - 32;

		minutos[0] = 'o';
	}

	if ( minuto >= 16 ){

		minuto = minuto - 16;

		minutos[1] = 'o';
	}

	if ( minuto >= 8 ){

		minuto = minuto - 8;

		minutos[2] = 'o';
	}

	if ( minuto >= 4 ){

		minuto = minuto - 4;

		minutos[3] = 'o';
	}

	if ( minuto >= 2 ){

		minuto = minuto - 2;

		minutos[4] = 'o';
	}

	if ( minuto >= 1 ){

		minuto = minuto - 1;

		minutos[5] = 'o';
	}

}

int muda_horas(int hora){

	horas[0] = ' ';
	horas[1] = ' ';
	horas[2] = ' ';
	horas[3] = ' ';

	if ( hora >= 8 ){

		hora = hora - 8;

		horas[0] = 'o';
	}

	if ( hora >= 4 ){

		hora = hora - 4;

		horas[1] = 'o';
	}

	if ( hora >= 2 ){

		hora = hora - 2;

		horas[2] = 'o';
	}

	if ( hora >= 1 ){

		horas[3] = 'o';
	}

}

int main(){

	int hora;

	int minuto;

	char roubo;

	while ( scanf("%d %c %d", &hora, &roubo , &minuto) != EOF ){

		muda_horas(hora);
		muda_minutos(minuto);

		// printf("%d\n", hora);

		printf(" ____________________________________________\n");
		printf("|                                            |\n");
		printf("|    ____________________________________    |_\n");
		printf("|   |                                    |   ");
		printf("|_)\n");
		printf("|   |   8         4         2         1  |   |\n");
		printf("|   |                                    |   |\n");
		printf("|   |   %c         %c         %c         %c  |   |\n", horas[0], horas[1], horas[2], horas[3]);
		printf("|   |                                    |   |\n");
		printf("|   |                                    |   |\n");
		printf("|   |   %c     %c     %c     %c     %c     %c  |   |\n", minutos[0],minutos[1],minutos[2],minutos[3],minutos[4],minutos[5]);
		printf("|   |                                    |   |\n");
		printf("|   |   32    16    8     4     2     1  |   |_\n");
		printf("|   |____________________________________|   ");
		printf("|_)\n");
		printf("|                                            |\n");
		printf("|____________________________________________|\n\n");

	}

	return 0;
}