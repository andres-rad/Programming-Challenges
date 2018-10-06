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

tint mod;

/*
7 = 111 == 16
dim 0 = 1
()x
dim 1 = 7
100
010x
001x
110
101
011x
111
dim 2 = 7
100 010 (110)
100 001 (101)
100 011 (111)
010 001 (011)x
010 101 (111)
001 110 (111)
110 101 (011)
dim 3 = 1


*/

tint f(tint n, tint l){
	if (l == 0)
		return 1;

	return ((f(n, l-1) * ((1ll << (n-l+1)) - 1)) / ((1ll << l) - 1)) % mod;
}

int main() {
	mod = 1000000007;

	/*
	vector<vector<tint>> comb (32, vector<tint> (34, 0));
	forn(i, 32){
		comb[i][i] = comb[i][0] = 1;
		comb[i][1] = i;
	}

	forsn(i, 1, 32){
		forsn(j, 1, i){
			comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
			comb[i][j] %= mod;
			//debug(comb[i][j]);
		}
	}
	*/

	tint k;
	cin >> k;

	tint res = 1; // ya estoy sumando el vacio
	tint curr = 30;
	tint seen = 0;
	while (curr >= -1){
		// Invariante, k<= 1<<curr
		debug(k & (1ll << curr));
		if (curr == -1 or (k & (1ll << curr))){

			forsn(i, seen, seen + curr + 1){
				debug(i);
				debug(f(curr+seen, i));
				res += f(curr+seen, i);//*((1ll << seen) % mod);
				res %= mod;
			}
			k = k ^ (1ll << curr);
			seen++;
			debug(seen);
			debug(curr);
			debug(1ll<<curr);
			debug(k);
			debug(res);
		}

		curr--;
	}



	cout << res << endl;


	return 0;
}
