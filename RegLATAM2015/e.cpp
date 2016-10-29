#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back

vector<int> pcost;
vector<vector<int>> adj;
vector<int> vis;
vector<int> costs;
vector<int> diffs;
int comps;

int sumcomps;

long d,p,r,b;

bool isPPP(int u) {
	return u >= d;
}

pair<int,int> dfs(int u, int comp) {
	if(vis[u] != -1) return {0,0};
	vis[u] = comp;

	int cost = pcost[u];
	int diff = isPPP(u) ? 1 : -1;

	for(auto v : adj[u]) {
		int cos, dif;
		tie(cos,dif) = dfs(v, comp);
		cost += cos;
		diff += dif;
	}

	//cout << u << " - " << cost << " " << diff << endl;
	return {cost,diff};
}

void getComps() {
	sumcomps = 0;
	comps = 0;
	vis = vector<int>(d+p, -1);
	costs = vector<int>();
	diffs = vector<int>();
	costs.reserve(200);
	diffs.reserve(200);

	forn(i,d+p) {
		if(vis[i] != -1) continue;
		//cout << "componente " << comps << endl;
		int cos, dif;
		tie(cos,dif) = dfs(i, comps);
		costs.pb(cos);
		diffs.pb(dif);
		sumcomps += cos;
		//cout << "cost y diff " << cos << " " << dif << endl;
		comps++;
	}
}

int knap(bool reverse) {
	int rev = reverse ? 1 : -1;
	//cerr << "reverse: " << (reverse ? "true" : "false") << endl;	

	vector<vector<int>> dp(b+1, vector<int>(comps+1, -1));
	forn(com, comps+1) {
		dp[0][com] = 0;
	}

	int best = dp[0][0];

	forsn(money, 1, b+1) {
		if(money > sumcomps) break;
		
		forsn(com, 1, comps+1) {
			dp[money][com] = dp[money][com-1];

			if(costs[com-1] <= money) {
				int other = dp[money-costs[com-1]][com-1];

				if(other >= 0) {
					dp[money][com] = max(dp[money][com],
						other + (diffs[com-1] * rev));
				}
			}
		}

		best = max(best, dp[money][comps]);
	}

	//forn(i,b+1) {
	//	cerr << i << ": ";
	//	forn(j,comps+1) {
	//		cerr << " " << dp[i][j];
	//	}
	//	cerr << endl;
	//}		cerr << endl;

	//cerr << "best: " << best << endl;	
	//cerr << "d: " << d << endl;	
	//cerr << "reverse: " << (reverse ? "true" : "false") << endl;	
	//cerr << "result: " << best + (reverse ? d : p) << endl;
	return best + (reverse ? d : p);
}

int main() {

	while(cin >> d) {
		cin >> p >> r >> b;

		pcost = vector<int>(d+p);
		adj = vector<vector<int>>(d+p);

		forn(i,d+p) {
			cin >> pcost[i];
		}
		forn(i,r) {
			int x,y;
			cin >> x >> y;
			y--;
			x--;
			y+=d;

			adj[y].pb(x);
			adj[x].pb(y);
		}

		getComps();

		//cerr << comps << " componentes" << endl;
		//forn(c,comps) {
		//	cerr << " $" << costs[c] << "(" << diffs[c] << ")";
		//}
		//cerr << endl;


		cout << knap(true) << " ";
		cout << knap(false) << endl;
	}
	
	return 0;
}