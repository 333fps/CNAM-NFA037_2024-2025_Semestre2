#include <stdio.h>

int main( void )
{
	int codeSecret = 4700;
	int codeUtilisateur;
	int montantAretirer;
	int err;

	printf( "Saisir le code secret : " );
	err = scanf( "%d", &codeUtilisateur );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
	}

	while ( codeSecret != codeUtilisateur )
	{
		printf( "Le code est incorrect\n" );
		printf( "Saisir le code secret : " );
		err = scanf( "%d", &codeUtilisateur );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
		}
	}

	printf( "Le code est correct\n" );
	printf( "Saisir le montant à retirer : " );
	err = scanf( "%d", &montantAretirer );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
	}
	{
		printf( "Vous souhaitez retirer %d euros. Tiens voilà tes %d dollars.\n", montantAretirer, montantAretirer );
	}

	return 0;
}
