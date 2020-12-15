#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

struct node {
    int children[26];
    bool isword;
}; struct node trie[mxN];

int n, m, k, nodecnt = 0;
string word;

void init() { nodecnt = 1; }

void add(string s) {
    int next, cur = 1;
    for(int i = 0; i < s.length(); i++) {
        next = trie[cur].children[s[i]-'a'];
        if(next == 0) {
            ++nodecnt;
            trie[cur].children[s[i]-'a'] = nodecnt;
            cur = nodecnt;
        } else cur = next;
    }
    trie[cur].isword = 1;
}

void remove(string s) {
    int cur = 1;
    for(int i = 0; i < s.length(); i++) {
        cur = trie[cur].children[s[i]-'a'];
        assert(cur != 0);
    }
    trie[cur].isword = 0;
}

bool check(string s) {
    int cur = 1;
    for(int i = 0; i < s.length(); i++) {
        cur = trie[cur].children[s[i]-'a'];
        if(cur == 0) return 0;
    }
    return trie[cur].isword;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    init();
    for(int i = 0; i < n; i++) {
        cin >> word;
        add(word);
    }
    for(int i = 0; i < m; i++) {
        cin >> word;
        remove(word);
    }
    for(int i = 0; i < k; i++) {
        cin >> word;
        cout << check(word) << "\n"; // 1 -> true, 0 -> false
    }
}
