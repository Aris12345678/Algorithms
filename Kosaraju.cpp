#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n, m, scc = 0, ans[mxN];
vector<int> adj[mxN], radj[mxN];
bool vis[mxN], rvis[mxN];
stack<int> fin;

void dfs1(int u) {
    vis[u] = 1;
    for(auto& v : adj[u]) {
        if(!vis[v]) dfs1(v);
    }
    fin.push(u);
}

void dfs2(int u) {
    rvis[u] = 1;
    ans[u] = scc;
    for(auto& v : radj[u]) {
        if(!rvis[v]) dfs2(v);
    }
}

void kosaraju() {
    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs1(i);
    }
    while(!fin.empty()) {
        if(!rvis[fin.top()]) { dfs2(fin.top()); ++scc; }
        fin.pop();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    kosaraju();
    cout << scc << "\n"; // printing the number of the strongly connected compononents
    for(int i = 0; i < n; i++) cout << ans[i]+1 << " "; // printing the compononent of each vertex
}
