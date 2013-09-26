// http://codeforces.com/contest/344/problem/A

#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {    
    int x, p, n;
    cin >> n;
    cin >> p;
    if (n==0) {
        cout << 0 << endl;
        return 0;
    }
    int grp = 1;
    for (int i=1 ; i<n ; i++) {
        cin >> x;
        if (x!=p)
            grp++;
        p = x;
    }

    cout << grp << endl;

    return 0;
}