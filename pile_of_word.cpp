#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;

    while (t--)
    {
        int freArr1[27] = {0};
        int freArr2[27] = {0};

        string s1, s2; cin >> s1 >> s2;

        if(s1.size() == s2.size()) {

        for(char c : s1) {
            freArr1[c - 'a']++;
        }
        for(char c : s2) {
            freArr2[c - 'a']++;
        }

        bool flag = true;

        for(int i = 0; i < 27; i++) {
            if(freArr1[i] != freArr2[i]){
                flag = false;
                break;
            }
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
    

    return 0;
}