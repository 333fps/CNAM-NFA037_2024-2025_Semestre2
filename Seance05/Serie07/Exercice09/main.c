#include <stdio.h>
#include <stdlib.h>

void Affiche( int TabEntiers[], int indice, int n );

int main( void )
{
	int n, i;
	int* TabEntiers;
	int indice = 0;

	printf( "Saisir n, le nb d'entiers dans le tableau :\n" );
	if ( scanf( "%d", &n ) != 1 || n <= 0 )
	{
		printf( "Erreur: nombre invalide\n" );
		return EXIT_FAILURE;
	}

	TabEntiers = (int*)malloc( (size_t)n * sizeof( int ) );
	if ( TabEntiers == NULL )
	{
		printf( "Erreur d'allocation mémoire\n" );
		return EXIT_FAILURE;
	}

	for ( i = 0; i < n; i++ )
	{
		printf( "Saisir un entier du tableau :\n" );
		(void)scanf( "%d", &TabEntiers[i] );
	}

	printf( "Affichage du tableau :\n" );
	Affiche( TabEntiers, indice, n );

	free( TabEntiers );
	return EXIT_SUCCESS;
}

void Affiche( int TabEntiers[], int indice, int n )
{
	if ( indice == ( n - 1 ) )
		printf( "%d\n", TabEntiers[n - 1] );
	else
	{
		printf( "%d ; ", TabEntiers[indice] );
		Affiche( TabEntiers, indice + 1, n );
	}
}
