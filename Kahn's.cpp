#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n, m, in[mxN], order[mxN], id = 0;
vector<int> adj[mxN];

void kahn() {
    for(int i = 0; i < n; i++) {
        for(auto& u : adj[i]) ++in[u];
    }
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int u = q.front();
        order[id++] = u;
        q.pop();
        for(auto& v : adj[u]) {
            --in[v];
            if(in[v] == 0) q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
    }
    kahn();
    if(id != n) cout << "Graph contains a cycle\n";
    else {
        for(int i = 0; i < n; i++) cout << order[i] << " ";
    }
}
