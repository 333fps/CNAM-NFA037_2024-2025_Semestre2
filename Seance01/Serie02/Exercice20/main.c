#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int a = 6;
	a += 2;
	a++;
	a *= 2;
	printf( "%d", a++ );
	printf( " %d", a );

	return EXIT_SUCCESS;
}
