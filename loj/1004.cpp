#include <cstdio>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int mat[200][200];

int main() {

	int test, n;

	cin >> test;

	while (test--) {
		cin >> n;
		for (int i=0 ; i<(2*n-1) ; i++) {
			int r, c;
			if (i<=n) { r = 0; c = n-i-1; }
			else { r = (i-n); c = 0; }
			for (int j=0 ; j<=i ; j++) {
				cout << r << "," << c << " ";
				cin >> mat[r][c];
				if (i<=n) r++;
				c++;
			}
			cout << endl;
		}
		for (int i=0 ; i<n ; i++) {
			for (int j=0 ; j<n ; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}


	return 0;
}