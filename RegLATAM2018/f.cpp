#include <bits/stdc++.h>
using namespace std;
typedef __int128 tint;
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << (v) << endl;
#else
#define debug(v)
#endif

void print(__int128 a){
	if (! a){
		cout << 0 << endl;
		return;
	}
	vector<int> b;
	while(a){
		b.push_back(a % __int128(1e5));
		a = a / __int128(1e5);
	}
	auto it = b.rbegin();
	while(it != b.rend()){
		cout << *it;
		it++;
	}
	// cout << endl;
}

struct dxy {tint d,x,y;};
dxy mcde(tint a, tint b) {
	dxy r, t;
	if (b == 0) {
		r.d = a; r.x = 1; r.y = 0;
	} else {
		t = mcde(b,a %b);
		r.d = t.d; r.x = t.y;
		r.y = t.x - a/b*t.y;
	}
	return r;
}

tint modq(tint x, tint q) { return (x % q + q) % q ; }

tint tcr(const vector<tint>& r, const vector<tint>& m) {
	tint n = r.size();
	// assert(n == m.size());
	tint p=0, q=1;
	forn(i, n) {
		p = modq(p-r[i], q);
		dxy w = mcde(m[i], q);
		if (p % w.d) return -1; // sistema incompaible
		q = q / w.d * m[i];
		p = modq(r[i] + m[i] * p / w.d * w.x, q);
	}
	return p; // x \equiv p (q)
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	// print(1);
	int b, z; cin >> b >> z;

	vector<tint> init(b);
	vector<vector<tint>> to(b, vector<tint>(z));

	forn(i, b){
		int tmp;
		cin >> tmp;
		tmp--;
		init[i] = tmp;
		forn(j, z){
			cin >> tmp; tmp--;
			to[i][j] = tmp;
		}
	}
	tint ans = 0;
	while(ans < 200){
		tint curr = init[0];
		forn(i, b){
			if (init[i] != curr)
				curr = -1;
		}
		if (curr > -1){
			print(curr+1); cout << " ";
			print(ans);
			cout << endl;
			// cout << curr + 1 << " " << ans << endl;
			return 0;
		}
		ans++;
		forn(i, b){
			init[i] = to[i][init[i]];
		}
	}

	debug(ans);

	// Seguro entre a un ciclo
	vector<vector<pair<tint, tint>>> TCR(b, vector<pair<tint, tint>>(z, {0, 0}));
	// TCR[i][j] = (a, m) <=> cuando (t - ans) % m == a, la bestia i esta en el z j
	// si TCR[i][j] = (0, 0) Nunca llego ahi

	forn(i, b){
		debug(i);
		tint start = init[i];
		tint nxt = init[i];
		tint sz = 0;
		debug(start);
		do{
			sz++;
			nxt = to[i][nxt];
			// debug(nxt);
		}while(nxt != start);
		// tengo sz
		tint r = 0;
		do{
			TCR[i][nxt] = {r, sz};
			nxt = to[i][nxt];
			r++;
		}while(nxt != start);
	}



	tint best = 1ll<<62;
	tint bestz = -1;

	forn(i, b){
		debug(i);
		forn(j, z){
			debug(j);
			debug(TCR[i][j].first);
			debug(TCR[i][j].second);
		}
	}

	forn(i, z){
		vector<tint> m, r;
		bool vale = true;
		forn(j, b){
			m.push_back(TCR[j][i].second);
			r.push_back(TCR[j][i].first);
			if(TCR[j][i].second == 0){
				vale = false;
				break;
			}

		}
		debug(i);
		if (vale){
			debug(best);
			tint tmp = tcr(r, m);
			if (tmp >= 0 and tmp < best){
				best = tmp;
				bestz = i;
			}
		}

	}
	// debug(best);

	if(bestz == -1){
		cout << "*" << endl;
	}else{
		print(bestz+1); cout << " ";
			print(ans + best);
			cout << endl;
		// cout << bestz + 1 << " " << ans + best << endl;
	}


	return 0;
}