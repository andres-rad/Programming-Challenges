#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(tint i=(tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i=(tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long tint;
#define sz(C) ((tint) C.size())

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	int caso = 0;
	while(caso++ < t){
		cout << "Case " << caso << ": ";
		int n, m;
		cin >> n >> m;
		// while(n > 500);
		vector<vector<int>> ady (n);

		forn(i, m){
			int a, b;
			cin >> a >> b;
			ady[a].pb(b);
			ady[b].pb(a);
		}

		int ans = 100000;
		forn(i, n){
			// BFS de cada uno
			queue<pair<int, int>> q;
			q.push({i, -1});
			vector<int> dist(n, 0);
			int anstmp = 100000;

			while(not q.empty()){
				auto prox = q.front(); q.pop();
				debug (prox.fst);

				// if (dist[prox.fst] = dist[prox.snd] + 1;

				for (auto& v : ady[prox.fst]){
					if (v != prox.snd and dist[v] != 0){
						anstmp = min(anstmp, dist[v] + dist[prox.fst] + 1);
						// break;
					}else if ((not dist[v]) and v != prox.snd){
						dist[v] = 1 + dist[prox.fst];
						q.push({v, prox.fst});
					}
				}
			}
			ans = min(ans, anstmp);
			// cout << dist[i] << endl;
		}

		if (ans == 100000){
			cout <<"impossible" << (caso < t ? "\n" : "\n");
		}else{
			cout << ans << (caso < t ? "\n" : "\n");
		}
	}
	return 0;
}