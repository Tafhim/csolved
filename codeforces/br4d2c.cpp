#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string,int> mp;

int main() {

  cin >> n;
  mp.clear();
  string s;
  for (int i=0 ; i<n ; i++) {
    cin >> s;
    if (mp.find(s)!=mp.end()) {
      // found
      mp[s]++;
      cout << s << mp[s]
    }
  }

  return 0;

}
