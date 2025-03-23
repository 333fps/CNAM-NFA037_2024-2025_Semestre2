#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

#define FILENAME "Exercice23.dat"
#define MAX_PHRASE 1000

int Ecrit_Mots( const char* nomFichier );
void Nb_Mot( const char* nomFichier );
int Compter_Mots( const char* texte );

int main( void )
{
	if ( !Ecrit_Mots( FILENAME ) )
	{
		fprintf( stderr, "Erreur lors de l'écriture du fichier.\n" );
		return EXIT_FAILURE;
	}
	Nb_Mot( FILENAME );
	return EXIT_SUCCESS;
}

int Ecrit_Mots( const char* nomFichier )
{
	FILE* fp;
	char phrase[MAX_PHRASE];
	int nbMots;

	do
	{
		printf( "Entrez une phrase d'au moins 10 mots: " );
		if ( fgets( phrase, sizeof( phrase ), stdin ) == NULL )
		{
			fprintf( stderr, "Erreur de lecture de l'entrée.\n" );
			return EXIT_SUCCESS;
		}
		phrase[strcspn( phrase, "\n" )] = '\0';

		nbMots = Compter_Mots( phrase );
		if ( nbMots < 10 )
		{
			printf( "La phrase doit contenir au moins 10 mots. Elle n'en contient que %d.\n", nbMots );
		}
	} while ( nbMots < 10 );

	fp = fopen( nomFichier, "wb" );
	if ( fp == NULL )
	{
		perror( "Erreur d'ouverture du fichier en écriture" );
		return EXIT_SUCCESS;
	}
	fwrite( phrase, sizeof( char ), strlen( phrase ), fp );
	fclose( fp );
	printf( "Phrase écrite avec succès dans le fichier.\n" );
	return EXIT_FAILURE;
}

void Nb_Mot( const char* nomFichier )
{
	FILE* fp;
	char texte[MAX_PHRASE];
	size_t bytesRead;
	int nombre;

	fp = fopen( nomFichier, "rb" );
	if ( fp == NULL )
	{
		perror( "Erreur d'ouverture du fichier en lecture" );
		return;
	}
	bytesRead = fread( texte, sizeof( char ), sizeof( texte ) - 1, fp );
	texte[bytesRead] = '\0';
	fclose( fp );

	nombre = Compter_Mots( texte );
	printf( "Nombre de mots: %d\n", nombre );
}

int Compter_Mots( const char* texte )
{
	wchar_t wbuf[MAX_PHRASE];
	int count = 0;
	int inWord = 0;
	size_t i;
	size_t len;

	len = mbstowcs( wbuf, texte, MAX_PHRASE );
	if ( len == (size_t)-1 )
	{
		fprintf( stderr, "Erreur de conversion de la chaîne UTF-8 en wchar_t.\n" );
		return EXIT_SUCCESS;
	}

	for ( i = 0; i < len; i++ )
	{
		if ( iswspace( (wint_t)wbuf[i] ) )
		{
			inWord = 0;
		}
		else if ( !inWord )
		{
			count++;
			inWord = 1;
		}
	}

	return count;
}
