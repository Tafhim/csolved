#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


vector<string> grid;
int test[20][20];
int dir[][2] = { {-1, 0}, {0, -1}, {0, 0}, {0, 1}, {1, 0} };
//int dir[][2] = { {0, 0}, {0, 1}, {1, 0} };

bool check() {

	for (int i = 0 ; i<10 ; i++)
		for (int j = 0 ; j<10 ; j++)
			if (test[i][j]) return false;
	return true;
}

int flip(int i, int j) {
	for (int k = 0 ; k<5 ; k++) {
		int x = i + dir[k][0];
		int y = j + dir[k][1];
		if (x<0 || y<0 || x>9 || y>9) continue;
		test[x][y] = 1-test[x][y];
	}
	return 0;
}


int bforce() {
	
	int maxflips = 1000000;

	for (int i = 0 ; i<(1<<10) ; i++) {
		for (int j = 0 ; j<10 ; j++)
			for (int k = 0 ; k<10 ; k++)
				test[j][k] = (grid[j][k] == 'O');

		int flips = 0;
		for (int j = 0 ; j<10 ; j++) {
			if (i&(1<<j)) {
				flip(0, j);
				flips++;
			}
		}
		for (int j = 1 ; j<10 ; j++) {
			for (int k = 0 ; k<10 ; k++) {
				if (test[j-1][k]) {
					flip(j, k);
					flips++;
				}
			}
			if (check())
				maxflips = min( maxflips, flips);
		}
		
	}

	return maxflips;

}

int main() {

	string str, s;

	while ( cin >> str ) {
		if ( str == "end" ) return 0;
		grid.clear();
		for (int i = 0 ; i<10 ; i++) {
			cin >> s;
			grid.push_back(s);
		}
		cout << str << " " << bforce() << endl;
	}


	return 0;
}