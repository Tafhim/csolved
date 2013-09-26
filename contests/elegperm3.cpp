#include <cstdio>
#include <iostream>
#include <string>

#define MOD 1000000007

using namespace std;

typedef long long lint;

lint dp[30000];
bool memo[30000];
lint solve(lint b, lint m, lint n, lint p) {
  
  if (b == (1<<15)-1) return 1; 
  if (memo[(b|(1<<p))]==true) return dp[(b|(1<<p))];
  
  for (int i=1 ; i<=n ; i++) {
    if (p<0 || ((p+i)%m!=0 && !(b&(1<<i)))) {  
      dp[(b|(1<<i))] = (dp[(b|(1<<i))] + solve((b|(1<<i)), m, n, i))%MOD; 
    }
  }
  memo[(b|(1<<i))] = true;

  return 0;
}


int main() {
  
  while (cin >> n >> m) {
    for (int i=0 ; i<30000 ; i++) {
      dp[i] = 0;
      memo[i] = false;
    }
    cout << solve(0, m, n, -1) << endl;
  }


  return 0;
}
