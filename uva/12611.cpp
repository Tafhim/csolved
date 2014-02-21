#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;


class point {
	public:
		double x, y;
		void show() {
			printf("%.0lf %.0lf\n",x,y);
		}
};

int main() {

	int test, kase=1;
	double r, w, l;
	cin >> test;

	while (test--) {

		cin >> r;

		l = r * 100.00 / 20.00;
		w = l * 60.00 / 100.00;

		point ul, ur, ll, lr;

		ul.x = - (l*45.00/100.00);
		ul.y = w / 2.00;

		ur.x = l*55.00/100.00;
		ur.y = w/2.00;

		ll.x = - (l*45.00/100.00);
		ll.y = - w/2.00;

		lr.x = l*55.00/100.00;
		lr.y = - w/2.00;

		printf("Case %d:\n",kase++);
		ul.show();
		ur.show();
		lr.show();
		ll.show();



	}

	return 0;
}