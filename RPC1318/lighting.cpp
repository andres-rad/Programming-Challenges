#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(tint i=(tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i=(tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long tint;
#define sz(C) ((tint) C.size())

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	tint mod = 1e9 + 7;
	debug(mod);
	int n, k; cin >> n >> k;
	string t; cin >> t;
	vector<vector<vector<tint>>> dp (n+1, vector<vector<tint>> (k+2, vector<tint> (2, 0)));

	reverse(t.begin(), t.end());
	if (t[0] == '0'){
		dp[0][1][0] = 1;
		dp[0][2][0] = 1;
	}else{
		dp[0][2][0] = 1;
		dp[0][1][1] = 1;
	}
	forsn(i, 1, n){
		forsn(j, 1, k+2){
			if(t[i] == '1'){
				dp[i][j][0] = dp[i-1][j-1][0];
				dp[i][j][1] = dp[i-1][j][1] + 
								dp[i-1][j][0]+
								dp[i-1][j-1][1];
			}else{
				dp[i][j][1] = dp[i-1][j][1];
				dp[i][j][0] = dp[i-1][j-1][0] + 
								dp[i-1][j-1][1]+
								dp[i-1][j][0];
			}
			dp[i][j][0] = dp[i][j][0] % mod;
			dp[i][j][1] = dp[i][j][1] % mod;
		}		

	}
	debug(dp[n-1][k+1][0]);
	debug(dp[n-1][k][1]);
	debug(dp[n-1][k+1][1]);
	cout << dp[n-1][k+1][0] + dp[n-1][k][1] << endl;
	return 0;
}