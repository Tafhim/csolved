#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

typedef long long lint;

map< vector<lint>, pair<lint, lint> > memo;

lint m, n;
lint solve(vector<lint> state, lint level) {

/*	for (lint x = 0 ; x<state.size() ; x++) {
		cout << state[x] << " ";
	}
	cout << endl;*/


	map< vector<lint>, pair<lint,lint> >::iterator mem = memo.find(state);
	if ( mem != memo.end() && mem->second.first == level+1 ) {
		lint res = mem->second.second;
		return ((res+1)%MOD);
	}

	if (state.size() == n) {
		//cout << "This 2" << endl;
		memo[ state ] = make_pair(level+1, 1);
		return 1;
	}

	memo[ state ] = make_pair(level+1, 0);
	map< vector<lint>, pair<lint, lint> >::iterator current = memo.find(state);

	lint last = (state.empty() ? -1 : state.back());
	for (lint i=1 ; i<=n ; i++) {
		vector<lint>::iterator point = find(state.begin(), state.end(), i);
		if (point == state.end()) { // i hasn't been used yet
			if ( ((last+i)%m !=0) || last<0 ) {
				state.push_back(i);
				current->second.second = (current->second.second + solve(state, level)%MOD )%MOD;
				state.pop_back();
			}
		}
	}

	return memo[ state ].second;
}

int main() {
	vector<lint> state;
	while ( cin >> n >> m ) {
		memo.clear();
		state.clear();
		cout << solve(state, -1) << endl;
	}

	return 0;
}