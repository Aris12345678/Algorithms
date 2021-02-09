#include <bits/stdc++.h>
using namespace std;

const long mxN = 1e6+5;

void sieve_of_eratosthenes(long n) {
    bool primes[n+5];
    memset(primes, true, sizeof primes);
    primes[0] = primes[1] = false;
    for(int i = 2; i*i <= n; i++) {
        if(primes[i]) for(int j = i*i; j <= n; j+=i) primes[j] = false;
    }
    for(int i = 0; i <= n; i++) {
        if(primes[i]) cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long n;
    cin >> n;
    sieve_of_eratosthenes(n);
    return 0;
}
