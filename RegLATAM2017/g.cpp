#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define fst first
#define snd second
#define push_back pb
#define make_pair mp
typedef long long tint;
typedef pair<int, int> ii;

#ifdef DEBUG
#define debug(v) cerr<< #v << " = " << v << endl;
#else 
#define debug(v) 
#endif

#define MOD 1000000007

const int q0 = 0;
const int q1 = 2;
const int d0 = 0;
const int d1 = 1;

int n;
vector<ii> hij;
vector<int> type;

vector<array<tint,4>> din;

tint uno = 1; // yay
tint cero = 0;

tint &d(int u, int quiero, int da) {
	if(u >= 0) {
		return din[u][quiero*2 + da];
	} else if(quiero == da) {
		return uno;
	} else {
		return cero;
	};
}

void dfs(int u) {
	if(u == -1) return;
	
	int a = hij[u].fst;
	int b = hij[u].snd;
	
	dfs(a);
	dfs(b);
	
	// calcular para no cortocircuitada
	d(u,0,0) = d(a,1,1) * d(b,1,1);
	d(u,0,0) %= MOD;
	
	d(u,0,1) = d(a,1,1) * d(b,1,0)
			 + d(a,1,0) * d(b,1,1)
			 + d(a,1,0) * d(b,1,0);
	d(u,0,1) %= MOD;
	
	d(u,1,0) = d(a,0,1) * d(b,0,1)
			 + d(a,1,1) * d(b,0,1)
			 + d(a,0,1) * d(b,1,1);
	d(u,1,0) %= MOD;
	
	d(u,1,1) = d(a,0,0) * d(b,0,0)
			 + d(a,0,1) * d(b,0,0)
			 + d(a,0,0) * d(b,0,1)
			 
			 + d(a,1,1) * d(b,0,0)
			 + d(a,1,0) * d(b,0,0)
			 + d(a,1,0) * d(b,0,1)
			 
			 + d(a,0,0) * d(b,1,1)
			 + d(a,0,0) * d(b,1,0)
			 + d(a,0,1) * d(b,1,0);
	d(u,1,1) %= MOD;
	
	// corto
	if(type[u] == 0) {
		d(u,0,0) += d(u,0,1);
		d(u,0,1) = 0;
		d(u,0,0) %= MOD;
		
		d(u,1,0) += d(u,1,1);
		d(u,1,1) = 0;
		d(u,1,0) %= MOD;
	} else if(type[u] == 1) {
		d(u,0,1) += d(u,0,0);
		d(u,0,0) = 0;
		d(u,0,1) %= MOD;
		
		d(u,1,1) += d(u,1,0);
		d(u,1,0) = 0;
		d(u,1,1) %= MOD;
	}
}
  
int main(){
	cin >> n;
	
	hij = vector<ii>(n, {-1,-1});
	type = vector<int>(n);
	din = vector<array<tint,4>>(n, {0,0,0,0});
	
	forn(i,n) {
		int x,y,f;
		cin >> x >> y >> f;
		x--; y--;
		hij[i] = {x,y};
		type[i] = f;
	}
	
	dfs(0);
	
	assert(cero == 0);
	assert(uno == 1);
	
	int root = 0;
	tint res = d(root,0,1) + d(root,1,0);
	res %= MOD;
	
	cout << res << endl;
	
	return 0;
}
