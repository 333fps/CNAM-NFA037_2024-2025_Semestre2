#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int a = 44;
	int* p = &a;

	printf( "Contenu de la variable: %d\n", a );
	printf( "Adresse de la variable: %p\n", (void*)&a );
	printf( "Contenu du pointeur: %p\n", (void*)p );
	printf( "Adresse du pointeur: %p\n", (void*)&p );
	printf( "Contenu pointé par le pointeur: %d\n", *p );

	printf( "\n--- Modification via le pointeur ---\n" );
	*p = 100;
	printf( "Nouvelle valeur de la variable: %d\n", a );
	printf( "Contenu pointé par le pointeur: %d\n", *p );

	return EXIT_SUCCESS;
}
