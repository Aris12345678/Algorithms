#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6+5;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    set<int> s; // empty set
    // sets always keep the elements sorted

    // inserting elements
    s.insert(10); // [10]
    s.insert(30); // [10, 30]
    s.insert(20); // [10, 20, 30]
    s.insert(20); // [10, 20, 30]
    // set doesn't have duplicates

    cout << s.size() << "\n"; // 3

    // removing elements
    s.erase(s.find(10)); // [20, 30]
    s.erase(s.find(30)); // [20]

    // clearing a set
    s.clear();
    return 0;
}
