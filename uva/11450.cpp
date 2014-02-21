// DP 11450
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector< vector<int> > prices;

int C, M;
bool memo[300][100];
int dp[300][100];

int solve(int money, int c, int bot) {
	if (money > M) return -10000;
	if (c == C) if (bot == C) { return money; } else { return -10000; }
	if ( memo[money][c] == true ) return dp[money][c];

	int res = -10000;
	for (int i = 0 ; i<prices[c].size() ; i++) {
		//if (money+prices[c][i]<=M) {
			res = max(res, solve(money+prices[c][i], c+1, bot+1));
		//}
	}
	//res = max(res, solve(money, c+1, bot));

	memo[money][c] = true;
	dp[money][c] = res;

	return dp[money][c];
}

void init() {
	for (int i = 0 ; i<=203 ; i++) {
		for (int j = 0 ; j<=30 ; j++) {
			memo[i][j] = false;
			dp[i][j] = -10000;
		}
	}
}

int main() {

	int test, m, c, k, tmp;
	prices.resize(30);
	scanf("%d", &test);
	while (test--) {
		init();
		scanf("%d %d",&m, &c);
		C = c;
		M = m;
		for (int i = 0 ; i<c ; i++) {
			scanf("%d",&k);
			prices[i].clear();
			for (int j = 0 ; j<k ; j++) {
				scanf("%d",&tmp);
				prices[i].push_back(tmp);
			}
		}
		int res = solve(0, 0, 0);

		if (res < 0) printf("no solution\n");
		else printf("%d\n",res);
	}

	return 0;
}