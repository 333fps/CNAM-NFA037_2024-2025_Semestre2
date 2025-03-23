#include <stdio.h>

int main( void )
{
	int a = 44;
	int b;

	int* p = &a;
	b = *p;

	printf( "Contenu de la variableb : %d\n", b );

	return 0;
}
