
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

		cout << left << hex << showbase << nouppercase << (long long)A << '\n';

		cout << right << setfill('_') << setw(15)
			<< fixed << setprecision(2) << showpos << B << '\n';

		cout << setprecision(9) << scientific << noshowpos << uppercase << C << '\n';

	}
	return 0;

}