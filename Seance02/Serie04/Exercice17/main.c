#include <stdio.h>

#define MIN_HAUTEUR 3

int main( void )
{
	int hauteur;
	int largeur;
	int ligne, colonne;
	int err;

	printf( "Hauteur du T (minimum %d) : ", MIN_HAUTEUR );
	err = scanf( "%d", &hauteur );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	if ( hauteur < MIN_HAUTEUR )
	{
		printf( "La hauteur doit être >= %d\n", MIN_HAUTEUR );
		return 1;
	}

	largeur = ( hauteur % 2 == 0 ) ? hauteur - 1 : hauteur;

	for ( colonne = 0; colonne < largeur; ++colonne )
	{
		printf( "*" );
	}
	printf( "\n" );

	for ( ligne = 1; ligne < hauteur; ++ligne )
	{
		for ( colonne = 0; colonne < largeur / 2; ++colonne )
		{
			printf( " " );
		}
		printf( "*\n" );
	}

	return 0;
}
