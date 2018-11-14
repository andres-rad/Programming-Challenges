#include <bits/stdc++.h>
using namespace std;
typedef  long long tint;
#define forsn(i, s, n) for (int i = 0; i < n; i++)
#define forn(i, n) forsn(i, 0, n)

#define debug(v) //cerr << #v << ": " << v << endl;
// struct pto{
// 	tint x, y;
// 	pto(tint a, tint b):x(a), y(b){}
// 	pto operator-(pto a){return pto(x - a.x, y - a.y);}
// 	tint operator^(pto a){return x*a.y - y*a.x;}
// };

typedef complex<tint> pto;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	tint n; cin >> n;
	vector<pto> pp, p(n, pto(0, 0));
	forn(i, n){
		tint x, y; cin >> x >> y;
		pp.push_back(pto(x, y));
	}
	forn(i, n){
		p[i] = pp[i] - pp[(i - 1 + n)% n];
	}
	tint next = 0;
	tint size = 0;
	tint ans = n*(n-1ll)*(n-2ll);
	ans = ans / 6ll;
	debug(ans);
	forn(i, n){
		debug(i);
		debug(p[i].x);
		debug(p[i].y);
		size--;
		if (next == i){
			next++; size = 1;
			next = next%n;
		}
		debug(p[next].x);
		debug(p[next].y);
		debug((p[i]^p[next]));
		debug((p[next]^p[i]));
		// while((p[i]^p[next]) > 0 and next != i){
		while((conj(p[i]) * p[next]).imag() > 0 and next != i){
			next++;
			next = next%n;
			size++;
			debug(p[next].x);
		debug(p[next].y);
		debug((p[i]^p[next]));
		debug((p[next]^p[i]));
		}
		debug(size);
		debug(n-size);
		tint cant = n - size;
		cant = cant*(cant - 1ll);
		cant = cant/2ll;
		debug(cant);
		ans -= cant;
	}

	cout << ans << endl;
	return 0;
}
