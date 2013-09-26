#include <cstdio>
#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

int ages[100], dp[100][3000], n;
bool memo[100][3000];
bool pre_samedigs[200][200], pre_getbits[102][(1<<10)+10];
int pre_setbits[102][(1<<10)+10], pre_countbits[(1<<10)+10], pre_maxres[(1<<10)+10][(1<<10)+10];

bool check(int mask, int bit) {
	if ( (mask & (1<<bit)) != 0 ) return true;
	return false;
}

bool same_digs(int a, int b) {
	bool found[20];
	for (int i = 0 ; i<20 ; i++) found[i] = false;
	char s[20];
	sprintf(s,"%d",a);
	for (int i = 0 ; s[i] ; i++) {
		found[s[i]-'0'] = true;
	}
	sprintf(s,"%d",b);
	for (int i = 0 ; s[i] ; i++) {
		if (found[s[i]-'0'] == true) return true;
		found[s[i]-'0'] = true;
	}
	return false;
}

int set_bits(int num, int mask) {
	if (num == 100 || num == 99 || num == 88 || num == 77 || num == 66 || num == 55 || num == 44 || num == 33 || num == 22 || num == 11 ) return -1;
	int set = mask;
	char s[4];
	sprintf(s,"%d",num);
	for (int i = 0 ; s[i] ; i++) {
		int b = s[i]-'0';
		set |= (1<<b);
	}
	return set;
}

bool get_bits(int num, int mask) {
	int set = mask;
	char s[4];
	bool valid = true;
	sprintf(s,"%d",num);
	for (int i = 0 ; s[i] ; i++) {
		int b = s[i]-'0';
		valid = ( valid && (check(mask,b)) );
	}

	return valid;
}

int count_bits(int mask) {
	int cnt = 0;
	for (int i = 9 ; i>=0 ; i--) {
		if (check(mask, i)) cnt++;
	}
	return cnt;
}

void print_pattern(int mask) {
	int cnt = 0;
	for (int i = 9 ; i>=0 ; i--) {
		if (check(mask, i)) cout << 1;
		else cout << 0;
	}
	cout << endl;
}

int returnmaxres(int maska, int maskb) {
	if (maska <= 0) return maskb;
	if (maskb <= 0) return maska;
	int ca = pre_countbits[maska];
	int cb = pre_countbits[maskb];
	if (ca == cb) {
		if (maska < maskb) return maska;
		else return maskb;
	}
	if (ca < cb) return maska;
	else return maskb;
}

int solve(int id, int mask) {
	if (id >=n) return mask;
	if (mask < 0) return -1;
	if ( memo[ id ][ mask ] == true ) {
		return dp[id][mask];
	}
	int num = ages[id];
	int direct = pre_setbits[num][mask];
	int mx = solve(id+1, direct);

	for (int i = 1 ; i<=((num+1)/2) ; i++) {
		if (i==(num-i) || pre_samedigs[i][num-i]) continue;
		int a = pre_setbits[i][mask];
		int b = pre_setbits[num-i][a];
		if (a>0 && b>0) {
			int tmp = solve( id+1, b );
			mx =  (mx < 0 ? tmp : pre_maxres[mx][tmp]);
		}
		a = pre_setbits[num-i][mask];
		b = pre_setbits[i][a];
		if (a>0 && b>0) {
			int tmp = solve( id+1, b );
			mx =  (mx < 0 ? tmp : pre_maxres[mx][tmp]);
		}
	}

	memo[id][mask] = true;
	dp[id][mask] = mx;

	return dp[id][mask];
}


int finalres[(1<<10)+10];

int result(int mask) {
	int power = 1;
	int res = 0;
	for (int i = 0 ; i<=9 ; i++) {
		if (check(mask, i)) {
			res = res + (i*power);
			power = power * 10;
		}
	}
	return res;
}

void init() {

	for (int i=0 ; i<=100 ; i++) { 
		for (int j = 0 ; j<=100 ; j++) {
			pre_samedigs[i][j] = same_digs(i, j);
		}
	}

	bool done = false;
	for (int i=0 ; i<=100 ; i++) {
		for (int j=0 ; j<(1<<10) ; j++) {
			if (!done) pre_countbits[j] = count_bits(j);
			pre_setbits[i][j] = set_bits(i, j);
			pre_getbits[i][j] = get_bits(i, j);
		}
		done = true;
	}


	for (int i=0 ; i<(1<<10) ; i++) {
		finalres[i] = result(i);
		for (int j=0 ; j<(1<<10) ; j++) {
			pre_maxres[i][j] = returnmaxres(i, j);
		}
	}
}

int main() {
	int kase = 1;

	init();
	while ( cin >> n ) {

		for (int i = 0 ; i<10 ; i++) {
			for (int j = 0 ; j<1100 ; j++) {
				memo[i][j] = false;
				//dp[i][j] = -1;
			}
		}

		if ( n == 0 ) return 0;
		for (int i = 0 ; i<n ; i++) {
			scanf("%d",&ages[i]);
		}
		int res = solve(0, 0);
		printf("Case %d: %d\n",kase++, finalres[res]);
	}

	return 0;
}