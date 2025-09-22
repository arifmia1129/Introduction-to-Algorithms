#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;

    while(t--) {
        int a, b, c; cin >> a >> b >> c;

        int tl = a + b + c;

        if(tl % 3 == 0 && b <= tl/3)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}