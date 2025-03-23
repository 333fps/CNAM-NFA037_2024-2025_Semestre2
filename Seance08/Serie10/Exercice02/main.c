#include <stdio.h>

int main( void )
{
	char mot[100] = { 0 };
	FILE* fichier = NULL;

	printf( "Saisir un mot: " );
	(void)scanf( "%99s", mot );

	fichier = fopen( "Exercice02.txt", "a" );
	if ( fichier != NULL )
	{
		fputs( mot, fichier );
		fclose( fichier );
		printf( "Mot écrit" );
	}
	else
	{
		printf( "Ouverture impossible" );
	}

	return 0;
}
