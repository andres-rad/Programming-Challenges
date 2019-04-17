#include <bits/stdc++.h>
using namespace std;
typedef long long tint;
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)


#ifdef DEBUG
#define debug(v) cerr << #v << ": " << (v) << endl;
#else
#define debug(v)
#endif

typedef tuple<tint, tint, tint> edge;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	tint n, m; cin >> n >> m;

	vector<vector<tuple<tint, tint, tint>>> g (n);
	forn(i, m){
		tint a, b, l , c; cin >> a >> b >> l >> c;
		a--; b--;
		g[a].push_back(make_tuple(l, c, b));
		g[b].push_back(make_tuple(l, c, a));
	}

	priority_queue<edge, vector<edge>, greater<edge>> q;
	q.push(make_tuple(0, 0, 0));
	tint ans = 0;
	vector<bool> vis(n, 0);

	while(!q.empty()){
		tint l, c, n;
		tie(l, c, n) = q.top(); q.pop();
		if (vis[n])
			continue;
		ans += c;
		vis[n] = 1;
		for (auto& e : g[n]){
			tint ll, cc, nn;
			tie(ll, cc, nn) = e;
			q.push(make_tuple(l+ll, cc, nn));
		}
	}
	cout << ans << endl;


	return 0;
}