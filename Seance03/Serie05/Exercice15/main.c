#include <stdio.h>

int main( void )
{
	int Table[2][3] = {
		{ 1234, 1256, 4578 },
		{ 12, 20, 30 } };
	size_t i;
	int somme = 0;
	float moyenne = 0;

	printf( "Numero\t Age\n" );

	for ( i = 0; i < 3; ++i )
	{
		printf( "%d\t %d\n", Table[0][i], Table[1][i] );

		somme += Table[1][i];
	}

	moyenne = (float)somme / 3.f;

	printf( "La moyenne d'age est: %.2f\n", (double)moyenne );

	return 0;
}
