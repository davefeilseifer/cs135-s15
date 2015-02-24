#include <stdio.h>

int main( int argc, char* argv[] )
{
	char* filename = argv[1];
	printf( "filename is: %s\n", filename );

	FILE* infile;
	infile = fopen( filename, "r" );

	char c;
	while( (c = fgetc(infile)) != EOF )
	{
		if( c == " " ) 
		{
			printf( "THIS IS A SPACE!!!" );
		}
		if( c == '\n' )
		{
			printf( "THIS IS A NEW LINE!!!" );
		}
		printf( "%c\n", c );
	}


	return 0;
}
