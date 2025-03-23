#include <stdio.h>
#include <string.h>
#include <ctype.h>

int NbVoyelles( char mot[] );

int main( void )
{
	char mot[100] = { 0 };

	printf( "Veuillez saisir un mot: " );
	(void)scanf( "%99s", mot );

	printf( "Le mot saisi contient %d lettres et %d voyelles.\n",
		(int)strlen( mot ), NbVoyelles( mot ) );

	return 0;
}

int NbVoyelles( char mot[] )
{
	int i;
	int nbVoyelles = 0;
	char c;

	for ( i = 0; mot[i] != '\0'; i++ )
	{
		c = (char)tolower( mot[i] );
		if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' )
		{
			nbVoyelles++;
		}
	}

	return nbVoyelles;
}
