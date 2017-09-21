#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)((n)-1); i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define pb push_back
#define debug(v)



int main() {
    tint n;
    cin >> n;

    vector<tint> v(n);
    forn(i,n) cin >> v[i];

    tint d = v[1] - v[0];
    bool ok = true;
    forn(i,n-1) {
        if(v[i+1] - v[i] != d) {
            ok = false;
            break;
        }
    }

    if(ok)
        cout << d + v[v.size()-1] << endl;
    else
        cout << v[v.size()-1] << endl;

    return 0;
}
