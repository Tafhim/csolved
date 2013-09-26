#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;


typedef long long lint;

lint dp[35][35];

lint solve(lint n, lint m) {
  
  lint pos, number, k, res, sum=0;
  for (k=1 ; k<=30 ; k++)
    for (pos=1 ; pos<=30 ; pos++)
      dp[k][pos]=0;

  for (k=1 ; k<=n ; k++) {
    dp[n][k] = 1;
  }
  for (pos = n-1 ; pos>=1 ; pos--) {
    for (number = 1 ; number <= n ; number++) {
      for (k = 1 ; k <= n ; k++) {
        if ((number + k)%m != 0 && (number!=k)) {
          //for (int s=0 ; s<pos ; s++) cout << " ";
          //cout << number << " " << k << endl;
          dp[pos][number] = (dp[pos][number] + dp[pos+1][k])%MOD;
          if (n-pos > 1) {
            for (int x = pos+2 ; x<=n ; x++) {
              dp[pos][number] = (dp[pos][number] - dp[x][number]) % MOD;
            }
          }
        }
      }
    }
  }
  
  for (k=1 ; k<=n ; k++)
    sum = (sum + dp[1][k])%MOD;
  
  return sum;
}

int main() {

  lint output = solve(14,25);

  cout << output << endl;

  return 0;
}
