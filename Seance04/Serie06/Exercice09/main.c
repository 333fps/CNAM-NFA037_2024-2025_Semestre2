#include <stdio.h>

void Affiche( int T[], int n );
void Affecte( int val, int T[], int n );

int main( void )
{
	int T[5];

	Affecte( 1, T, 5 );
	Affiche( T, 5 );

	return 0;
}

void Affiche( int T[], int n )
{
	int i;

	for ( i = 0; i < n; ++i )
	{
		printf( "%d ", T[i] );
	}
	printf( "\n" );
}

void Affecte( int val, int T[], int n )
{
	int i;

	for ( i = 0; i < n; ++i )
	{
		T[i] = val;
	}
}
