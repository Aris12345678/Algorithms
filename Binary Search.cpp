#include <bits/stdc++.h>
using namespace std;

const long mxN = 1e6+5;

void binary_search(int n, int a[], int x) {
    int st = 0, en = n-1, md;
    while(st <= en) {
        md = (st+en)/2;
        if(a[md] == x) return md;
        else if(a[md] > x) en = md-1;
        else st = md+1;
    }
    return -1;
}
