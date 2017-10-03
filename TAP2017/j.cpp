#include <bits/stdc++.h>
using namespace std;
#define tint long long 
#define ii pair<tint,tint>
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define fst first
#define snd second
#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

int k;
int nodes, src, dst;
vector<int> dist, q,work;

struct Edge {
	int to, rev;
	tint f, cap;
	Edge(int to, int rev, tint f, tint cap) : to(to), rev(rev), f(f), cap(cap) {}
};
vector<vector<Edge>> G;

void addEdge(int s, int t) {
	G[s].pb(Edge(t, G[t].size(), 0, 1));
	G[t].pb(Edge(s, G[s].size(), 0, 0));
}

bool dinic_bfs() {
	for(auto & c : dist) c = -1;
	dist[src] = 0;
	int qt = 0;
	q[qt++] = src;
	for(int qh=0; qh<qt; qh++) {
		int u = q[qh];
		for(auto &e : G[u]) {
			int v = e.to;
			if(dist[v]<0 && e.f < e.cap) {
				dist[v] = dist[u] + 1;
				q[qt++] = v;
			}
		}
	}
	return dist[dst] >= 0;
}

tint dinic_dfs(int u, tint f) {
	if(u == dst) return f;
	for(int &i = work[u]; i<G[u].size(); i++) {
		Edge &e = G[u][i];
		if(e.cap <= e.f) continue;
		int v = e.to;
		if(dist[v] == dist[u] + 1) {
			tint df = dinic_dfs(v, min(f, e.cap - e.f));
			if(df > 0) {
				e.f += df;
				G[v][e.rev].f -= df;
				return df;
			}
		}
	}
	return 0;
}

tint maxFlow(int _src, int _dst) {
	src = _src;
	dst = _dst;
	tint result = 0;
	while(dinic_bfs()) {
		for(auto & c : work) c = 0;
		while(tint delta = dinic_dfs(src, 1000000))
			result += delta;
	}
	return result;
}

int main() {
	tint n, m;
	cin >> n >> m;

	vector<set<int>> vecin;
	map<string, tint> nameton;
	int k = 0;
	forn(i,n) {
		vector<int> js(m);
		forn(j,m) {
			string s;
			cin >> s;

			if(nameton.find(s) == nameton.end()) {
				nameton[s] = k;
				k++;
				vecin.pb(set<int>());
			}
			js[j] = nameton[s];
		}
		forn(u, m) {
			forn(v, m) {
				if(u == v) continue;
				vecin[js[u]].insert(js[v]);
				vecin[js[v]].insert(js[u]);
			}
		}
	}

	// MATCHING
	nodes = 2*k+2;
	src = 2*k;
	dst = 2*k+1;
	dist = vector<int>(nodes);
	q = vector<int>(nodes);
	work = vector<int>(nodes);
	G = vector<vector<Edge>>(nodes);

	forn(u, k) {
		addEdge(src, u);
		addEdge(u+k, dst);
		forsn(v, u+1, k) {
			if(u == v) continue;
			if(vecin[u].find(v) != vecin[u].end())
				continue;
			addEdge(u,k+v);
			addEdge(v,k+u);
		}
	}

	tint v = maxFlow(src, dst);

	tint unicos = k - v/2;

	debug(k);
	debug(v);
	debug(unicos);
	if(unicos == m)
		cout << "S" << endl;
	else
		cout << "N" << endl;

	return 0;
}