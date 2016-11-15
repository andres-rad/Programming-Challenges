#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n; i-->s;)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define pb push_back

int main() {

    int k2,k3,k5,k6;
    cin >> k2 >> k3 >> k5 >> k6;

    int dos = min(k5,k6);
    dos = min(dos,k2);

    int tres = min(k3, k2 - dos);

    ull res = dos * 256 + tres * 32;
    cout << res << endl;

    return 0;
}
