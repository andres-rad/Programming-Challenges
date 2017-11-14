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

struct Interv {
	tint i,f,v;
};

vector<Interv> itvs;

struct Elem {
	set<tint> itvs;
	tint sum;
};
typedef vector<pair<bool,int>> Alt;

#define MAXN 100010
const Elem neutro = {set<tint>(),0};
const Alt neutro2 = vector<pair<bool,int>>();

Elem operacion(Elem q, Elem t) {
	Elem e;
	for(tint in : q.itvs) {
		e.itvs.insert(in);
	}
	for(tint in : t.itvs) {
		e.itvs.insert(in);
	}
	for(tint in : e.itvs) {
		e.sum += itvs[in].v;
	}
	return e;
}

struct RMQ {
	int sz;
	Elem t[4*MAXN];
	Alt dirty[4*MAXN];
	Elem &operator[](int p){return t[sz+p];}

	void init(int n) {
		sz = 1 << (32 - __builtin_clz(n));
		forn(i,2*sz) t[i] = neutro;
		forn(i,2*sz) dirty[i] = neutro2;
	}
	void push(int n, int a, int b) {
		if(dirty[n].size() > 0) {
			for(auto p : dirty[n]) {
				tint k = p.snd;
				Interv &in = itvs[k];

				if(in.f < a or b <= in.i) continue;
				if(p.fst) {
					t[n].itvs.insert(k);
					t[n].sum += in.v;	
				} else {
					t[n].itvs.erase(k);
					t[n].sum -= in.v;	
				}

				dirty[2*n].pb(p);
				dirty[2*n+1].pb(p);
			}
			dirty[n].empty();
		}
	}
	Elem get(int i, int j, int n, int a, int b) {
		if(j <=a or i >= b) return neutro;
		push(n, a ,b);
		if((i <= a) && (b <= j)) return t[n];
		int c=(a+b) / 2;
		return operacion(get(i,j,2*n,a,c), get(i,j,2*n+1, c,b));
	}
	Elem get(int i, int j) {
		return get(i,j,1,0,sz);
	}
	void alterar(pair<bool,int> val, int i, int j, int n, int a, int b) {
		push(n,a,b);
		if(j<=a || i>=b) return;
		if(i<=a && b <= j) {
			dirty[n].pb(val);
			push(n,a,b);
			return;
		}
		int c=(a+b)/2;
		alterar(val, i, j, 2*n, a, c);
		alterar(val, i, j, 2*n + 1, c, b);
		t[n] = operacion(t[2*n], t[2*n+1]);
	}
	void alterar(pair<bool,int> val, int i, int j) {
		alterar(val,i,j,1,0,sz);
	}
} rmq;

int main() {
	tint q;
	cin >> q;

	RMQ r;

	r.init(MAXN);

	forn(qq,q) {
		int op;
		cin >> op;
		if(op == 1) {
			int i,f,v;
			cin >> i >> f >> v;

			Interv in = {i,f,v};
			tint k = itvs.size();
			itvs.pb(in);
			r.alterar({true, k}, i, f);
		} else if(op == 2) {
			int k;
			cin >> k;
			k--;

			Interv in = itvs[k];
			r.alterar({false, k}, in.i, in.f);
		} else if(op == 3) {
			int a,b;
			cin >> a >> b;
			a--; b--;
			Elem e = r.get(a,b);
			cout << e.sum << endl;
		}
	}

	return 0;
}