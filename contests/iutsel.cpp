#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long lint;

vector<lint> final;
map< vector<lint>, bool > memo;
bool solve(vector<lint> tape, lint level, lint psize) {
//cout << level << endl;
/*	for (int mm = 0 ; mm<tape.size() ; mm++) {
		cout << tape[mm] << " ";
	}
	cout << endl;*/
	if (memo.find(tape)!=memo.end()) return memo[tape];
	//cout << tape.size() << endl;
	//cout << "Part 1" << endl;
	bool same = false;
	if (final.size() == tape.size()) { // Sizes match, so go further with checking each element
		same = true;
		for (lint i=0 ; i<tape.size() ; i++) {
			if (tape[i]!=final[i])
			{
				same = false;
				break;
			}
		}
	}

	if (same == true) {
		memo[tape] = same;
		return same;
	}

	//cout << "Part 2" << endl;
	if (tape.size() < 2 || tape.size() == psize) {
		memo[tape] = false;
		return false;
	}

	if (!same) {
		vector<lint> newtape;
		for (lint s = 0 ; s<tape.size() && !same ; s++) {
			// cout << "Fold starts at : " << s << " ";
			newtape.clear();
			lint j = 1;
			//cout << "Part 3 " << endl;// << tape.size() << endl;
			for (lint k=s ; k>=0 ; k--, j++) {
				lint a = tape[k];
				lint b = ((k+(2*j-1))>=tape.size() ? 0 : tape[k+(2*j-1)]);
				newtape.push_back(a + b);
			}
			j--;

			// cout << "Fold ends at : " << 2*j-1 << endl;
			for (lint x = 2*j ; x<tape.size() ; x++) {
				newtape.push_back(tape[x]);
			}
			//cout << newtape.size() << endl;
			
			//cout << "Part 4" << endl;
			same = same || solve(newtape, level+1, tape.size());
		}
	}

	memo[tape] = same;

	return same;
}

int main() {
	vector<lint> origtape;
	lint n;
	while (cin >> n) {
		origtape.clear();
		for (lint i=0, x = 0 ; i<n ; i++) {
			cin >> x;
			origtape.push_back(x);
		}
		lint m;
		cin >> m;
		final.clear();
		for (lint i=0, x ; i<m ; i++) {
			cin >> x;
			final.push_back(x);
		}
		memo.clear();
		cout << (solve(origtape, 0, -1)==true?'S':'N') << endl;
	}


	return 0;
}