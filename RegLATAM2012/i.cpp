#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define debug(v) cerr << #v << " = " << (v) << endl;
#define pb push_back

#define MAXN 100002
#define operacion(x,y) (x*y)

const int neutro = 1;
struct RMQ {
	int sz;
	int t[4*MAXN];
	int &operator[](int p){return t[sz+p];}
	void init(int n){
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
	}
	void updall() {
		dforn(i, sz) t[i] = operacion(t[2*i], t[2*i+1]);
	}
	int get(int i, int j) {return get(i,j,1,0,sz);}
	int get(int i, int j, int n, int a, int b) {
		if(j <= a || i >= b) return neutro;
		if(i <= a && b <= j) return t[n];
		int c = (a+b)/2;
		return operacion(get(i,j,2*n,a,c), get(i,j,2*n+1,c,b));
	}
	void set(int p, int val) {
		for(p+=sz; p>0 && t[p] != val;) {
			t[p] = val;
			p /= 2;
			val = operacion(t[p*2], t[p*2+1]);
		}
	}
} rmq;

int main() {
	tint n,k;
	while(cin >> n) {
		cin >> k;

		rmq.init(n);
		forn(i, n) {
			tint x;
			cin >> x;
			rmq[i] = x != 0 ? x/abs(x) : 0;
		}
		rmq.updall();

		forn(i,k) {
			/*cerr << endl;
			forn(j, n) {
				cerr << rmq.get(j,j+1) << " ";
			}
			cerr << endl;*/

			char c;
			cin >> c;

			if(c == 'C') {
				tint pos, x;
				cin >> pos >> x;
				x = x != 0 ? x/abs(x) : 0;
				rmq.set(pos-1, x);
			} else {
				tint u, v;
				cin >> u >> v;

				tint res = rmq.get(u-1,v);

				if(res == 0)
					cout << 0;
				else if(res > 0)
					cout << "+";
				else
					cout << "-";
			}
		}

		cout << endl;
	}
	return 0;
}