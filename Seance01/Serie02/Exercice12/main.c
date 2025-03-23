#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	double sommeEnEuro;
	double conversionYenEuro;
	int err;

	conversionYenEuro = 0.0078255407;

	printf( "Entrez une somme en euro : " );
	err = scanf( "%lf", &sommeEnEuro );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "La somme en yen est de : %.2f\n", sommeEnEuro / conversionYenEuro );

	return EXIT_SUCCESS;
}
