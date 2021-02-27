#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6+5;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    vector<int> a = {1, 3, 4, 8, 6, 1, 4, 2}; // input array A
    vector<pair<int, int> > q; // input array Q
    // inserting the queries
    q.push_back({0, 3});
    q.push_back({3, 5});
    q.push_back({5, 7});
    q.push_back({2, 6});
    vector<int> p; // prefix sum array P
    p.push_back(a[0]);
    for(int i = 1; i < a.size(); i++)
        p.push_back(a[i]+p[i-1]); // creating prefix sum array P
    for(int i = 0; i < q.size(); i++) {
        // answer the queries with the help of prefix sum array P
        if(q[i].first == 0) cout << p[q[i].second] << "\n";
        else cout << p[q[i].second]-p[q[i].first-1] << "\n";
    }
    return 0;
}
