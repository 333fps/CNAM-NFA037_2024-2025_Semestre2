#include <stdio.h>

int main( void )
{
	int Table[2][3] =
		{
			{ 1234, 1256, 4578 },
			{ 12, 20, 30 } };
	size_t i;

	printf( "Numero\t Age\n" );

	for ( i = 0; i < 3; ++i )
	{
		printf( "%d\t %d\n", Table[0][i], Table[1][i] );
	}

	return 0;
}
