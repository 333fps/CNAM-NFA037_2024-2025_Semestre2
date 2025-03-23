#include <stdio.h>

int main( void )
{
	int i;
	int T[5] = { 0 };
	FILE* fic = NULL;

	fic = fopen( "Exercice09.txt", "r+" );
	if ( fic != NULL )
	{
		for ( i = 0; i < 5; i++ )
		{
			(void)fscanf( fic, "%d ", &T[i] );
		}
		fclose( fic );
	}
	else
	{
		printf( "Ouverture impossible\n" );
	}

	for ( i = 0; i < 5; i++ )
	{
		printf( "%d ", T[i] );
	}

	return 0;
}
