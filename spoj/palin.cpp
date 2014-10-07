// UNFINISHED
#include <cstdio>
#include <iostream>

using namespace std;

pair<pair<int, int>, int> stk[500000+10];
int stk_pointer = -1;


void solve(string str) {
	int num_length = str.size();
	int mid_position_1, mid_position_2;
	
	// Determine both mid positions
	if (num_length & 1) {
		mid_position_1 = (num_length / 2);
		mid_position_2 = (num_length / 2);
	} else {
		mid_position_1 = (num_length / 2);
		mid_position_2 = (num_length / 2)+1;
	}

	// Decrement 1 from each to match array positions
	mid_position_1--;
	mid_position_2--;

	


}

int main() {
//	cin >> n;
//	while (n--) {
//		cin >> str;
//	}
	int a = 1000000, b = 999999;
	for (int i = 0 ; i<500000 ; i++) {
		a+b;	
	}
	return 0;
}
