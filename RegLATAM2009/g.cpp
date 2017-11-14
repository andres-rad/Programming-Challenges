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
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	//unordered_map<int, set<pair<int, int> > > s;
	vector<pair<int, int> >  s[1002];
	while (cin >> n >> m){
		if (n == 0 ) break;
		forn (i, 1002){
			s[i].clear();
		}
		//for (auto d : s){
		//	d.clear();
		//}

		//vector<vector <int > > m (n, vector<int> (m));
		int a;
		forn(i,n){
			//debug(i);
			forn(j,m){
				cin >> a;
				s[i - j + 500].emplace(s[i-j+500].end(), make_pair(a, i)) ;
				//debug(i - j + 1000);
			}
		}

		int q;
		cin >> q;
		int res;
		forn(i, q){
			int l, u;
			res = 0;
			cin >> l >> u;
			//debug (l);
			for (auto& d : s){
				if (d.empty()) continue;
				auto chico = lower_bound(d.begin(), d.end(), make_pair(l, -1));
				auto grande = upper_bound(d.begin(), d.end(), make_pair(u, n*m));
				if (grande != d.begin() and chico != d.end()){

					//debug(chico->fst);
					//auto gg = grande;
					grande--;
					//debug (grande->fst);

					res = max(res, (grande)->snd - chico->snd + 1);
					//debug(res);

				}
			}

			cout << res << '\n';
		}

		cout << '-' << '\n';
	}

	return 0;
}
