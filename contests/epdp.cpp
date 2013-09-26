#include <cstdio>
#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef long long lint;

/*lint dp[30][30][(1<<14)];

lint solve(lint n, lint m) {

	for (lint i = 1 ; i<=n ; i++) {
		dp[n][i][(1<<i)] = 1;
	}

	for (lint p = n-1 ; p >= 1 ; p--) {
		for (lint i = 1 ; i <= n ; i++) {
			for (lint j = 1 ; j<=(1<<13) ; j++) {
				dp[p][i][j|(1<<i)] = 
			}
		}
	}

	for (lint i = 1 ; i <= n ; i++) {
		for (lint p = 1 ; p <= n ; p++) {
			cout << dp[p][i] << " ";
		}
		cout << endl;
	}

}*/

int main() {

/*	lint n, m;

	cout << 14*14*(1 << 13) << endl;

	while ( cin >> n >> m ) {
		solve(n, m);
	}*/
	for (lint x = 1 ; x <= 50 ; x++)
	for (lint i = 1 ; i <= 14 ; i++) {
		for (lint j = 1 ; j <= 14 ; j++) {
			for (lint k = 1 ; k <= 14 ; k++) {
				for (lint l = 1 ; l<=(1<<13) ; l++) {

				}
			}
		}
	}
	cout << "Done" << endl;

}