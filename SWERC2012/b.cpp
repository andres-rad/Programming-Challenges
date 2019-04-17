#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(tint i=(tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i=(tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long tint;
#define sz(C) ((tint) C.size())

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	tint cases;
	cin >> cases;
	forn(cas, cases){
		string s,t;
		cin >> s >> t; 

		tint p01 = 0;
		tint p10 = 0;
		tint pQ0 = 0;
		tint pQ1 = 0;

		forn(i,s.length()) {
			if(s[i] == t[i]) continue;
			if(s[i] == '0') {
				p01++;
			} else if (s[i] == '1') {
				p10++;
			} else if(s[i] == '?') {
				if(t[i] == '0') pQ0++;
				else pQ1++;
			}
		}

		tint res = 0;

		tint inverses = min(p01, p10);
		p01 -= inverses;
		p10 -= inverses;
		res += inverses;

		if(p10 > 0) {
			if(pQ1 < p10) {
				res = -1;
			} else {
				res += 2 * p10;
				pQ1 -= p10;
				p10 = 0;

				res += pQ0 + pQ1;
			}
		} else {
			res += p01 + pQ0 + pQ1;
		}

		cout << "Case " << (cas+1) << ": " << res << endl;
	}

	return 0;
}