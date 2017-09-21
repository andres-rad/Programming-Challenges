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
#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

int main() {
    int n;
    cin >> n;

    vector<tint> v(n);
    forn(i,n)
        cin >> v[i];

    vector<pair<tint,tint>> left(n,{0,0});
    vector<pair<tint,tint>> right(n,{0,0});

    forsn(i,1,n) {
        left[i].snd = max((tint)0, v[i-1]+left[i-1].snd+1-v[i]);
        left[i].fst = left[i-1].fst + left[i].snd;
    }
    dforn(i,n-1) {
        right[i].snd = max((tint)0, v[i+1]+right[i+1].snd+1-v[i]);
        right[i].fst = right[i+1].fst + right[i].snd;
    }

    tint res = 10e16;
    forn(i,n)
        res = min(res, right[i].fst + left[i].fst
                        - min(right[i].snd, left[i].snd));

    cout << res << endl;

    return 0;
}
