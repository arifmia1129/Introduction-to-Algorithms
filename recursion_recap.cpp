#include<bits/stdc++.h>
using namespace std;

// void rec(int n) {
//     if(n > 5) return;

//     cout << n << endl;

//     rec(n + 1);
// }


// void rec(int n) {
//     if(n > 5) return;

//     rec(n + 1);

//     cout << n << endl;
// }

int rec(int n) {
    if(n > 5) return 0;

    int sum = rec(n + 1);

    return sum + n;
}

int main () {

    int sum = rec(1);

    cout << sum << endl;
    
    return 0;
}