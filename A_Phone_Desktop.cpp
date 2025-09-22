#include<bits/stdc++.h>
using namespace std;

int main () {
    int t;

    cin >> t;

    while(t--) {
        int x, y; cin >> x >> y;

        int screen = y / 2;
        int remain = screen * 7;

        if(y % 2 != 0) {
            screen++;
            remain += 11;
        }

        if(x > remain) {
            x -= remain;

            screen += x/15;

            if(x % 15 != 0){
                screen++;
            }
        }

        cout << screen << endl;
    }

    return 0;
}