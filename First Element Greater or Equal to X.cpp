#include <bits/stdc++.h>
using namespace std;

const long mxN = 1e6+5;

void first_greater_or_equal(int n, int a[], int x) {
    int st = 0, en = n-1, md, ans = -1;
    while(st <= en) {
        md = (st+en)/2;
        if(a[md] >= x) ans = md, end = md-1;
        else st = md+1;
    }
    return ans;
}
