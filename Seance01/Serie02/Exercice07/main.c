#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	float FF;
	float GG;

	FF = 12.5f;
	GG = 25.5f;

	printf( "La somme de FF et GG est : %f\n", (double)( FF + GG ) );

	return EXIT_SUCCESS;
}
