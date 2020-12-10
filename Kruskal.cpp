#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n, m, par[mxN], height[mxN];
pair<int, pair<int, int> > adj[mxN];

void init() {
    for(int i = 0; i < n; i++) {
        par[i] = i;
        height[i] = 1;
    }
}

int find(int x) {
    while(x != par[x]) x = par[x];
    return x;
}

void unite(int x, int y) {
    if(height[x] > height[y]) swap(x, y);
    par[y] = x;
    height[x] += height[y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0, a, b, w; i < m; i++) {
        cin >> a >> b >> w, --a, --b;
        adj[i] = {w, {a, b}};
    }
    sort(adj, adj+m);
    init();
    int ans = 0, size = 0;
    for(int i = 0; i < m; i++) {
        int a = find(adj[i].second.first);
        int b = find(adj[i].second.second);
        if(a != b) { unite(a, b); ans += adj[i].first; ++size; }
        if(size == n-1) break;
    }
    cout << ans << "\n";
}
