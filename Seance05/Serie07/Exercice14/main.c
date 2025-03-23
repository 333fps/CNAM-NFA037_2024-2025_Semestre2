#include <stdio.h>
#include <stdlib.h>

int fibonacci( int n );

int main( void )
{
	int n;
	int err;

	printf( "Entrez un entier: " );
	err = scanf( "%d", &n );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Nombre de couples de lapins après %d mois: %d\n", n, fibonacci( n ) );

	return EXIT_SUCCESS;
}

int fibonacci( int n )
{
	int fib_prev = 0;
	int fib_curr = 1;
	int fib_next;

	if ( n == 0 )
	{
		return EXIT_SUCCESS;
	}
	else if ( n == 1 )
	{
		return EXIT_FAILURE;
	}

	{
		int i;
		for ( i = 2; i <= n; i++ )
		{
			fib_next = fib_prev + fib_curr;
			fib_prev = fib_curr;
			fib_curr = fib_next;
		}
	}

	return fib_curr;
}
