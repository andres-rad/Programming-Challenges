#include <bits/stdc++.h>
using namespace std;
typedef long long tint;
#define forsn(i,s,n) for(tint i=(tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define dforsn(i,s,n) for(tint i=(tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
typedef pair<tint,tint> ii;

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

vector<tint> ss;
tint sMin = 100, sMax = 1, sSum = 0;

struct Node {
    tint sigue;
    tint rompe;
    tint nMin;
    tint nMax;
    tint nActual;
    tint nivel;
    tint padre;
};

vector<vector<Node>> t;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    tint n;
    cin >> n;
    
    ss.resize(n);
    forn(i,n) {
        string s;
        cin >> s;
        ss[i] = s.size();
        sMin = min(sMin, ss[i]);
        sMax = max(sMax, ss[i]);
        sSum += ss[i];
    }
    
    t.resize(n);
    
    // make t
    t[0].pb(Node{-1, -1, 0, sSum + n, 0, 0,-1});
    
    forsn(i,1,n) {
        antSz = ss[i-1];
        iSz = ss[i];
        forn(j, t[i-1].size()) {
            auto& nod = t[j];
            tint corte = nod.nActual + antSz + 1 + iSz;
            // romp
            if(nod.nMin < corte) {
                nod.rompe = t[i].size();
                t[i].pb(Node{-1,-1,nod.nMin, corte, 0, nod.nivel+1, j});
            }
            // sigue
            if(corte <= nod.nMax) {
                nod.sigue = t[i].size();
                t[i].pb(Node{-1,-1,corte, nod.nMax, nod.nActual + antSz + 1, nod.nivel, j});
            }
        }
    }
    
    // dfs
    
    
    return 0;
}
