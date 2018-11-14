#include <bits/stdc++.h>
using namespace std;
typedef long long tint;
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << (v) << endl;
#else
#define debug(v)
#endif

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	tint n; cin >> n;
	const tint INF = 1ll<<60;
	vector<double> dp(n, INF);
	vector<double> cost(n);
	vector<tint> dur (n);

	forn(i, n){
		cin >> dur[i] >> cost[i];
	}

		vector<double> c = {1, 0.5, .25, .25, .25, .25};
	for(int i = n-1; i >= 0; i--){
		tint t0 = 0;
		debug(dur[i]);
		debug(cost[i]);
		double acum = 0;
		// dp[i] = dp[i+1];
		forsn(j, 0, 6){
			if (t0 >= 120 or (i + j) >= n)
				break;
			t0 += dur[i+j];
			acum += c[j]*cost[i+j];
			dp[i] = min(dp[i], acum + dp[i+j+1]);

		}
		debug(dp[i]);
	}

	cout << setprecision(2) << fixed << dp[0] << endl;


	return 0;
}