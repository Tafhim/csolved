#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef long long lint;

lint a[10];

lint solve(lint m, lint remain) {
  if (remain == 0) return 1;
  if (remain < 0) return 0;
  if (m<0 && remain>0) return 0;
  
  if (memo[m][remain]==true) return dp[m][remain];

  dp[m][remain] += solve(m,remain-a[m]) + solve(m-1,remain);
  
  memo[m][remain] = true;
  return dp[m][remain];
}

int main() {
  
  cin >> n >> a[0] >> a[1] >> a[2];
  return 0;
}
