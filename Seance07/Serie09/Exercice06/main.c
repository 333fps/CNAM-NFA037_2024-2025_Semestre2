#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	enum Notes
	{
		Do = 1,
		Re = 2,
		Mi = 3,
		Fa = 4,
		Sol = 5,
		La = 6,
		Si = 7
	};
	typedef enum Notes Notes;
	Notes Note1, Note2;
	Note1 = Mi;
	Note2 = Do;
	printf( "Position de la note : %d \n\n", Note1 );

	if ( Note1 == Note2 )
		printf( "Notes identiques\n" );
	else
		printf( "Notes differentes\n" );
	return EXIT_SUCCESS;
}
