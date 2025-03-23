#include <stdio.h>

int Modif( int a );

int main( void )
{
	int a;

	printf( "Valeur de a ? : \n" );
	(void)scanf( "%d", &a );
	printf( "Valeur de a saisie : %d\n", a );
	printf( "Valeur renvoyee apres execution de la fontion Modif : %d\n", Modif( a ) );
	printf( "Valeur de a apres execution de la fonction Modif : %d\n", a );

	return 0;
}

int Modif( int a )
{
	return --a;
}
