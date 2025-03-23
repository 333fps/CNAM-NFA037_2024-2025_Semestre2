#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice_cours01.dat"

enum Result
{
	SUCCESS = 0,
	FAILURE
};

enum Result BinaryWrite( void );
enum Result BinaryRead( void );

int main( void )
{
	enum Result result;

	result = BinaryWrite();
	if ( result == FAILURE )
	{
		printf( "La fonction BinaryWrite a échoué\n" );

		return EXIT_FAILURE;
	}

	result = BinaryRead();
	if ( result == FAILURE )
	{
		printf( "La fonction BinaryRead a échoué\n" );

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

enum Result BinaryWrite( void )
{
	FILE* file = NULL;
	int a = 10;
	double b = 3.14;
	size_t itemsWritten;

	file = fopen( FILENAME, "wb" );
	if ( !file )
	{
		printf( "Impossible de créer le fichier %s\n", FILENAME );
		return FAILURE;
	}

	itemsWritten = fwrite( &a, sizeof( int ), 1, file );
	if ( itemsWritten != 1 )
	{
		printf( "Erreur lors de l'écriture de l'entier\n" );
		fclose( file );
		return FAILURE;
	}

	itemsWritten = fwrite( &b, sizeof( double ), 1, file );
	if ( itemsWritten != 1 )
	{
		printf( "Erreur lors de l'écriture du réel\n" );
		fclose( file );
		return FAILURE;
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier\n" );
		return FAILURE;
	}

	return SUCCESS;
}

enum Result BinaryRead( void )
{
	FILE* file = NULL;
	int a;
	double b;
	size_t itemsRead;

	file = fopen( FILENAME, "rb" );
	if ( !file )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );
		return FAILURE;
	}

	itemsRead = fread( &a, sizeof( int ), 1, file );
	if ( itemsRead != 1 )
	{
		printf( "Erreur lors de la lecture de l'entier\n" );
		fclose( file );
		return FAILURE;
	}

	itemsRead = fread( &b, sizeof( double ), 1, file );
	if ( itemsRead != 1 )
	{
		printf( "Erreur lors de la lecture du réel\n" );
		fclose( file );
		return FAILURE;
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier\n" );
		return FAILURE;
	}

	printf( "L'entier est %d et le réel est %f.\n", a, b );

	return SUCCESS;
}
