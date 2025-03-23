#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "Exercice20.txt"

#define MAX_MOT 50
#define MAX_LIGNE 1000

int rechercheMot( FILE* fichier, const char* mot );

int main( void )
{
	FILE* fichier = NULL;
	char mot[MAX_MOT] = { 0 };

	printf( "Entrez un mot à rechercher: " );
	if ( scanf( "%49s", mot ) != 1 )
	{
		printf( "Erreur lors de la saisie du mot.\n" );
		return EXIT_FAILURE;
	}

	fichier = fopen( FILENAME, "r" );
	if ( fichier == NULL )
	{
		printf( "Impossible d'ouvrir le fichier %s.\n", FILENAME );
		return EXIT_FAILURE;
	}

	if ( rechercheMot( fichier, mot ) )
	{
		printf( "Mot present\n" );
	}
	else
	{
		printf( "Mot absent\n" );
	}

	fclose( fichier );

	return EXIT_SUCCESS;
}

int rechercheMot( FILE* fichier, const char* mot )
{
	char ligne[MAX_LIGNE];
	char* position;
	int longueurMot = (int)strlen( mot );

	while ( fgets( ligne, MAX_LIGNE, fichier ) != NULL )
	{
		position = ligne;

		while ( ( position = strstr( position, mot ) ) != NULL )
		{
			if ( ( position == ligne || !isalpha( *( position - 1 ) ) ) &&
				 ( !isalpha( *( position + longueurMot ) ) || *( position + longueurMot ) == '\0' ) )
			{
				return EXIT_FAILURE;
			}
			position++;
		}
	}

	return EXIT_SUCCESS;
}
