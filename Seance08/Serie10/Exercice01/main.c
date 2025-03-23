#include <stdio.h>

int main( void )
{
	char lettre;
	FILE* fichier = NULL;

	printf( "Veuillez saisir une lettre: " );
	(void)scanf( " %c", &lettre );

	fichier = fopen( "Exercice01.txt", "a" );
	if ( fichier != NULL )
	{
		fputc( lettre, fichier );
		fclose( fichier );
		printf( "Lettre ecrite" );
	}
	else
	{
		printf( "Ouverture impossible" );
	}

	return 0;
}
