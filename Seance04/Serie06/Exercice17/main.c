#include <stdio.h>

#ifdef __clang__
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wuninitialized"
#endif

#if defined( __GNUC__ ) && !defined( __clang__ )
#	pragma GCC diagnostic push
#	pragma GCC diagnostic ignored "-Wuninitialized"
#endif

#ifdef _MSC_VER
#	pragma warning( push )
#	pragma warning( disable : 6001 )
#	pragma warning( disable : 4700 )
#endif

int Modif( void );

int main( void )
{
	int a;

	printf( "Valeur de a ? : \n" );
	(void)scanf( "%d", &a );
	printf( "Valeur de a saisie : %d\n", a );
	printf( "Valeur renvoyee apres execution de la fontion Modif : %d\n", Modif() );
	return 0;
}

int Modif( void )
{
	int a;

	return --a;
}

#ifdef __clang__
#	pragma clang diagnostic pop
#endif

#if defined( __GNUC__ ) && !defined( __clang__ )
#	pragma GCC diagnostic pop
#endif

#ifdef _MSC_VER
#	pragma warning( pop )
#endif
