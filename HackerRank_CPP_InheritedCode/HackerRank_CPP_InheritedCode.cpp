
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
// try: Represents a block of code that can throw an exception.
// catch: Represents a block of code that is executed when
//		a particular exception is thrown.
// throw : Used to throw an exception. Also used to list
//		the exceptions that a function throws but doesn’t handle itself.

/* Syntax
	try {
	   // protected code
	} catch( ExceptionName e1 ) {
	   // catch block
	} catch( ExceptionName e2 ) {
	   // catch block
	} catch( ExceptionName eN ) {
	   // catch block
	}
*/

class BadLengthException : public exception {
public:
	int length;
	
	BadLengthException(int n) {
		length = n;
	}
	int what() {
		return length;
	}
};
/******************************/

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if (n < 5) {
		throw BadLengthException(n);
	}
	for (int i = 0; i < n - 1; i++) {
		if (username[i] == 'w' && username[i + 1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while (T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if (isValid) {
				cout << "Valid" << '\n';
			}
			else {
				cout << "Invalid" << '\n';
			}
		}
		catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}