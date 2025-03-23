#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int A1 = 4;
	int A2;
	A2 = ( ++A1 + 2 );
	printf( "A1 = %d, A2 = %d\n", A1, A2 );
	A1 = A2++ + 1;
	printf( "A1 = %d, A2 = %d\n", A1, A2 );

	return EXIT_SUCCESS;
}
