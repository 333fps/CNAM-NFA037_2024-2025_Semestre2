#include <stdio.h>

int main( void )
{
	int Table[2][3] =
		{
			{ 1234, 1256, 4578 },
			{ 12, 20, 30 } };

	size_t i;
	for ( i = 0; i < 3; i++ )
	{
		printf( "%d\t %d\n", Table[0][i], Table[1][i] );
	}

	{
		int temp;
		for ( i = 0; i < 3; ++i )
		{
			temp = Table[0][i];
			Table[0][i] = Table[1][i];
			Table[1][i] = temp;
		}
	}

	for ( i = 0; i < 3; i++ )
	{
		printf( "%d\t %d\n", Table[0][i], Table[1][i] );
	}

	return 0;
}
