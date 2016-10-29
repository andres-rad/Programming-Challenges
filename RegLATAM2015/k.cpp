#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define fst first
#define snd second

int main() {
	long n,m;

	while(cin >> n) {
		cin >> m;

		vector<long> lev(n);
		// Energy, money
		vector<vector<pair<long,long>>> shop(n);

		forn(i,n) {
			cin >> lev[i];
		}
		forn(i,m) {
			long l,s,c;
			cin >> l >> s >> c;
			l--;
			shop[l].pb({s,c});
		}

		set<pair<long,long>> opt;
		opt.insert({0,0});

		long acum = 0;

		forn(i,n) {
			if(opt.size() == 0) break;
			long buyPrice = opt.begin()->snd;

			//cerr << "i " << i;
			//cerr << " acum " << acum << " lev " << lev[i]<< endl;
			while(opt.size() and opt.begin()->fst < acum + lev[i]) {
				opt.erase(opt.begin());
			}

			for(auto s : shop[i]) {	
				auto itNew = opt.upper_bound({s.fst + acum, -1});
				if(itNew == opt.end()) {
					if(s.fst >= lev[i])
						opt.insert({s.fst + acum, buyPrice + s.snd});
				} else if(itNew->snd > buyPrice + s.snd) {
					if(s.fst >= lev[i]){
						opt.erase(itNew);
						opt.insert({s.fst + acum, buyPrice + s.snd});
					}
				}
			}

			acum += lev[i];

			//cerr << "    ";
			//for(auto &p : opt) {
			//	cerr << "(" << p.fst << "," << p.snd << ") ";
			//}
			//cerr << endl;
		}

		cout << (opt.size() ? opt.begin()->snd : -1);
		cout << endl;
	}
	
	return 0;
}