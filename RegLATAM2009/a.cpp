#include <bits/stdc++.h>
using namespace std;
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n); i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long tint;
typedef pair<tint,tint> ii;

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << v << endl;
#else
#define debug(v)
#endif

tint n, t;
vector<tint> f;
vector<tint> c;
vector<vector<tint>> adj;

tint calc(tint v) {
	tint child = adj[v].size();
	if(child == 0) {
		return 1;
	}

	tint needed = (child * t - 1) / 100 + 1;
	debug(child);
	debug(t);
	debug(needed);

	set<ii> s;
	for(tint u : adj[v]) {
		s.insert({c[u],u});
		if(s.size() > needed){
			auto it = s.end();
			it--;
			s.erase(it);
		}
	}

	debug(s.size());

	tint res = 0;
	for(ii cc : s) {
		res += cc.fst;
	}

	return res;
}

void dfs(tint v) {
	for(tint u : adj[v]) {
		dfs(u);
	}
	debug(v);
	c[v] = calc(v);
	debug(c[v]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while(cin >> n >> t) {
		if(n == 0) break;

		f = vector<tint>(n+1);
		c = vector<tint>(n+1);
		adj = vector<vector<tint>>(n+1);
		forn(i,n) {
			cin >> f[i+1];
			adj[f[i+1]].pb(i+1);
		}

		 dfs(0);
		tint res =c[0];
		cout << res << endl;
	}

	return 0;
}
