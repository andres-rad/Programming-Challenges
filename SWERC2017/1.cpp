#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;

unordered_map<tint, int> mapa;

vector<tint> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;

	while(cin >> n){
		// mapa.clear();
		cin >> m;

		vector<tint> ins(n);
		vector<tint> outs(m);
		// mapa.reserve(n*m);
		v.clear();

		forn(i,n) cin >> ins[i];
		forn(i,m) cin >> outs[i];
		tint firstGT = 0;
		tint best = -1;
		tint bestDif = -1;

		forn(i, n) {
			tint in = ins[i];
			forsn(j, 0, m) {
				tint out = outs[j];
				// if(in > out) {
				// 	firstGT = j+1;
				// 	continue;
				// }

				tint diff = out - in;
				if (diff < 0) continue;
				v.pb(diff);
				// continue;
				// int temp = ++mapa[diff];
				// if(temp > best || (temp == best && diff < bestDif)) {
				// 	bestDif = diff;
				// 	best = temp;
				// }
			}
		}

		sort(v.begin(), v.end());

		tint last = v[0], last_cnt = 0, best_cnt = 0;
		bestDif = 0;
		forn(i, v.size()){
			if (last != v[i]){
				// cerr << last << ' ' << last_cnt << ' ' << best_cnt << endl;
				if (last_cnt > best_cnt){
					best_cnt = last_cnt;
					bestDif = last;
				}
				last = v[i];
				last_cnt = 0;
			}
			last_cnt++;
		}

		cout << max(bestDif, 0ll) << endl;
	}	
	return 0;
}