#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int Tableau[3][2] =
		{
			{ 1, 2 },
			{ 11, 22 },
			{ 111, 222 } };

	size_t i;

	for ( i = 0; i < 3; ++i )
	{
		printf( "%d\t %d\n", Tableau[i][0], Tableau[i][1] );
	}

	return EXIT_SUCCESS;
}
