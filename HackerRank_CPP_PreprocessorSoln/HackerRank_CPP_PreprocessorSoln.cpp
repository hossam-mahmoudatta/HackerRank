/* Enter your macros here */

# define INF 10000000

//# define minimum(min, x) (x < min) ? (min == x) : (min);
//# define maximum(max, x) (x > max) ? (max == x) : (max);

# define foreach(v, i) for(int i = 0 ; i < v.size() ; i++)
# define io(v) cin >> v
# define toStr(S) #S

# define FUNCTION(name, operator) void name(int &current, int candidate) {!(current operator candidate) ? current = candidate : false;}

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION( minimum, < )
FUNCTION( maximum, > )

int main() {
	int n; cin >> n;
	vector<int> v(n);
	
	foreach(v, i) {
		io(v)[i];
	}

	int mn = INF;
	int mx = -INF;

	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result = ) << ' ' << ans;
	return 0;

}