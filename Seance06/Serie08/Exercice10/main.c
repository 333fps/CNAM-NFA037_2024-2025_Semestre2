#include <stdio.h>

void minmax( double* tableau, int taille, double* min, double* max );

int main( void )
{
	double tableau[5] = { 1.1, 0.2, 3.3, 34.4, 5.5 };
	double* p = tableau;

	double min = *p;
	double max = *p;

	minmax( p, 5, &min, &max );

	printf( "Min: %f\n", min );
	printf( "Max: %f\n", max );

	return 0;
}

void minmax( double* tableau, int taille, double* min, double* max )
{
	int i;
	for ( i = 0; i < taille; ++i )
	{
		if ( *( tableau + i ) < *min )
		{
			*min = *( tableau + i );
		}
		if ( *( tableau + i ) > *max )
		{
			*max = *( tableau + i );
		}
	}
}
