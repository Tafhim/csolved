#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;


int main() {

	int test, first, second;
	string str;

	cin >> test;

	while ( test-- ) {
		cin >> str;
		first = 0;
		second = 0;
		for (int i=2, j=1 ; i>=0 ; i--, j*=26) {
			first += ( (str[i]-'A') * j );
		}
		for (int i=str.size()-1, j=1 ; i>3 ; i--, j*=10) {
			second += ( (str[i]-'0') * j );
		}
		//cout << first << " " << second << endl;
		if ( abs( first - second ) <= 100 ) cout << "nice" << endl;
		else cout << "not nice" << endl;
	}



	return 0; 
}