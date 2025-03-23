#include <stdio.h>
#include <string.h>

#define FILENAME "Exercice22.dat"
#define MAX_PHRASE 1000
#define MAX_MOT 100

void Ecrit_Mots( const char* nomFichier );
void Mot_3( const char* nomFichier );

int main( void )
{
	Ecrit_Mots( FILENAME );

	Mot_3( FILENAME );

	return 0;
}

void Ecrit_Mots( const char* nomFichier )
{
	FILE* fichier = NULL;
	char phrase[MAX_PHRASE];
	size_t longueur;

	printf( "Entrez une phrase: " );
	fgets( phrase, MAX_PHRASE, stdin );

	longueur = strlen( phrase );
	if ( longueur > 0 && phrase[longueur - 1] == '\n' )
	{
		phrase[longueur - 1] = '\0';
	}

	fichier = fopen( nomFichier, "wb" );
	if ( fichier == NULL )
	{
		printf( "Impossible d'ouvrir le fichier %s en écriture.\n", nomFichier );
		return;
	}

	fwrite( phrase, sizeof( char ), strlen( phrase ) + 1, fichier );

	fclose( fichier );
	printf( "Phrase écrite avec succès dans le fichier.\n" );
}

void Mot_3( const char* nomFichier )
{
	FILE* fichier = NULL;
	char phrase[MAX_PHRASE];
	char mot[MAX_MOT];
	int compteurMots = 0;
	int i, j = 0;
	size_t tailleLue;

	fichier = fopen( nomFichier, "rb" );
	if ( fichier == NULL )
	{
		printf( "Impossible d'ouvrir le fichier %s en lecture.\n", nomFichier );
		return;
	}

	tailleLue = fread( phrase, sizeof( char ), MAX_PHRASE - 1, fichier );
	phrase[tailleLue] = '\0';

	for ( i = 0; phrase[i] != '\0'; i++ )
	{
		if ( phrase[i] == ' ' || phrase[i] == '\t' || phrase[i] == '\n' )
		{
			if ( j > 0 )
			{
				mot[j] = '\0';
				compteurMots++;

				if ( compteurMots == 3 )
				{
					printf( "Le troisième mot est: \"%s\"\n", mot );
					break;
				}

				j = 0;
			}
		}
		else
		{
			mot[j++] = phrase[i];
			if ( j >= MAX_MOT - 1 )
				j = MAX_MOT - 1;
		}
	}

	if ( compteurMots < 3 )
	{
		if ( j > 0 )
		{
			mot[j] = '\0';
			compteurMots++;
			if ( compteurMots == 3 )
			{
				printf( "Le troisième mot est: \"%s\"\n", mot );
			}
		}

		if ( compteurMots < 3 )
		{
			printf( "Le fichier contient moins de 3 mots.\n" );
		}
	}

	fclose( fichier );
}
