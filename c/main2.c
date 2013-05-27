#include <stdio.h>

void main(int argc, char** argv)
{
    if( argc > 0 ) {
    	printf("String  i: %s\n", argv[ 1 ] );
    	printf("Integer i: %i\n", get_integer_from_string( argv[ 1 ] ));
    }
}

int get_integer_from_string( const char* str ) {
	int value = 0, power = 1, tmp = 0, size = 0, sign = 1;
	const char* c = NULL;
	if( str[0] == '-') {
		sign = -1;
		str++;
	}

	for(c = str; *c != '\0'; c++){
		tmp = *c - '0';
		if( tmp < 0 || tmp > 9 ) break;
		power *= 10;
		size++;
	}

	for(c = str; *c != '\0'; c++){
		power /= 10;
		value += (*c - '0') * power;
		if( power <= 1 ) break;
	}
	
	return value * sign;
}
