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

#define MAXN 120


int main() {
	const tint mod = 1000000007;

	vector<vector<tint> > comb (MAXN+1, vector<tint> (MAXN+1));
	forn(i, MAXN+1){
		comb[i][0] = comb[i][i] = 1;
		forsn(k, 1, i) comb[i][k]=(comb[i-1][k] + comb[i-1][k-1]) % mod;
	}


	tint n, m, p1, p2, pmax;
	cin >> n >>m >> p1 >> p2;
	pmax = max(p1, p2);
	vector<vector<tint> > dp (n+1, vector<tint> (pmax +1, 0));
	dp[0][0] = 1;


	forsn (i, 1, n+1){
		forsn (j, 1, pmax + 1){
			int cur = min(m, j);

			forsn(h,1, cur+1){
				dp[i][j] += dp[i-1][j-h] % mod;
				dp[i][j] = dp[i][j] %mod;
			}
		}
	}

	tint res = 0;

	forn(j, n+1){
		forn(i, n-j+1){
			tint mul;
			mul = (dp[i][p1]*dp[n-j-i][p2]) % mod;
			mul *= (comb[n][j]*comb[n-j][i]) % mod;
			mul %= mod;
			res += mul;
			res = res % mod;
		}
	}

	cout << res <<endl;


	return 0;
}