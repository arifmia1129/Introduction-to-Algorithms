#include<bits/stdc++.h>
using namespace std;



class cmp {
    public:
       bool operator()(pair<string, int> a, pair<string, int> b) {
        return a.second < b.second;
    }   
};

int main () {
    int n; cin >> n;
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;

    while(n--) {
        string name;
        int marks; cin >> name >> marks;

        pq.push({name, marks});
    }

    while(!pq.empty()){
        auto pqTop = pq.top();

        cout << pqTop.first << "---> " << pqTop.second << endl;

        pq.pop();
    }

    return 0;
}