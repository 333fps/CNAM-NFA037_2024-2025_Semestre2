#include <stdio.h>
#include <string.h>

#define MAX_NOM 10

int main( void )
{
	char prenom[MAX_NOM];
	int err;
	size_t longueur;

	printf( "Entrez votre prénom (max %d caractères) : ", MAX_NOM - 1 );

	err = scanf( "%9s", prenom );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	longueur = strlen( prenom );
	printf( "Votre prénom '%s' contient %u caractères.\n", prenom, (unsigned int)longueur );

	return 0;
}
