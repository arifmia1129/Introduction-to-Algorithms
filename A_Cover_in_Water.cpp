#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        string s; cin >> s;

        int consecutiveCount = 0;
        int emptyCount = 0;

        for(char c : s) {
            if(c == '.') {
                consecutiveCount++;
                emptyCount++;

                if(consecutiveCount == 3) break;
            }else{
                consecutiveCount = 0;
            }
        }

        if(consecutiveCount == 3)
            cout << 2 << endl;
        else    
            cout << emptyCount << endl;
    }

    return 0;
}