#include <stdio.h>
#include <stdlib.h>

void Modif( float T[], int n );
void Affiche( float T[], int n );

int main( void )
{
	int n;
	float* Tab;
	int err;

	printf( "Combien de réels contiendra le tableau ?\n" );
	err = scanf( "%d", &n );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	Tab = (float*)malloc( (size_t)n * sizeof( float ) );
	if ( Tab == NULL )
	{
		printf( "Erreur d'allocation\n" );
		return 1;
	}

	Modif( Tab, n );
	Affiche( Tab, n );

	return 0;
}

void Affiche( float T[], int n )
{
	int i;

	for ( i = 0; i < n; ++i )
	{
		printf( "%f\n", (double)T[i] );
	}
}

void Modif( float T[], int n )
{
	int i;
	int err;

	for ( i = 0; i < n; ++i )
	{
		printf( "Entrez un réel: " );
		err = scanf( "%f", &T[i] );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return;
		}
	}
}
