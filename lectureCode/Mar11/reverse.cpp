#include <stdio.h>

/*
	function int string_length(char*)
		calculates the length of a string
	returns and integer containing the length of the string
*/

int string_length(char* s)
{
	int len = 0;
	while( s[len] != '\0' )
	{
		len++;
	}

	return len;
}

/*
	function: reverse(char*)
		reverses a string in place
	returns nothing
*/

void reverse(char* s)
{
	int len = string_length(s);
	
	for( int i = 0; i < len / 2; i++ )
	{
		char tmp = s[i];
		s[i] = s[len-1-i];
		s[len-1-i] = tmp;
	}
}

int main( int argc, char* argv[] )
{
	printf( "initial string: %s(%d)\n", argv[1], string_length(argv[1]) );
	reverse(argv[1]);
	printf( "reversed string: %s\n", argv[1] );

	return 0;
}
