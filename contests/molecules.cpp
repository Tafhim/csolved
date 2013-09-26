// http://codeforces.com/contest/344/problem/B
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c;

	cin >> a >> b >> c;

	int total_hands = a + b + c; // Since a hands connect to b hands

	if (total_hands % 2 == 0) {
		int total_connections = total_hands / 2; // Since each 2 hands make 1 connection
		int ab = total_connections - c;
		int bc = total_connections - a;
		int ca = total_connections - b;

		if (ab < 0 || bc < 0 || ca < 0) {
			cout << "Impossible" << endl;
		} else {
			cout << ab << " " << bc << " " << ca << endl;
		}

	} else {
		cout << "Impossible" << endl;
	}

	return 0;
}