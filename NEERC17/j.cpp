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
#define ii pair<tint,tint>

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif


tint res;
tint n,m;
vector<bool> vis;
vector<ii> resEdg;
vector<set<tint>> adj;
vector<tint> countDirig;

void run(tint root) {
    set<ii> cant;
    vector<set<ii>::iterator> its(n, cant.end());

    tint nn = 0, mm = 0;

    set<tint> bfsS;
    bfsS.insert(root);
    vis[root] = true;
    while(bfsS.size()) {
        tint u = *bfsS.begin();
        bfsS.erase(bfsS.begin());

        nn++;
        mm += adj[u].size();

        if(adj[u].size()) {
            its[u] = cant.insert({adj[u].size(), u}).fst;
        }
        for(tint v : adj[u]) {
            if(vis[v]) continue;
            bfsS.insert(v);
            vis[v] = true;
        }
    }
    mm /= 2;

    tint cota = (mm+nn-1)/nn;

    while(cant.size()) {
        ii elem = *cant.begin();
        tint u = elem.snd;

        // Agarrar elmm primero
        tint v = *adj[u].begin();
        adj[u].erase(v);
        adj[v].erase(u);
        resEdg.pb({u,v});

        countDirig[u]++;
        res = max(res, countDirig[u]);

        debug(u+1);
        debug(v+1);
        debug(adj[u].size());
        debug(adj[v].size());

        if(its[v] != cant.end())
            cant.erase(its[v]);
        if(adj[v].size() > 0)
            its[v] = cant.insert({adj[v].size(), v}).fst;
        else
            its[v] = cant.end();

        cant.erase(its[u]);
        if(adj[u].size() > 0 and countDirig[u] < cota)
            its[u] = cant.insert({adj[u].size(), u}).fst;
        else
            its[u] = cant.end();
    }
}

int main() {
    cin >> n >> m;

    vis = vector<bool>(n);
    adj = vector<set<tint>>(n);
    countDirig = vector<tint>(n,0);
    res = 0;

    forn(i,m) {
        tint u,v ;
        cin >> u >> v;
        u--;v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    forn(i,n) {
        if(vis[i]) continue;
        run(i);
    }

    cout << res << endl;
    for(ii r : resEdg) {
        cout << r.fst+1 << " " << r.snd+1 << endl;
    }

    return 0;
}
