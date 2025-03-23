#include <stdio.h>

int main( void )
{
	float VAR1;
	float VAR2;
	float VAR3;
	int err;

	printf( "Entrez la valeur de VAR1 : " );

	err = scanf( "%f", &VAR1 );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Entrez la valeur de VAR2 : " );

	err = scanf( "%f", &VAR2 );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	VAR1 > VAR2 ? ( VAR3 = VAR1 ) : ( VAR3 = VAR2 );

	printf( "La valeur de VAR3 est : %f\n", (double)VAR3 );

	return 0;
}
