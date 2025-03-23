#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define FILENAME "Exercice24.dat"
#define NUM_INTEGERS 200

void Ecrit_200( const char* nomFichier );
void Plus_Grand( const char* nomFichier );

int main( void )
{
	srand( (unsigned)time( NULL ) );

	Ecrit_200( FILENAME );

	Plus_Grand( FILENAME );

	return EXIT_SUCCESS;
}

void Ecrit_200( const char* nomFichier )
{
	FILE* fp;
	int i;
	int randomInt;

	fp = fopen( nomFichier, "wb" );
	if ( fp == NULL )
	{
		perror( "Erreur d'ouverture du fichier en écriture" );
		exit( EXIT_FAILURE );
	}

	for ( i = 0; i < NUM_INTEGERS; i++ )
	{
		randomInt = rand();
		fwrite( &randomInt, sizeof( int ), 1, fp );
	}

	fclose( fp );
	printf( "200 entiers aléatoires ont été écrits dans le fichier.\n" );
}

void Plus_Grand( const char* nomFichier )
{
	FILE* fp;
	int i;
	int currentInt;
	int maxInt;

	fp = fopen( nomFichier, "rb" );
	if ( fp == NULL )
	{
		perror( "Erreur d'ouverture du fichier en lecture" );
		exit( EXIT_FAILURE );
	}

	maxInt = INT_MIN;

	for ( i = 0; i < NUM_INTEGERS; i++ )
	{
		fread( &currentInt, sizeof( int ), 1, fp );
		if ( currentInt > maxInt )
		{
			maxInt = currentInt;
		}
	}

	fclose( fp );
	printf( "Le plus grand entier dans le fichier est: %d\n", maxInt );
}
