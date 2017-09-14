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

vector<vector<tint>> g;
int n;
vector<tint> d, d2;
//vector<tint> p;

tint bfs(tint r, vector<tint> &d) {
    queue<tint> q;
    d[r] = 0;
    q.push(r);
    tint v;
    while(q.size()) {
        v = q.front();
        q.pop();
        for(tint u : g[v]) {
            if(d[u] == -1) {
                d[u] = d[v] + 1;
                //p[u] = v;
                q.push(u);
            }
        }
    }
    return v;
}

int main() {
    int n;

    while(cin >> n) {
        if(n == -1) break;

        g = vector<vector<tint>>(n);
        d = vector<tint>(n, -1);
        d2 = vector<tint>(n, -1);
        //p = vector<tint>(n, -1);

        forsn(i, 1, n) {
            tint j;
            cin >> j;
            j--;
            g[i].pb(j);
            g[j].pb(i);
        }

        tint v;
        v = bfs(bfs(0, d2), d);

        tint diam = d[v];

        cout << (diam + 1) / 2 << endl;
    }

    return 0;
}
