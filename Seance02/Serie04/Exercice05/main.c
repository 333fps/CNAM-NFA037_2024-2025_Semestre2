#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int i;
	int j = 0;

	for ( i = 0; i <= 100; ++i )
	{
		printf( "%d", i );
		++j;

		if ( j <= 100 )
		{
			printf( "-" );
		}

		if ( j % 30 == 0 )
		{
			printf( "\n" );
		}
	}

	return EXIT_SUCCESS;
}
