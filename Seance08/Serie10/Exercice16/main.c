#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice16.txt"

int main( void )
{
	FILE* fichier = NULL;
	int nombreNotes = 0;
	float sommeNotes = 0.0;
	float note;
	int candidat;

	fichier = fopen( FILENAME, "r" );
	if ( fichier == NULL )
	{
		printf( "Impossible d'ouvrir le fichier %s.\n", FILENAME );
		return EXIT_FAILURE;
	}

	while ( fscanf( fichier, "Candidat %d : %f\n", &candidat, &note ) == 2 )
	{
		sommeNotes += note;
		nombreNotes++;
	}

	fclose( fichier );

	if ( nombreNotes == 0 )
	{
		printf( "Aucune note trouvée dans le fichier.\n" );
	}
	else
	{
		float moyenne = sommeNotes / (float)nombreNotes;
		printf( "La moyenne des %d candidats est de : %.2f\n", nombreNotes, (double)moyenne );
	}

	return EXIT_SUCCESS;
}
