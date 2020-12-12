#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n, m, low[mxN], num[mxN], curnum = 0;
vector<int> adj[mxN];
bool in[mxN];
stack<int> comp;

void scc(int u) {
    comp.push(u);
    in[u] = 1;
    low[u] = num[u] = curnum++;
    for(auto& v : adj[u]) {
        if(num[v] == -1) { scc(v); low[u] = min(low[u], low[v]); }
        else if(in[v]) low[u] = min(low[u], num[v]);
    }
    if(num[u] == low[u]) {
        cout << "Comp: ";
        while(1) {
            int cur = comp.top();
            comp.pop();
            in[cur] = 0;
            cout << cur+1 << " ";
            if(cur == u) break;
        }
    }
    cout << "\n";
}

void init() {
    fill(num, num+n, -1);
    for(int i = 0; i < n; i++) {
        if(num[i] == -1) scc(i);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
    }
    init();
}
