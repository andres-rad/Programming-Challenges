#include <bits/stdc++.h>
using namespace std;
typedef long long tint;
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define pb push_back

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << (v) << endl;
#else
#define debug(v)
#endif

vector<vector<pair<tint, int>>> g;
vector<tint>  vis, otro;
set<tint> dist;
tint best, cnt, fail, szA, szB;
vector<vector<tint>> dists;

tint sgn(tint a){
	if (a){
		return a < 0 ? -1 : 1;
	}else{
		return 0;
	}
}

void color(tint n, tint d, tint col = 0){
	debug(n);
	debug(d);
	debug(col);
	if (col){
		// szB++;
		vis[n] = -cnt;
	}else{
		vis[n] = cnt;
		// szA++;
	}
	// cnt++;

	auto it = g[n].rbegin();
	while(it != g[n].rend() and it->first > d){
		debug(it->second);
		debug(it->first);
		tint a = vis[it->second];

		if (abs(a) < cnt){
			color(it->second, d, 1 - col);
		}else if ((sgn(a) > 0 and !col) or (sgn(a) < 0 and col)){
			fail = 1;
		}
		it++;


		if (fail)
			return;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	tint n; cin >> n;

	g = vector<vector<pair<tint, int>>> (n);
	vis = vector<tint> (n, 0);
	dists = vector<vector<tint>> (n, vector<tint> (n, 0));
	forn(i, n-1){
		forn(j, n - 1 - i){
			tint d; cin >> d;
			g[i].pb({d, i + j + 1});
			g[i + j + 1].pb({d, i});
			dist.insert(d);
			dists[i][j] = d;
			dists[j][i] = d;
		}
	}
	forn(i, n)
		dists[i][i] = 0;

	best = 1e12;
	cnt = 0;


	forn(i, n){
		sort(g[i].begin(), g[i].end());
	}
	// sort(dist.begin(), dist.end());

	for (auto e : dist){
		debug("=================");
		debug(e);
		debug("===========");
		cnt++;
		// szA = szB = 0;
		fail = 0;
		forn(i, n){
			if (abs(vis[i]) < cnt)
				color(i, e);
		}
		if (!fail){
			tint ansA = 0, ansB = 0;
			forn (i, n){
				forsn(j, i+1, n){
					if (vis[i] < 0 and vis[j] < 0 ){
						ansA = max(ansA, dists[i][j]);
					}else if (vis[i] > 0 and vis[j] > 0){
						ansB = max(ansB, dists[i][j]);
					}
				}
			}
			best = min(best, ansA + ansB);
		}
	}
	cout << best << endl;


	return 0;
}