#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	float Tableau[5];
	int err;
	size_t i;
	struct
	{
		size_t position;
		float plusPetit;
	} data;

	for ( i = 0; i < sizeof( Tableau ) / sizeof( float ); ++i )
	{
		printf( "Entrez le nombre %lu: ", (unsigned long)( i + 1 ) );
		err = scanf( "%f", &Tableau[i] );
		if ( err != 1 )
		{
			printf( "Erreur de lecture\n" );
			return EXIT_FAILURE;
		}
	}

	data.position = 0;
	data.plusPetit = Tableau[0];
	for ( i = 0; i < sizeof( Tableau ) / sizeof( float ); ++i )
	{
		if ( Tableau[i] < data.plusPetit )
		{
			data.position = i;
			data.plusPetit = Tableau[i];
		}
	}

	for ( i = 0; i < sizeof( Tableau ) / sizeof( float ); ++i )
	{
		printf( "Tableau[%lu] = %f\n", (unsigned long)i, (double)Tableau[i] );
	}

	printf( "Le plus petit nombre est %f et est situé à la position: %lu\n", (double)data.plusPetit, (unsigned long)data.position );

	return EXIT_SUCCESS;
}
