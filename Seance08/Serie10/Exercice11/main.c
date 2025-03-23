#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define FILENAME "Exercice11.txt"

int main( void )
{
	FILE* fichier = NULL;
	char phrase[BUFFER_SIZE];

	printf( "Programme d'enregistrement de texte\n" );
	printf( "Saisir une phrase: " );
	if ( fgets( phrase, BUFFER_SIZE, stdin ) == NULL )
	{
		printf( "Erreur de lecture\n" );
		return 1;
	}

	fichier = fopen( FILENAME, "w" );
	if ( fichier == NULL )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );
		return 1;
	}

	if ( fprintf( fichier, "%s", phrase ) < 0 )
	{
		printf( "Erreur lors de l'écriture dans le fichier\n" );
		fclose( fichier );
		return 1;
	}

	fclose( fichier );
	printf( "Phrase enregistrée avec succès dans %s\n", FILENAME );

	return 0;
}
