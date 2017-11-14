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
#define ii pair<tint, tint>

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

struct cat {
    ii pos;
    tint f;
};

vector<vector<pair<double, tint>>> g;

double dist(ii a, ii b, tint f) {
    double d1 = sqrt((a.fst - b.fst) * (a.fst - b.fst)
                   + (a.snd - b.snd) * (a.snd - b.snd));
    double d2 = abs(d1 - (double)f);
    return min(d1, d2);
}

double dijkstra(tint s, tint t, tint n) {
    priority_queue<pair<tint,tint>, vector<ii>, greater<ii>> q;
    vector<double> dist(n, 1e12);
    vector<tint> dad(n, -1);
    q.push({0, s});
    dist[s] = 0;

    while(q.size()) {
        ii p = q.top();
        q.pop();
        if(p.snd == t) break;

        for(auto it : g[p.snd]) {
            if(dist[p.snd] + it.fst < dist[it.snd]) {
                dist[it.snd] = dist[p.snd] + it.fst;
                dad[it.snd] = p.snd;
                q.push({dist[it.snd], it.snd});
            }
        }
    }
    return dist[t];
}

int main() {
    int n;

    while(cin >> n) {
        if(n == -1) break;

        vector<cat> cats(n);

        ii p;
        ii l;
        cin >> p.fst >> p.snd >> l.fst >> l.snd;

        forn(i,n) {
            cin >> cats[i].pos.fst >> cats[i].pos.snd >> cats[i].f;
        }

        // g[n] = salida, g[n+1] = llegada
        g = vector<vector<pair<double, tint>>>(n+2);

        g[n].pb({dist(p, l, 0), n+1});
        forn(i,n) {
            g[n].pb({dist(p, cats[i].pos, 0), i});
            g[i].pb({dist(cats[i].pos, l, cats[i].f), n+1});

            forn(j, n) {
                if(i == j) continue;
                g[i].pb({dist(cats[i].pos, cats[j].pos, cats[i].f), j});
            }
        }

        cout << setprecision(2) << fixed << dijkstra(n, n+1, n+2) << endl;
    }

    return 0;
}
