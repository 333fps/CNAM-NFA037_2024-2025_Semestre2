#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "Exercice21.txt"
#define MAX_MOT 50
#define MAX_LIGNE 1000

int compteOccurrences( FILE* fichier, const char* mot );

int main( void )
{
	FILE* fichier = NULL;
	char mot[MAX_MOT] = { 0 };
	int occurrences = 0;

	printf( "Entrez un mot a rechercher: " );
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

	occurrences = compteOccurrences( fichier, mot );

	printf( "Le mot \"%s\" apparait %d fois dans le fichier.\n", mot, occurrences );

	fclose( fichier );
	return EXIT_SUCCESS;
}

int compteOccurrences( FILE* fichier, const char* mot )
{
	char ligne[MAX_LIGNE];
	char* position;
	int compteur = 0;
	int longueurMot = (int)strlen( mot );

	rewind( fichier );

	while ( fgets( ligne, MAX_LIGNE, fichier ) != NULL )
	{
		position = ligne;

		while ( ( position = strstr( position, mot ) ) != NULL )
		{
			if ( ( position == ligne || !isalnum( *( position - 1 ) ) ) &&
				 ( !isalnum( *( position + longueurMot ) ) || *( position + longueurMot ) == '\0' ) )
			{
				compteur++;
			}
			position += 1;
		}
	}

	return compteur;
}
