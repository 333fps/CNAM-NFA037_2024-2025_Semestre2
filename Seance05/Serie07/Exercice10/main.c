#include <stdio.h>
#include <stdlib.h>

int somme( int TabEntiers[], int indice, int n );

int main( void )
{
	int n, i;
	int* TabEntiers;

	printf( "Saisir n, le nb d'entiers dans le tableau :\n" );

	if ( scanf( "%d", &n ) != 1 || n <= 0 )
	{
		printf( "Erreur: nombre invalide\n" );
		return 1;
	}

	TabEntiers = (int*)malloc( (size_t)n * sizeof( int ) );

	if ( TabEntiers == NULL )
	{
		printf( "Erreur d'allocation mémoire\n" );
		return 1;
	}

	for ( i = 0; i < n; i++ )
	{
		printf( "Saisir un entier du tableau :\n" );
		(void)scanf( "%d", &TabEntiers[i] );
	}

	printf( "Somme des éléments du tableau: %d\n", somme( TabEntiers, 0, n ) );

	return 0;
}

int somme( int TabEntiers[], int indice, int n )
{
	if ( indice == ( n - 1 ) )
	{
		return TabEntiers[n - 1];
	}
	else
	{
		return TabEntiers[indice] + somme( TabEntiers, indice + 1, n );
	}
}
