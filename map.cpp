#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6+5;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    map<int, int> mp; // empty map
    // maps always keep the elements sorted

    // inserting elements
    mp[10] = 1; // [(10, 1)]
    mp.insert({30, 3}); // [(10, 1), (30, 3)]
    mp[20]++; // [(10, 1), (20, 1), (30, 3)]
    mp[10]++; // [(10, 2), (20, 1), (30, 3)]

    cout << mp.size() << "\n"; // 3

    // removing elements
    mp.erase(10); // [(20, 1), (30, 3)]
    mp.erase(mp.find(30)); // [(20, 1)]

    // clearing a map
    mp.clear();
    return 0;
}
