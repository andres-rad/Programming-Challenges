#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define MAX_V 810
#define add(a, b, w) G[a].pb(make_pair(w, b))
#define debug(v) cerr << #v << ": " << (v) << endl;

typedef long long ll;
typedef pair<int,int> ii;
typedef double tipo;


int N = 210;
vector<vector<ii> > G(MAX_V);
//To add an edge use

ll dijkstra(int s, int t){//O(|E| log |V|)
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	vector<ll> dist(N, INF); vector<int> dad(N, -1);
	Q.push(make_pair(0, s)); dist[s] = 0;
	while(sz(Q)){
		ii p = Q.top(); Q.pop();
		if(p.snd == t) break;
		forall(it, G[p.snd])
			if(dist[p.snd]+it->first < dist[it->snd]){
				dist[it->snd] = dist[p.snd] + it->fst;
				dad[it->snd] = p.snd;
				Q.push(make_pair(dist[it->snd], it->snd));				}
	}
	return dist[t];
}
/////
// Modular Gaussian elimination
//
// Solves systems of linear modular equations.
//
// To use, build a matrix of coefficients and call run(mat, R, C, mod).
// If there is no solution, -1 will be returned, otherwise the number of free
// variables will be returned.
// If the i-th variable is free, row[i] will be -1, otherwise it's value will
// be ans[i].
//
// Time complexity: O(R * C^2)
//
// Constants to configure:
// - MAXC is the number of columns

// Constantes van en mat[][MAXC]
// Las constantes tiene que estar en [0..mod)
const int MAXC = 205;

int row[MAXC];
ll ans[MAXC];

ll power(ll a, ll b, ll mod) {
	ll ret = 1;
	for (; b; b /= 2) {
	  if (b % 2) ret = ret*a % mod;
	  a = a*a % mod;
	}
	return ret;
}

ll inv(ll x, ll mod) { return power(x, mod-2, mod); }

int run(vector<vector<ll> > mat, int R, int C, ll mod) {
	REP(i, C) row[i] = -1;

	int r = 0;
	REP(c, C) {
	  int k = r;
	  while (k < R && mat[k][c] == 0) ++k;
	  if (k == R) continue;

	  REP(j, C+1) swap(mat[r][j], mat[k][j]);
	  ll div = inv(mat[r][c], mod);

	  REP(i, R) if (i != r) {
	    ll w = mat[i][c] * (mod - div) % mod;
	    REP(j, C+1) mat[i][j] = (mat[i][j] + mat[r][j] * w) % mod;
	  }
	  row[c] = r++;
	}

	REP(i, C) {
	  int r = row[i];
	  ans[i] = r == -1 ? 0 : mat[r][C] * inv(mat[r][i], mod) % mod;
	}

	FOR(i, r, R) if (mat[i][C]) return -1;
	return C - r;
}


vector<vector<ii> > g;


int main() {
  	
	int n, a ,r, t;
	int vars = 0;
	cin >> n >> a >> r >> t;
	
	vector<vector<int> > coef(210, vector<int>(210, -1));
	vector<vector<ll> > mat(t, vector<ll>(210));
	vector<ii> inv_coef(210);

	forn(i, t){
		int d, p, start, fin;
		cin >> d >> p >> start;
		
		mat[i][MAXC] = d;
		forn(j, p-1){
			cin >> fin;
			
			int x = min(start, fin);
			int y = max(start, fin);
			
			if (coef[x][y] == -1) coef[x][y] = coef[y][x] = vars++;
			
			mat[i][coef[x][y]] = (mat[i][coef[x][y]] + 1) % 13;
			inv_coef[coef[x][y]] = {x,y};
			start = fin;
		}
	}

#ifdef DEBUG  	

	cerr << "mat" << endl;
	forn(yy, t) {
		forn(xx, vars) {
			cerr << mat[yy][xx] << " ";
		}
		cerr << " | " << mat[yy][MAXC] << " ";
		cerr << endl;
	}

	cerr << "row" << endl;
	forn(i, vars) {
		cerr << row[i] << " ";
	}
	cerr << endl;

	cerr << "ans" << endl;
	forn(i, vars) {
		cerr << ans[i] << " ";
	}
	cerr << endl;

#endif

	run(mat, t, 205, 13);

	G = vector<vector<ii> >(810, vector<ii>());
	forn(i, MAXC){
		if (row[i] != -1){
		ii temp = inv_coef[i];
			add(temp.fst, temp.snd, (ans[i] + 13) % 13);
			add(temp.snd, temp.fst, (ans[i] + 13) % 13);
		}
	}
	cout << dijkstra(a, r) << endl;
	return 0;
}
