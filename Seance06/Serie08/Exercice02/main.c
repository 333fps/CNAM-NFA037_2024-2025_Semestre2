#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int a = 44;
	int b;

	int* p = &a;
	b = *p;

	printf( "Contenu de la variableb : %d\n", b );

	return EXIT_SUCCESS;
}
