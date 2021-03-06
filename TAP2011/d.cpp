#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i=(tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i=(tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define pb push_back

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

int main() {
    int n;

    while(cin >> n) {
        if(n == -1) break;

        int m;
        cin >> m;

        tint res = 0;
        tint tempo = 0;
        forn(i,n) {
            tint l;
            cin >> l;
            res += tempo + l * m;
            tempo += l * m;
        }

        cout << res << endl;
    }

    return 0;
}
