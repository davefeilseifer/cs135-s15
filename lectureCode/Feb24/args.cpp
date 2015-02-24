#include <stdio.h>

int main( int argc, char* argv[] )
{
	printf( "the number of command-line arguments is: %d\n", argc );

	for( int i = 0; i < argc; i++ )
	{
		printf("argv[%d]: %s\n", i, argv[i] );
	}

	return 0;
}
