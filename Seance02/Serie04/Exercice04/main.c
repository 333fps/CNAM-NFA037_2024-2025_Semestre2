#include <stdio.h>

int main( void )
{
	int i;
	int j = 0;

	for ( i = 0; i <= 100; ++i )
	{
		printf( "%d-", 4 * i );
		++j;

		if ( j % 10 == 0 )
		{
			printf( "\n" );
		}
	}

	return 0;
}
