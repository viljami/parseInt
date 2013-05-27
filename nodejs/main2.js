(function () {
	"use strict";

	console.log( 'String  s: ', process.argv[2] );
	console.log( 'Integer i: ', get_integer_from_string( process.argv[2] ));

	function get_integer_from_string( str ) {
		var power = 1, value = 0, sign = 1, size = 0;

		// Is the number negative or positive
		if( str[0] == '-') {
			sign = -1;
		}

		// Validate
		for( var i = 0; i < str.length; i++ ) {
			if( sign < 0 && i === 0 ) continue;

			var code = str.charCodeAt( i ) - '0'.charCodeAt(0);
			if( code < 0 || code > 9 ) break;

			power *= 10;
			size++;
		}

		// Parsing
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
