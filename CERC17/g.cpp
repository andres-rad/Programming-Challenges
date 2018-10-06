#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) //cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;

struct node{
	bool proc;
	int vis;
	double val;
	vector<int> ady;
};

vector<node> g;

void dijkstra(int start){
	std::priority_queue<pair<double, int>, std::vector<pair<double, int>>, std::greater<pair<double, int>> > p;

	p.push({g[start].val * ((double)g[start].ady.size()/(double)g[start].vis), start});

	while(not p.empty()){
		int n = p.top().second; 

		double v = p.top().first;
		p.pop();
		if(g[n].proc) continue;
		debug(n);
		debug(v);
		g[n].proc = true;
		// g[n].vis = g[n].ady.size();

		for (auto h : g[n].ady){
			if (! g[h].proc){
				g[h].val += v*(1.0/(double)g[h].ady.size());
				g[h].vis++;
				p.push({g[h].val * ((double)g[h].ady.size()/(double)g[h].vis), h});
			}
		}
	}
}



int main() {
	int n;

	while(cin >> n){
		int m;
		cin >> m;

		g = vector<node> (n, {false, 0, 1.0, vector<int> ()});

		forn(i, m){
			int a, b;
			cin >> a>>b;
			a--;b--;
			g[a].ady.pb(b);
			g[b].ady.pb(a);
		}

		g[n-1].vis = g[n-1].ady.size();
		g[n-1].val = 0.0;

		dijkstra(n-1);

		// for(auto n : g){
		// 	debug(((double)n.ady.size()));
		// 	debug(((double)n.ady.size()/(double)n.vis));
		// 	debug(n.val*((double)n.ady.size()/(double)n.vis));
		// }
		
		cout << fixed << setprecision(10) << g[0].val << endl;
	}	
	return 0;
}