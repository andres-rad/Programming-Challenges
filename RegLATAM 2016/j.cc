#include <bits/stdc++.h>

#define ull unsigned long long
#define ui unsigned int
#define forsn(i, s, n) for (ull i = s; i < n; i++)
#define forn(i, n) forsn(i, 0, n)
#define dforsn(i, s, n) for (int i = n - 1; i >= s; i--)
#define dforn(i, n) dforsn(i, 0, n)
#define pb push_back
#define snd second
#define fst first

using namespace std;

bool isPrime(ull p) {
    ull end = sqrt(p);
    forsn(i,2,end+1) {
        if(p % i == 0) return false;
    }
    return true;
}

int main() {
    ull n;
    cin >> n;

    ull res = 0;
    dforn(i,n+1) {
        if(isPrime(i)) {
            res = i;
            break;
        }
    }

    cout << res << endl;
}
