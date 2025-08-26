#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        string s; cin >> s;

        int cnt = 0;

        for(char ch : s) {
            if(ch == '1')
                cnt++;
        }


        int sum = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '0')
               sum += cnt + 1;
            else    
                sum += cnt - 1;
        }

        cout << sum << endl;;
    }
    return 0;
}