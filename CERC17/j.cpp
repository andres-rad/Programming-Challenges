#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) //cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;


int n, nn;
vector<vector<int>> g;

int dfs(int s, int p = -1){
	int sum = 1;
	for (auto n : g[s]){
		if (n == p) continue;
		int res = dfs(n, s);
		if (res == -1) {
			debug(s);
			debug(p);
			debug(-1);
			return -1;
		}
		sum += res;
	}
	debug(s);
	debug(p);
	debug((sum > nn ? -1 : sum % nn));
	return (sum > nn ? -1 : sum % nn);	
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while (cin >> n){
		g = vector<vector<int>> (n);

		forn(i, n-1){
			int a, b;
			cin >> a >> b;
			a--; b--;
			g[a].pb(b);
			g[b].pb(a);
		}

		int s = 0;
		forn(i, n){
			if (g[i].size() == 1){
				s = i; break;
			}
		}
		debug(s);

		int cnt = 0;

		forsn(i, 2,  n+1){
				debug("======================================");
				debug(i);
				debug((n/i)*i);
				debug(n/i);
				nn = n/i;
				debug(dfs(0));
			if ((n/i)*i == n and (nn = n/i) and dfs(s) == 0){
				cout << (cnt > 0 ? " " : "") << i-1;
				cnt++;
			}
		}

		cout << endl;
	}

	return 0;
}