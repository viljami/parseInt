(function () {
	"use strict";

	console.log( 'String  s: ', process.argv[2] );
	console.log( 'Integer i: ', get_integer_from_string( process.argv[2] ));

	function get_integer_from_string( str ) {
		var num = 1, value = 0, sign = 1, index = 0;
		var charCodeOfZero = '0'.charCodeAt(0);

		// Is the number negative or positive
		if( str[0] == '-') {
			sign = -1;
			index = 1;
		}

		// Parse int
		for( index; index < str.length; index++ ) {
			num = str.charCodeAt( index ) - charCodeOfZero;
			if( num < 0 || num > 9 ) break;
			value = value * 10 + num;
		}

		return value * sign;
	}
})();
