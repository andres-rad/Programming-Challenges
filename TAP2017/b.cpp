#include <bits/stdc++.h>
using namespace std;
#define tint long long 
#define ii pair<tint,tint>
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

int main() {
	tint n;
	cin >> n;

	vector<tint> ps(n);
	vector<tint> cs(n);

	forn(i,n) cin >> ps[i];
	forn(i,n) cin >> cs[i];

	sort(ps.rbegin(), ps.rend());
	sort(cs.rbegin(), cs.rend());

	tint c = 0;
	tint res = 1;
	forn(p, n) {
		while(c < n && cs[c] >= ps[p]) {
			c++;
		}

		tint cchoose = c - p;
		res *= cchoose;
		res %= 1000000007;
	}

		res %= 1000000007;

	cout << res << endl;

	return 0;
}