#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#define MOD 1000000007
typedef long long lint;

using namespace std;

lint dp[30][30][30][2];

lint solve(lint n, lint m) {

  for (int i=0 ; i<=n ; i++)
    for (int j=0 ; j<=n ; j++)
      for (int k=0 ; k<=n ; k++)
        for (int l=0 ; l<=1 ; l++)
          dp[i][j][k][l] = 0;

  for (int k=1 ; k<=n ; k++) {
    dp[n][k][k][0] = (1<<k);
    dp[n][k][k][1] = 1;
  }

  for (int pos = n-1 ; pos>=1 ; pos--) {
    for (int num = 1 ; num<=n ; num++) {
      for (int k = 1 ; k<=n ; k++) {
        for (int l=1 ; l<=n ; l++) {
          if ( (num+k)%m!=0 && ((dp[pos+1][k][l][0]&(1<<num))==0)) {
            dp[pos][num][k][1] = (dp[pos][num][k][1] + dp[pos+1][k][l][1])%MOD;
            dp[pos][num][k][0] = dp[pos+1][k][l][0] | (1<<num);
          }
        }
      }
    }
  }
 
  lint sum=0;
  for (int k=1 ; k<=n ; k++)
    for (int l=1 ; l<=n ; l++)
      sum = (sum + dp[1][k][l][1])%MOD;

  return sum;
}


int main() {
  cout << solve(14,25) << endl;
  return 0;
}
