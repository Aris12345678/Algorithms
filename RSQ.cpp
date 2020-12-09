#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n, q, k, i, j, t[4*mxN], a[mxN];

void build(int x, int y, int id) {
    if(x == y) t[id] = a[x];
    else {
        int md = (x+y)/2;
        build(x, md, 2*id);
        build(md+1, y, 2*id+1);
        t[id] = t[2*id]+t[2*id+1];
    }
}

void update(int pos, int val, int x, int y, int id) {
    if(x == y) t[id] = val;
    else {
        int md = (x+y)/2;
        if(pos <= md) update(pos, val, x, md, 2*id);
        else update(pos, val, md+1, y, 2*id+1);
        t[id] = t[2*id]+t[2*id+1];
    }
}

int query(int qx, int qy, int x, int y, int id) {
    if(qx <= x && y <= qy) return t[id];
    else if(y < qx || qy < x) return 0;
    int md = (x+y)/2;
    return query(qx, qy, x, md, 2*id)+query(qx, qy, md+1, y, 2*id+1);
}

int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    while(q--) {
        cin >> k >> i >> j;
        if(k == 1) cout << query(i, j, 1, n, 1) << "\n";
        else update(i, j, 1, n, 1);
    }
}
