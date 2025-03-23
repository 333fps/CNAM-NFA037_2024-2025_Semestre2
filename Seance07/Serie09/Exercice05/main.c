#include <stdio.h>
#include <string.h>

struct Personne
{
	char Nom[15];
	char Prenom[15];
};

int main( void )
{
	struct Personne p1;

	printf( "Quel est votre nom? " );
	(void)scanf( "%s", p1.Nom );

	printf( "Quel est votre prénom? " );
	(void)scanf( "%s", p1.Prenom );

	printf( "vous vous appelez %s %s\n", p1.Prenom, p1.Nom );

	return 0;
}
