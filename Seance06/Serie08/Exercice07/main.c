#include <stdio.h>

void Permut( int* VAR1, int* VAR2 );

int main( void )
{
	int A, B;
	printf( "Valeur de A ?" );
	(void)scanf( "%d", &A );
	printf( "Valeur de B ?" );
	(void)scanf( "%d", &B );
	Permut( &A, &B );
	printf( "A vaut : %d\n ", A );
	printf( "B vaut : %d\n ", B );

	return 0;
}

void Permut( int* VAR1, int* VAR2 )
{
	int* Tampon;
	Tampon = VAR1;
	VAR1 = VAR2;
	VAR2 = Tampon;
}
