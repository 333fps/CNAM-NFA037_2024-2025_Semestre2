#include <stdio.h>

int main( void )
{
	int err;
	double Pi;
	double rayonDuCercle;

	Pi = 3.14159;

	printf( "Entrez le rayon du cercle : " );

	err = scanf( "%lf", &rayonDuCercle );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Le périmètre du cercle est : %f\n", 2. * Pi * rayonDuCercle );

	return 0;
}
