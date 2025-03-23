#include <stdio.h>

#define FILENAME "Exercice11bis.txt"

int main( void )
{
	FILE* fichier = NULL;
	int c;

	fichier = fopen( FILENAME, "w" );
	if ( fichier == NULL )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );
		return 1;
	}

	printf( "Programme d'enregistrement de texte\n" );
	printf( "Saisir une phrase: " );

	while ( ( c = getchar() ) != '\n' && c != EOF )
	{
		if ( fputc( c, fichier ) == EOF )
		{
			printf( "Erreur lors de l'écriture dans le fichier\n" );
			fclose( fichier );
			return 1;
		}
	}

	fclose( fichier );
	printf( "Phrase enregistrée avec succès dans %s\n", FILENAME );

	return 0;
}
