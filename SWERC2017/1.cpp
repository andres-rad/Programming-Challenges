#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;

int main() {
	int n,m;

	while(cin >> n){
		cin >> m;

		vector<tint> ins(n);
		vector<tint> outs(m);

		forn(i,n) cin >> ins[i];
		forn(i,m) cin >> outs[i];

		unordered_map<tint, int> mapa;
		tint firstGT = 0;
		tint best = -1;
		tint bestDif = -1;

		forn(i, n) {
			tint in = ins[i];
			forsn(j, firstGT, m) {
				tint out = outs[j];
				if(in > out) {
					firstGT = j+1;
					continue;
				}

				tint diff = out - in;
				mapa[diff]++;
				if(mapa[diff] > best || (mapa[diff] == best && diff < bestDif)) {
					bestDif = diff;
					best = mapa[diff];
				}
			}
		}

		if(bestDif < 0) {
			cout << 0 << endl;
		} else {
			cout << bestDif << endl;
		}
	}	
	return 0;
}