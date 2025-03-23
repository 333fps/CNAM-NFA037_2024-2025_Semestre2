#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int i = 0;

	for ( i = 0; i < 100; ++i )
	{
		printf( "%d\n", i % 10 );
	}

	return EXIT_SUCCESS;
}
