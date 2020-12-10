#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e6+5;

int f[mxN];
string text, pattern;

void prefix() {
    f[0] = -1, f[1] = 0;
    for(int i = 2; i <= pattern.length(); i++) {
        int j = f[i-1];
        while(1) {
            if(pattern[j] == pattern[i-1]) { f[i] = j+1; break; }
            else if(j == 0) { f[i] = 0; break; }
            else j = f[j];
        }
    }
}

int kmp() {
    int i = 0, j = 0;
    while(1) {
        if(j == text.length()) break;
        if(text[j] == pattern[i]) {
            ++i, ++j;
            if(i == pattern.length()) return j;
        } else if(i > 0) i = f[i];
        else ++j;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> text;
    cin >> pattern;
    prefix();
    cout << kmp() << "\n";
}
