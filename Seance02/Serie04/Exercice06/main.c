#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int i;
	for ( i = 1; i <= 10; ++i )
	{
		printf( "4*%d=%d\n", i, i * 4 );
	}

	return EXIT_SUCCESS;
}
