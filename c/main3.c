#include <stdio.h>

void main(int argc, char** argv)
{
    if( argc > 1 ) {
    	printf("String : %s\n", argv[ 1 ] );
    	printf("Integer: %i\n", get_integer_from_string( argv[ 1 ] ));
    }
}

/**
 * Function parses String to Int. Parsing stops if value outside 0 - 9 is met.
 * '-' char is accepted as indicator of a negative number.
 *
 * Param  String to be parsed.
 * Return Parsed Integer.
 */
int get_integer_from_string( const char* str ) {
	int value = 0, num = 0, sign = 1;
	const char* c = NULL;

	// Is the number negative
	if( str[0] == '-') {
		sign = -1;
		str++;
	}

	// Parse int
	for(c = str; *c != '\0'; c++){
		num = *c - '0';
		if( num < 0 || num > 9 ) break;
		value = value * 10 + num;
	}

	return value * sign;
}
