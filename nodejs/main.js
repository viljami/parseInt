(function () {
	"use strict";

	var ASCII_CODE_OF_ZERO = 48;

	console.log( 'String  s: ', process.argv[2] );
	console.log( 'Integer i: ', get_integer_from_string( process.argv[2] ));

	function get_integer_from_string( str ) {
		var power = 1, value = 0, sign = 1, size = 0;

		// Is the number negative or positive
		if( str[0] == '-') {
			sign = -1;
		}

		// Validate string
		for( var i = 0; i < str.length; i++ ) {
			var charCode = str.charCodeAt( i );

			// Sign has already been taken into account
			if( sign < 0 && i === 0 ) continue;

			// Is it a number
			if( charCode - ASCII_CODE_OF_ZERO > 9 ) break;
			power *= 10;
			size++;
		}

		// Calculate the value
		for( i = 0; i < size; i++ ) {
			if( sign < 0 && i === 0 ) {
				size++;
				continue;
			}
			power /= 10;
			value += str[ i ] * power;
		}
		return value * sign;
	}
})();
