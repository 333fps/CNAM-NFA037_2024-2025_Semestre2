#include <stdio.h>

int main( void )
{
	int a = 44;
	int* P = NULL;
	P = &a;
	a = 45;
	printf( " le contenu de a vaut maintenant : %d\n ", *P );
	return 0;
}
