#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <map>
using namespace std;
#define DEBUG false
int reqs[300][300];
map<int, bool> nums;
int main() {
	
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

	int test, kase=1;

	scanf("%d",&test);

	while(test--) {
		scanf("%d %d",&m, &n);
		
		nums.clear();
		for (i=0 ; i<m ; i++) {
			for (j=0 ; j<n ; j++) {
				scanf("%d",&reqs[i][j]);
				nums[reqs[i][j]] = true;
			}
		}
		
		bool yes = true;
	
		for(map<int, bool>::iterator num = nums.begin() ; num != nums.end() ; num++) {
			for (i = 0 ; i<m ; i++) {
				for (j = 0 ; j<n ; j++) {
					if (reqs[i][j] == (*num).first) {
						bool tyes = true;
						bool ftyes = true;
						for (k = 0 ; k<m ; k++) {
							tyes &= (reqs[k][j]<=(*num).first);
							if (DEBUG) {
								cout << (*num).first << " " << tyes << " " << " " << reqs[k][j] << endl;
							}
						}
						ftyes = tyes;
						tyes = true;
						for (l = 0 ; l<n ; l++) {
							tyes &= (reqs[i][l]<=(*num).first);
							if (DEBUG) {
								cout << (*num).first << " " << tyes << " " << " " << reqs[i][l] << endl;
							}
						}
						ftyes = tyes || ftyes;
						yes &= ftyes;
					}
				}
			}
		}

		printf("Case #%d: %s\n",kase++,(yes?"YES":"NO"));
	}
	return 0;
}
