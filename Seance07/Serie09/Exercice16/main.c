#include <stdio.h>

#define MAX_LENGTH 200

void Cherche( char* chaine, char* sous_chaine );
int Identique( char* debut_chaine, char* sous_chaine );

int main( void )
{
	char chaine[MAX_LENGTH];
	char sous_chaine[MAX_LENGTH];
	int i;

	printf( "Veuillez saisir une chaîne de caractères: " );
	fgets( chaine, MAX_LENGTH, stdin );

	for ( i = 0; chaine[i] != '\0'; i++ )
	{
		if ( chaine[i] == '\n' )
		{
			chaine[i] = '\0';
			break;
		}
	}

	printf( "Veuillez saisir une sous-chaîne de caractères: " );
	fgets( sous_chaine, MAX_LENGTH, stdin );

	for ( i = 0; sous_chaine[i] != '\0'; i++ )
	{
		if ( sous_chaine[i] == '\n' )
		{
			sous_chaine[i] = '\0';
			break;
		}
	}

	Cherche( chaine, sous_chaine );

	return 0;
}

void Cherche( char* chaine, char* sous_chaine )
{
	int i;
	int trouve = 0;

	if ( sous_chaine[0] == '\0' )
	{
		printf( "La sous-chaîne est vide.\n" );
		return;
	}

	for ( i = 0; chaine[i] != '\0'; i++ )
	{
		if ( Identique( &chaine[i], sous_chaine ) )
		{
			printf( "La sous-chaîne \"%s\" est au rang %d de la chaîne \"%s\".\n",
				sous_chaine, i + 1, chaine );
			trouve = 1;
			break;
		}
	}

	if ( !trouve )
	{
		printf( "La sous-chaîne \"%s\" n'a pas été trouvée dans la chaîne \"%s\".\n",
			sous_chaine, chaine );
	}

	return;
}

int Identique( char* debut_chaine, char* sous_chaine )
{
	int i;

	for ( i = 0; sous_chaine[i] != '\0'; i++ )
	{
		if ( debut_chaine[i] == '\0' || debut_chaine[i] != sous_chaine[i] )
		{
			return 0;
		}
	}

	return 1;
}
