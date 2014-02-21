#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n;
bool res[110][110], adj[110][110], visit[110];
vector<int> prelist, reslist;

void dfs(int u, int x) {

	visit[u] = true;

	for (int i = 0 ; i<n ; i++) {
		if (!visit[i] && adj[u][i] && i!=x) {
			dfs(i, x);
		}
	}
}

void solve() {
	for (int i = 0 ; i<n ; i++) {
		for (int j = 0 ; j<n ; j++) {
			res[i][j] = false;
		}
	}
	for(int x = 1 ; x<n ; x++) {
		prelist.clear();
		reslist.clear();
		for (int i = 0; i<n ; i++) {
			visit[i] = false;
		}
		dfs(0, -1);
		for (int i = 0 ; i<n ; i++) {
			if (visit[i])
				prelist.push_back(i);
			else {
				res[0][i] = true;
				res[x][i] = true;
			}
		}
		for (int i = 0; i<n ; i++) {
			visit[i] = false;
		}
		dfs(0, x);
		for (int i = 0 ; i<prelist.size() ; i++) {
			if (visit[prelist[i]])
				reslist.push_back(prelist[i]);
		}
		for (int i = 0 ; i<reslist.size() ; i++) {
			res[x][reslist[i]] = true;
		}
	}
}

int main() {

	int test, v, kase = 1;

	cin >> test;

	while (test--) {
		cin >> n;
		for (int i = 0 ; i<n ; i++) {
			for (int j = 0 ; j<n ; j++) {
				cin >> v;
				adj[i][j] = (v != 0);
				res[i][j] = false;
			}
		}
		solve();
		cout << "Case " << kase++ << ":" << endl;
		cout << "+";
		for (int i = 0 ; i<2*n-1 ; i++) cout << "-";
		cout << "+" << endl;
		for (int i = 0 ; i<n ; i++) {
			cout << "|";
			for (int j = 0 ; j<n ; j++) {
				cout << (res[i][j]==false?'Y':'N') << "|";
			}
			cout << endl;
			cout << "+";
			for (int i = 0 ; i<2*n-1 ; i++) cout << "-";
			cout << "+" << endl;
		}
	}


	return 0;
}