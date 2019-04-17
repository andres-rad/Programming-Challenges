#include <bits/stdc++.h>
using namespace std;
typedef  long long tint;
#define forsn(i, s, n) for (int i = s; i < n; i++)
#define forn(i, n) forsn(i, 0, n)
#ifdef DEBUG
#define debug(v) cerr << #v << ": " << (v) << endl;
#else
#define debug(v)
#endif

tint expmod(tint a, tint exp, tint mod){
	if (exp == 0)
		return 1;
	tint b = expmod((a*a)%mod, exp >> 1, mod);
	return ((exp & 1 ? a : 1)*b) % mod;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	tint n; cin >> n;
	map<pair<tint, tint>, tint> recs;
	forn(i,n){
		// debug(i);
		tint a, b; cin >> a >> b;
		recs[{a, b}]++;
	}
	map<pair<tint, tint>, map<tint, set<pair<tint, tint>>>> inter;
	// (a, b) in inter dice cuantas rectas hay que se intersecan cuando R =1 y B =a/b

	auto it = recs.begin();
	while(it != recs.end()){
		// debug(it->first.first);
		// debug(it->first.second);
		auto jt = it;
		jt++;
		while(jt != recs.end()){
			// debug("alla");
			// if (it->first->second == jt->first->second)
				// continue;
			// debug(jt->first.first);
			// debug(jt->first.second);
			tint a, b, mcd;
			a = it->first.first - jt->first.first;
			b = jt->first.second - it->first.second;
			// debug(a);
			// debug(b);
			if (a != 0 and b != 0 and a*b > 0){
				a = abs(a);
				b = abs(b);
				mcd = __gcd(a, b);
				assert(a % mcd == 0);
				assert(b % mcd == 0);
				a /= mcd; b /= mcd;
				tint y = a*it->first.second + b*it->first.first;
				assert(y == a*jt->first.second + b*jt->first.first);
				// debug(y);
				inter[{a, b}][y].insert(it->first);
				inter[{a, b}][y].insert(jt->first);
			}
			jt++;

		}

		it++;
	}
	tint mod = 1e9 + 7;
	// debug(mod*mod);
	vector<tint> fact(2010, 1);
	forsn(i, 1, 2010){
		fact[i] = (i * fact[i-1]) %mod;
	}
	tint cant = 1;
	// map<pair<tint, tint>, pair<tint, int>> igs;
	// for (auto& e : recs){
		// if (e.second > 1){
			// igs[e.first] = {e.second, 0};
		// }
	// }
	for (auto& e : recs){
		// assert(e.second.first > 1);
		cant = (cant*fact[e.second]) % mod;
	}
	tint ans = 0;
	for (auto& pto : inter){
		tint canti = 1;
		tint cantigs = 1;
		
		for (auto& s : pto.second){
			tint sz = 0;
			for (auto& p : s.second){
				sz+= recs[p];
				cantigs = (cantigs * fact[recs[p]]) % mod;
			}
			// debug(sz);
			canti = (canti * fact[sz]) % mod;
		}
		cantigs = (cant * expmod(cantigs, mod - 2, mod)) % mod; // inverso

		canti = (canti * cantigs) % mod;
		// assert(canti > cant);
		ans += (canti - cant) % mod;
		ans = ans % mod;
	}

	
	debug(ans);
	debug(cant);
	debug(inter.size());
	if (inter.size() == 0){
		cout << cant << endl;
		return 0;
	}
	ans += cant;
	// ans -= (((long long)(inter.size()))*cant);
	// cerr << ((int(inter.size()) - 1)*cant) << endl;
	// cerr << ((int(inter.size()) - 1)*cant)%mod << endl;
	debug(ans);
	ans %= mod;
	debug(ans);
	ans += mod;
	debug(ans);
	ans %= mod;
	cout << ans << endl;
	return 0;
	// if (ans & 1){
	// 	//impar
	// 	debug("impar");
	// 	cout << ((ans + mod)/2)%mod << endl;
	// }else{
	// 	cout << ans/2 << endl;
	// }
	// return 0;
}