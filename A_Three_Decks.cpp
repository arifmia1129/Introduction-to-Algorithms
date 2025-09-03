#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;

    while(n--) {
        int a, b, c; cin >> a >> b >> c;

        int total = a + b + c;
        int avg = total / 3;

        if(total % 3 == 0 && b <= avg) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }

    return 0;
}