#include <stdio.h>

float minNB( float, float );

int main( void )
{
	float a, b;
	int err;

	printf( "Saisir le premier réel a: " );
	err = scanf( "%f", &a );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Saisir le deuxième réel b: " );
	err = scanf( "%f", &b );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Le plus petit nombre entre %f et %f est %f\n", (double)a, (double)b, (double)minNB( a, b ) );

	return 0;
}

float minNB( float a, float b )
{
	return a < b ? a : b;
}
