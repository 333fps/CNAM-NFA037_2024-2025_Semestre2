#include <stdio.h>

int main( void )
{
	int choix;
	int err;

	printf( "\n1: Café court non sucré \n2: Café court sucré \n3: Café long non sucré \n4: Café long sucré\n" );
	err = scanf( "%d", &choix );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	switch ( choix )
	{
		case 1:
			printf( "Vous avez choisi %d : Café court non sucré\n", choix );
			break;
		case 2:
			printf( "Vous avez choisi %d :  Café court sucré\n", choix );
			break;
		case 3:
			printf( "Vous avez choisi %d : Café long non sucré\n", choix );
			break;
		case 4:
			printf( "Vous avez choisi %d : Café long sucré\n", choix );
			break;
		default:
			printf( "Vous avez choisi %d : Choix de boisson non valide !\n", choix );
	}

	return 0;
}
