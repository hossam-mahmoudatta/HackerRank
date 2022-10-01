
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while (T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
		cout << "A Value\n" << left << setfill('#')
			<< setw(12) << hex << showbase << 42 << '\n'
			<< setw(12) << hex << showbase << 42 << '\n';
		
		cout << "B Value\n" << right << setfill('_')
			<< setw(15) << hex << showbase << 42 << '\n';

		cout << "C Value\n" << right << setfill('_')
			<< setw(15) << hex << showbase << 42 << '\n';

	}
	return 0;

}