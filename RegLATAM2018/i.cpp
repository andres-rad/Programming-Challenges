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
tint ans;
	vector<vector<tint>> g;
int dfs(int node){
	vector<tint> t = {0, 0, 0};
	for(auto v : g[node]){
		t[dfs(v)]++;
	}
	debug(node);
	assert(t[0] + t[1] + t[2] == g[node].size());
	debug(t[0]);
	debug(t[1]);
	debug(t[2]);
	ans += t[2];

	if(t[0] + t[1] >= 3 and t[1] >= 1){
		return 2;
	}else if (t[0] + t[1]>= 2){
		return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	tint n;
	cin >> n;
	// g.resize(n);
	g = vector<vector<tint>> (n);
	forn(i, n-1){
		int p; cin >> p;
		g[p-1].push_back(i + 1);
	}
	ans = 0;
	dfs(0);
	cout << ans << endl;


	return 0;
}