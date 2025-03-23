#include <stdio.h>

int main( void )
{
	char tableau[] = { 'a', 'e', 'i', 'o', 'u', 'y' };
	size_t i;

	for ( i = 0; i < sizeof( tableau ) / sizeof( char ); ++i )
	{
		printf( "%c\t", tableau[i] );
	}
	printf( "\n" );

	return 0;
}
