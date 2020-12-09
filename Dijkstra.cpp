#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;
const int inf = 1e9+7;

int n, m, dist[mxN];
vector<pair<int, int> > adj[mxN];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    fill(dist, dist+n, inf);
    dist[s] = 0;
    pq.push({s, 0});
    while(!pq.empty()) {
        int u = pq.top().first, w = pq.top().second;
        pq.pop();
        if(dist[u] < w) continue;
        for(auto& v : adj[u]) {
            if(dist[v.first] > dist[u]+v.second) {
                dist[v.first] = dist[u]+v.second;
                pq.push({v.first, dist[v.first]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0, a, b, w; i < m; i++) {
        cin >> a >> b >> w, --a, --b;
        adj[a].push_back({b, w});
    }
    dijkstra(0);
    for(int i = 0; i < n; i++) cout << dist[i] << " "; cout << "\n";
}
