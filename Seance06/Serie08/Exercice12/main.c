#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int A = 1, B = 10, C = 100, D = 1000;
	int* T[4];
	int** P = T;

	{
		T[0] = &A;
		T[1] = &B;
		T[2] = &C;
		T[3] = &D;
	}

	{
		int i;
		for ( i = 0; i < 4; ++i )
		{
			printf( "Contenu de T[%d]: %d\n", i, *P[i] );
		}
	}
	return EXIT_SUCCESS;
}
