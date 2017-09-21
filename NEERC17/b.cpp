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
#define ii pair<tint,tint>

int main() {
    int n;
    cin >> n;

    vector<tint> v(n);
    forn(i,n) cin >> v[i];

    vector<vector<tint>> ls;
    set<ii> ord;

    forn(i,n) {
        tint x = v[i];
        auto it = ord.lower_bound({x,-1});

        if(it == ord.begin()) {
            ls.pb(vector<tint>(1,x));
            ord.insert({x, ls.size()-1});
        } else {
            it--;
            assert(x > it->fst);
            tint pos = it->snd;
            ls[pos].pb(x);
            ord.erase(it);
            ord.insert({x,pos});
        }
    }

    forn(i, ls.size()) {
        forn(j, ls[i].size()) {
            cout << ls[i][j];
            if(j+1 < ls[i].size())
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
