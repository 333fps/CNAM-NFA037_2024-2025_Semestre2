#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int codeUtilisateur;
	int codeSecret = 4700;
	int compteur = 0;
	int montant;
	int err;

	do
	{
		compteur++;
		printf( " %d\n Veuillez saisir votre code:", compteur );
		err = scanf( "%d", &codeUtilisateur );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
		}
	} while ( codeUtilisateur != codeSecret && compteur < 3 );

	if ( compteur >= 3 && codeUtilisateur != codeSecret )
	{
		printf( "Carte avalée\n" );
		return EXIT_SUCCESS;
	}

	printf( "Veuillez saisir le montant de votre retrait:" );
	err = scanf( "%d", &montant );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
	}
	while ( montant > 350 )
	{
		printf( "Tu ne peux pas retirer plus de 350 euros! Essaie encore !\n" );
		err = scanf( "%d", &montant );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
		}
	}
	printf( "Tiens, voilà tes %d euros\n", montant );

	return EXIT_SUCCESS;
}
