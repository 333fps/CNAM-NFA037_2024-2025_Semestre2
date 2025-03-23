#include <stdio.h>

int main( void )
{
	int Tableau[4][3] =
		{
			/* num, age, sexe */
			{ 455, 12, 1 },
			{ 1234, 16, 2 },
			{ 856, 26, 2 },
			{ 256, 23, 1 },
		};

	size_t i = 0;
	int ageMaxi = Tableau[i][1];
	size_t indexAgeMaxi = 0;

	printf( "Numero\t Age\t Sexe\n" );
	for ( i = 0; i < 4; ++i )
	{
		printf( "%d\t %d\t %d\n", Tableau[i][0], Tableau[i][1], Tableau[i][2] );

		if ( Tableau[i][1] > ageMaxi )
		{
			ageMaxi = Tableau[i][1];
			indexAgeMaxi = i;
		}
	}

	printf( "Le candidatle plus agé est le numéro %d et est âgé de %d ans.\n", Tableau[indexAgeMaxi][0], Tableau[indexAgeMaxi][1] );

	return 0;
}
