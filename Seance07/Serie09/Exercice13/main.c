#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 1000
#define MAX_WORD 50

void afficherStats( const char* texte );
void rechercherMot( const char* texte, const char* mot );
void inverserTexte( const char* texte, char* inverse );
void convertirMajuscules( const char* texte, char* majuscules );
void convertirMinuscules( const char* texte, char* minuscules );
int estPalindrome( const char* texte );

int main( void )
{
	char texte[MAX_TEXT] = { 0 };
	char mot[MAX_WORD] = { 0 };
	char inverse[MAX_TEXT] = { 0 };
	char majuscules[MAX_TEXT] = { 0 };
	char minuscules[MAX_TEXT] = { 0 };
	int choix = 0;

	printf( "=== ANALYSEUR DE TEXTE ===\n\n" );

	printf( "Entrez un texte (max %d caractères):\n", MAX_TEXT - 1 );
	fgets( texte, MAX_TEXT, stdin );

	if ( strlen( texte ) > 0 && texte[strlen( texte ) - 1] == '\n' )
		texte[strlen( texte ) - 1] = '\0';

	do
	{
		printf( "\nMenu:\n" );
		printf( "1. Afficher les statistiques du texte\n" );
		printf( "2. Rechercher un mot\n" );
		printf( "3. Afficher le texte inversé\n" );
		printf( "4. Convertir en majuscules\n" );
		printf( "5. Convertir en minuscules\n" );
		printf( "6. Vérifier si c'est un palindrome\n" );
		printf( "0. Quitter\n" );
		printf( "Votre choix: " );
		(void)scanf( "%d", &choix );

		while ( getchar() != '\n' )
			;

		switch ( choix )
		{
			case 1:
				afficherStats( texte );
				break;
			case 2:
				printf( "Entrez le mot à rechercher: " );
				fgets( mot, MAX_WORD, stdin );
				if ( strlen( mot ) > 0 && mot[strlen( mot ) - 1] == '\n' )
					mot[strlen( mot ) - 1] = '\0';
				rechercherMot( texte, mot );
				break;
			case 3:
				inverserTexte( texte, inverse );
				printf( "Texte inversé: %s\n", inverse );
				break;
			case 4:
				convertirMajuscules( texte, majuscules );
				printf( "En majuscules: %s\n", majuscules );
				break;
			case 5:
				convertirMinuscules( texte, minuscules );
				printf( "En minuscules: %s\n", minuscules );
				break;
			case 6:
				if ( estPalindrome( texte ) )
					printf( "Le texte EST un palindrome!\n" );
				else
					printf( "Le texte N'EST PAS un palindrome.\n" );
				break;
			case 0:
				printf( "Au revoir!\n" );
				break;
			default:
				printf( "Choix invalide!\n" );
		}
	} while ( choix != 0 );

	return 0;
}

void afficherStats( const char* texte )
{
	int chars = (int)strlen( texte );
	int lettres = 0;
	int mots = 0;
	int i;

	int enMot = 0;
	for ( i = 0; texte[i] != '\0'; i++ )
	{
		if ( isalpha( texte[i] ) )
		{
			lettres++;
			if ( !enMot )
			{
				enMot = 1;
				mots++;
			}
		}
		else
		{
			enMot = 0;
		}
	}

	printf( "Statistiques du texte:\n" );
	printf( "- Longueur: %d caractères\n", chars );
	printf( "- Lettres: %d\n", lettres );
	printf( "- Mots: %d\n", mots );
}

void rechercherMot( const char* texte, const char* mot )
{
	const char* position = texte;
	int count = 0;

	while ( ( position = strstr( position, mot ) ) != NULL )
	{
		count++;
		position += strlen( mot );
	}

	if ( count > 0 )
	{
		printf( "Le mot '%s' apparaît %d fois dans le texte.\n", mot, count );
	}
	else
	{
		printf( "Le mot '%s' n'a pas été trouvé dans le texte.\n", mot );
	}
}

void inverserTexte( const char* texte, char* inverse )
{
	int len = (int)strlen( texte );
	int i;

	for ( i = 0; i < len; i++ )
	{
		inverse[i] = texte[len - 1 - i];
	}
	inverse[len] = '\0';
}

void convertirMajuscules( const char* texte, char* majuscules )
{
	int i;

	strcpy( majuscules, texte );
	for ( i = 0; majuscules[i] != '\0'; i++ )
	{
		majuscules[i] = (char)toupper( majuscules[i] );
	}
}

void convertirMinuscules( const char* texte, char* minuscules )
{
	int i;

	strcpy( minuscules, texte );
	for ( i = 0; minuscules[i] != '\0'; i++ )
	{
		minuscules[i] = (char)tolower( minuscules[i] );
	}
}

int estPalindrome( const char* texte )
{
	char simplifie[MAX_TEXT] = { 0 };
	char inverse[MAX_TEXT] = { 0 };
	int j = 0;
	int i;

	for ( i = 0; texte[i] != '\0'; i++ )
	{
		if ( isalpha( texte[i] ) )
		{
			simplifie[j++] = (char)tolower( texte[i] );
		}
	}
	simplifie[j] = '\0';

	inverserTexte( simplifie, inverse );

	return strcmp( simplifie, inverse ) == 0;
}
