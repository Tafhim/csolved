#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define swp(a,b,t) {t tmp_swp=a; a=b; b=tmp_swp;}

using namespace std;
typedef long long lint;
typedef	wn lint;
vector<wn> set1, set2, Temp;
int main() {
	wn test, kase=1, input, NegOne, NegTwo, MaxNegHolder;
	cin >> test;
	while (test--) {
		cin >> n;
		set1.clear();
		set2.clear();
		NegOne = NegTwo = 0;

		for (wn i=0 ; i<n ; i++) {
			cin >> input;
			set1.push_back(input);
			NegOne += (input<0);
		}
		for (wn i=0 ; i<n ; i++) {
			cin >> input;
			set2.push_back(input);
			NegTwo += (input<0);
		}
		if (NegTwo>NegOne) {
			swp(set1, set2, vector<wn>);			
		}

		if (NegTwo>NegOne) {

		} else {

		}

	}
}
