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

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << v << endl;
#else
#define debug(v) 
#endif

const int MAXN=100001;
const int LOGN=20;
//f[v][k] holds the 2^k father of v
//L[v] holds the level of v
int N, f[MAXN][LOGN], L[MAXN];

vector<tint> w;
vector<tint> dist;
vector<vector<int>> child;

//call before build:
void dfs(int v, int fa=-1, int lvl=0){
//generate required data
	f[v][0] = fa, L[v] = lvl;
	for(int u : child[v])
		dfs(u, v, lvl+1);
}
void build(){
//f[i][0] must be filled previously, O(nlgn)
	forn(k, LOGN-1) forn(i, N) f[i][k+1]=f[f[i][k]][k];
}
#define lg(x) (31-__builtin_clz(x))//=floor(log2(x))
int climb(int a, int d){//O(lgn)
	if(!d) return a;
	dforn(i, lg(L[a])+1) if(1<<i<=d) a=f[a][i], d-=1<<i;
    return a;
}
int lca(int a, int b){//O(lgn)
	if(L[a]<L[b]) swap(a, b);
	a=climb(a, L[a]-L[b]);
	if(a==b) return a;
	dforn(i, lg(L[a])+1) if(f[a][i]!=f[b][i]) a=f[a][i], b=f[b][i];
	return f[a][0];
}
//int dist(int a, int b) {//returns distance between nodes
//	return L[a]+L[b]-2*L[lca(a, b)];
//}

void bfsDist() {
	dist = vector<tint>(N);
	queue<int> q;
	q.push(0);

	while(q.size()) {
		int u = q.front();
		q.pop();

		int father = u == 0 ? 0 : f[u][0];
		dist[u] = dist[father] + w[u];

		for(int v : child[u]) q.push(v);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while(cin >> N){
		if(N == 0) break;

		w = vector<tint>(N);
		child = vector<vector<int>>(N);

		f[0][0] = -1;
		forsn(i,1,N) {
			int ai, li;
			cin >> ai >> li;

			f[i][0] = ai;
			w[i] = li;

			child[ai].pb(i);
		}
		dfs(0);
		build();

		bfsDist();

		tint q;
		cin >> q;
		forn(i,q) {
			int s,t;
			cin >> s >> t;

			int lcaNode = lca(s,t);

			cout << (dist[s] + dist[t] - 2 * dist[lcaNode]);

			if(i != q-1) cout << " ";
		}
		cout << endl;
	}

	return 0;
}