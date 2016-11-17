#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n; i-->s;)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define pb push_back

vector<bool> c;
vector<vector<ll>> adj;
vector<vector<ll>> adj2;
ll counter = 0;

void compress(ll u, ll padre, ll snode) {

    for(ll v : adj[u]) {
        if(v == padre) continue;

        ll snext = snode;
        if(c[v] != c[u]) {
            adj2.pb({});
            counter++;
            adj2[snode].pb(counter);
            adj2[counter].pb(snode);
            snext = counter;
        }

        compress(v, u, snext);
    }
}

ll bfs(ll r, vector<ll> &d) {
    queue<ll> q;
    d[r] = 0;
    q.push(r);
    ll v;
    while(q.size()) {
        v=q.front();
        q.pop();
        for(ll u : adj2[v]) {
            if(d[u] != -1) continue;
            d[u] = d[v]+1;
            q.push(u);
        }
    }
    return v;
}

ll diam() {
    vector<ll> d(adj2.size(), -1);
    vector<ll> d2(adj2.size(), -1);

    int v = bfs(bfs(0, d2), d);
    return d[v];
}

int main() {
    ll n;
    cin >> n;

    c = vector<bool>(n);
    adj = vector<vector<ll>>(n);

    forn(i,n) {
        bool b;
        cin >> b;
        c[i] = b;
    }

    forn(i,n-1) {
        ll a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    adj2 = vector<vector<ll>>(1);

    compress(0, -1, 0);
    ll res = (diam()+1) / 2;

    cout << res << endl;

    return 0;
}
