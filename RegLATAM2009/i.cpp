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

int main() {
	//ios::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin >> n){
		if(n == 0) break;
		tint res = 0;
		vector<pair<tint, tint> > ptos;
		forn(i, n){
			tint x, y;
			cin >> x >> y;
			ptos.pb(mp(x, y));
		}
		unordered_map<tint, tint> m;
		forn(i, n){
			m.clear();

			forn(j, n){
				tint dist = (ptos[i].fst - ptos[j].fst) * (ptos[i].fst - ptos[j].fst) + (ptos[i].snd - ptos[j].snd) * (ptos[i].snd - ptos[j].snd);
				m[dist]++;
			}

			for(auto tupla: m){
				tint k = tupla.snd;
				res += k*(k-1)/2;
			}
		}

		cout << res << endl;
	}

	return 0;
}
