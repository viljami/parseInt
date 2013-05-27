#include <stdio.h>

void main(int argc, char** argv)
{
    if( argc > 0 ) {
    	printf("String  i: %s\n", argv[ 1 ] );
    	printf("Integer i: %i\n", get_integer_from_string( argv[ 1 ] ));
    }
}

/**
 * Function parses String to Int. Parsing stops if value outside 0 - 9 is met.
 *
 * Param  String to be parsed.
 * Return Parsed Integer.
 */
int get_integer_from_string( const char* str ) {
	int value = 0, power = 1, tmp = 0, size = 0, sign = 1;
	const char* c = NULL;

	// Is the number positive or negative
	if( str[0] == '-') {
		sign = -1;
		str++;
	}

	// Validation
	for(c = str; *c != '\0'; c++){
		tmp = *c - '0';
		if( tmp < 0 || tmp > 9 ) break;
		power *= 10;
		size++;
	}

	// Parsing
	for(c = str; *c != '\0'; c++){
		power /= 10;
		value += (*c - '0') * power;
		if( power <= 1 ) break;
	}

	return value * sign;
}
