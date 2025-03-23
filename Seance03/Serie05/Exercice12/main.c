#include <stdio.h>

int main( void )
{
	int Tableau[] = { 1, 100, 200, 300, 400, 800, 1000, 1200 };

	int i;
	int numElements = sizeof( Tableau ) / sizeof( int );
	int temp;

	for ( i = 0; i < numElements / 2; ++i )
	{
		temp = Tableau[i];
		Tableau[i] = Tableau[( numElements - 1 ) - i];
		Tableau[( numElements - 1 ) - i] = temp;
	}

	for ( i = 0; i < numElements; ++i )
	{
		printf( "Tableau[%d] = %d\n", i, Tableau[i] );
	}

	return 0;
}
