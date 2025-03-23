#include <stdio.h>

int main( void )
{
	FILE* file = NULL;
	int c;

	file = fopen( "Exercice10.txt", "r" );
	if ( file != NULL )
	{
		while ( ( c = fgetc( file ) ) != EOF )
		{
			printf( "%c", c );
		}

		fclose( file );
	}
	else
	{
		printf( "Ouverture impossible\n" );
	}

	return 0;
}
