#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n, q, k, i, j, b, a[mxN], t[4*mxN], l[4*mxN];

void build(int x, int y, int id) {
    if(x == y) { t[id] = a[x]; return; }
    int md = (x+y)/2;
    build(x, md, 2*id);
    build(md+1, y, 2*id+1);
    t[id] = t[2*id]+t[2*id+1];
}

void push(int x, int y, int id) {
    if(l[id] != 0) {
        int dx = l[id];
        l[id] = 0;
        t[id] += dx*(y-x+1);
        if(x != y) l[2*id] += dx, l[2*id+1] += dx;
    }
}

void update(int x, int y, int ux, int uy, int val, int id) {
    push(x, y, id);
    if(x > uy || ux > y) return;
    if(x >= ux && uy >= y) {
        int dx = (y-x+1)*val;
        t[id] += dx;
        if(x != y) l[2*id] += val, l[2*id+1] += val;
        return;
    }
    int md = (x+y)/2;
    update(x, md, ux, uy, val, 2*id);
    update(md+1, y, ux, uy, val, 2*id+1);
    t[id] = t[2*id]+t[2*id+1];
}

int query(int x, int y, int qx, int qy, int id) {
    push(x, y, id);
    if(x > qy || qx > y) return 0;
    if(x >= qx && qy >= y) return t[id];
    int md = (x+y)/2;
    return query(x, md, qx, qy, 2*id)+query(md+1, y, qx, qy, 2*id+1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    while(q--) {
        cin >> k;
        if(k == 1) {
            cin >> i >> j >> b;
            update(1, n, i, j, b, 1);
        } else {
            cin >> i >> j;
            cout << query(1, n, i, j, 1) << "\n";
        }
    }
}
