#include <stdio.h>

int main( void )
{
	int i;
	float f;
	FILE* fic = NULL;

	fic = fopen( "Exercice08.txt", "r+" );
	if ( fic != NULL )
	{
		for ( i = 0; i < 3; i++ )
		{
			printf( "Reel numero %d : ", ( i + 1 ) );
			(void)fscanf( fic, "%f ", &f );
			printf( "%.2f \n", (double)f );
		}
		fclose( fic );
	}
	else
		printf( "Ouverture impossible\n" );

	return 0;
}
