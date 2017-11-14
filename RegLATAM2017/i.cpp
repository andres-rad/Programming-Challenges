#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define first fst
#define second snd
#define push_back pb
#define make_pair mp
typedef long long tint;
typedef pair<tint, tint> ii;

#ifdef DEBUG
#define debug(v) cerr<< #v << " = " << v << endl;
#else 
#define debug(v) 
#endif
 
tint n,r;
map<ii, tint> edges;
vector<vector<int>> adj;

vector<int> _cl;
int cl(int i) {return (_cl[i] == -1 ? i : _cl[i] = cl(_cl[i])); }
void join(int i, int j) {if(cl(i) != cl(j)) _cl[cl(i)] = cl(j); }
void ini(int n) {
	_cl = vector<int>(n, -1);
}

struct Ar{int a,b,w;};
bool operator<(const Ar& a, const Ar& b){return a.w<b.w;}
vector<Ar> E;
tint kruskal(){
	tint cost=0;
	sort(E.begin(), E.end());
	ini(n);
	for(auto &t : E) {
		if(cl(t.a) != cl(t.b)) {
			join(a,b);
			cost += t.w;
			adj[a].pb(b);
			adj[b].pb(a);
		}
	}
	return cost;
}
/*
vector<tint> first;
vector<tint> last;
struct RMQ {
	#define LVL 10
	int vec[LVL][1<<(LVL+1)];
	int &operator[](int p){return vec[0][p];}
	int get(int i, int j) {
		int p = 31-__builtin_clz(j-i);
		return min(vec[p][i], vec[p][j-(1<<p)];
	}
	void build(int n) {
		int mp = 31 - __builtin_clz(n);
		forn(p,mp) forn(x, n-(1<<p))
			vec[p+1][x]=min(vec[p][x], vec[p][x+(1<<p)]);
	}
};
RMQ rmq;

vector<bool> vis;
int dfsC;

void _dfs(int u) {
	vis[u] = true;
	
	first[u] = dfsC;
	rmq[dfsC] = u;
	dfsC++;
	
	for(int v : adj[u]) {
		if(vis(v)) continue;
		_dfs(v);
	}
	
	last[u] = dfsC;
	rmq[dfsC] = u;
	dfsC++;
}

void dfs() {
	first = vector<tint>(n);
	last = vector<tint>(n);
	vis = vector<bool>(n,false);
	dfsC = 0;
	_dfs(0);
}
*/
  
int main(){
	cin >> n >> r;
	
	adj = vector<vector<int>>(n);
	
	forn(i,r) {
		tint a,b,w;
		a--;b--;
		edges[{a,b}] = w;
		edges[{b,a}] = w;
		E.pb({a,b,w});
	}
	
	tint base = kruskal();
	
	//dfs();
	//rmq.build(n);
	
	tint q;
	cin >> q;
	forn(i,q) {
		tint u,v;
		cin >> u >> v;
		u--; v--;
		
		minE = ;
		
		cout << base + edges[{u,v}] - minE << endl; 
	}
	
	return 0;
}
