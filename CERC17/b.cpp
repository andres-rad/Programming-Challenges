#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) //cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;

struct UF{
	vector<int> p, sz;
	UF(int n = 0):p(n, -1), sz(n, 0){};

	int find(int a){
		return ((p[a] == -1) ? a : (p[a] = find(p[a])));
	};

	int unio(int a, int b){
		int ra = find(a), rb = find(b);
		if (ra == rb) return sz[ra];
		if (sz[ra] < sz[rb]) swap(ra, rb);
		sz[ra] += sz[rb];
		p[rb] = ra;
		return sz[ra];
	};
};

int main() {
	int n;
	ios::sync_with_stdio(0); cin.tie(0);

	while(cin >> n){

		vector<pair<tint, tint>> buffs(n);

		forn(i, n){
			cin >> buffs[i].second >> buffs[i].fst;
		}

		int m; cin >> m;

		vector<pair<pair<tint, tint>, tint>> fenc(m);
		forn(i, m){
			cin >> fenc[i].fst.snd >> fenc[i].fst.fst;
			fenc[i].snd = i+1;
		}

		sort(buffs.begin(), buffs.end());
		sort(fenc.begin(), fenc.end());

		auto bit = buffs.rbegin();
		auto fit = fenc.rbegin();

		vector<int> out(m+1, 0);

		map<tint, int> sweep;
		sweep[1e10] = 0;

		UF uf(m+1);

		while(bit != buffs.rend() or fit != fenc.rend()){
			if (bit == buffs.rend() or (fit!=fenc.rend() and fit->fst.fst >= bit->fst)){
				// analizo fit
				sweep[fit->fst.snd] = fit->snd;

				auto it = sweep.find(fit->fst.snd);

				while(it != sweep.begin()){
					auto check = it; check--;
					if (check->snd < it->snd) break;
					sweep.erase(check);
				}

				auto outer = it; outer++;
				debug(it->snd); debug(outer->snd);
				out[it->snd] = outer->snd;
				fit++;
			}else{
				// analizo bit
				uf.sz[uf.find(sweep.lower_bound(bit->snd)->snd)]++;
				debug(uf.find(sweep.lower_bound(bit->snd)->snd));
				bit++;
			}
		}

		vector<int> res(m);

		for (int i = m; i > 0; i--){
			res[i-1] = uf.sz[uf.find(i)];
			uf.unio(i, out[i]);
		}

		for (auto r : res){
			cout << r << '\n';
		}

		
	}	
	return 0;
}