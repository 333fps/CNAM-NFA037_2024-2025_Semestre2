#include <stdio.h>

int main( void )
{
	int n;
	int i;
	float f;
	FILE* fic = NULL;

	printf( "Combien de reels voulez-vous saisir ? " );
	(void)scanf( "%d", &n );

	fic = fopen( "Exercice07.txt", "a" );
	if ( fic != NULL )
	{
		for ( i = 0; i < n; i++ )
		{
			printf( "Saisir un reel : " );
			(void)scanf( "%f", &f );
			fprintf( fic, "%.2f ", (double)f );
		}
		fclose( fic );
		printf( "Nombres enregistres\n" );
	}
	else
		printf( "Ouverture impossible\n" );

	return 0;
}
