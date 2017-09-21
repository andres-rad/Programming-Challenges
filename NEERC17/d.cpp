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
    tint n, t;
    cin >> n >> t;

    vector<tint> cost (n + 2, 0);

    forn(i, n){
        cin>>cost[i+1];
    }
    cost[n+1] = 2*t;

    multiset<tint> cola;

    int res = 0;


    cola.clear();
    forsn(i, 1, min(t + 1, n+2)){
        while (!cola.empty() && *cola.begin() < i){
            debug(*cola.begin());
            cola.erase(cola.begin());
        }
        debug(cola.size());
        res = max(res, (int)cola.size());
        cola.insert(t + i - cost[i]);
    }

/*
    forsn(i, 1, n+2){
        while (!cola.empty() && *cola.begin() <= i){
            debug(*cola.begin());
            cola.erase(cola.begin());
        }
        debug(cola.size());
        res = max(res, (int)cola.size() + (cost[i]<=t && i<t ? 1 : 0));
        cola.insert(t + i - cost[i]);
    }
*/
    cout<<res<<endl;


    return 0;
}
