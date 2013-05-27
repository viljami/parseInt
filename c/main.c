#include <stdio.h>

const int ASCII_CODE_OF_ZERO = 48;

void main(int argc, char** argv)
{
    if( argc > 0 ) {
    	printf("String  s: %s\n", argv[ 1 ]);
    	int result = get_integer_from_string( argv[ 1 ] );
    	printf("Integer i: %i\n", result);
    }
}

int get_integer_from_string( const char* str ) {
	int value = 0, power = 1, tmp = 0, size = 0, sign = 1;
	const char* c = NULL;

	// Is the number negative or positive
	if( str[0] == '-') {
		sign = -1;
		str++;
	}

	// check the whole is ok
	for(c = str; *c != '\0'; c++){
		tmp = *c - ASCII_CODE_OF_ZERO;
		if( tmp > 9 ) {
			break;
		}
		size++;
	}
	
	// setting the power
	for( tmp = size; tmp > 0; tmp--) {
		power *= 10;
	}

	// calculation of the number
	for(c = str; *c != '\0'; c++){
		power = power / 10;
		tmp = *c - ASCII_CODE_OF_ZERO;
		value += tmp * power;
		if( power <= 1 ) {
			break;
		}
	}
	return value * sign;
}
