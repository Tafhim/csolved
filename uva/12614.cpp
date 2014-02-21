/*Solution to : UVa 12614
Method : Silly, just analyze what happens when you and between items in an array. The result is the max of them*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

/*ll dp[100][100], a[100];
ll solve(int n) {
	ll maxand = 0;
	for (int j = 0 ; j<n ; j++) {
		dp[j][0] = a[j];
		maxand = max( maxand, a[j]);
	}

	for (int l = 1 ; l<n ; l++) {
		for (int j = 0 ; l+j < n ; j++) {
			dp[j][l] = dp[j][l-1]&a[j+l];
			maxand = max( maxand, dp[j][l] );
		}
	}
	sort(a, a+n);

	return a[n-1];
}
*/
int main() {

	int test, kase=1;
	int n, x, maxres;

	//cout << ll(2&1) << endl;

	cin >> test;

	while (test--) {

		cin >> n;
		maxres = 0;
		for (int i = 0 ; i<n ; i++) {
			cin >> x;
			maxres = max(x, maxres);
		}

		cout << "Case " << kase++ << ": " << maxres << endl;


	}

}