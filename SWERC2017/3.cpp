#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) cerr << #v << ": " << (v) << endl
typedef long long tint;


unordered_map<tint, int> dp [260][260];
// dpchico [260][260][8];

int chicos(vector<int> v, int n, int ult = 0){
	debug("C");
	forn(i, 3) debug(v[i]);
	debug(ult);
	
	if (ult >= 3*n or (v[0] == 0 and v[1] == 0  and v[2] == 0)){
		// debug("fin");
		return 1;
	}else{
		int i = ult/3, j = ult % 3;

		int ans = 0;
		if (v[j] & (1 << i)){
			auto vv = v;
			vv[j] = vv[j] & ~(1 << i);
			ans += chicos(vv, n, ult + 1);
			if (v[j] & (1 << i) and (i+1) < n and v[j] & (1 << (i+1))){
				vv = v;
				vv[j] = vv[j] & ~(1 << i);
				vv[j] = vv[j] & ~(1 << (i+1));
				ans += chicos(vv, n, ult + 1);
			}
			if (v[j] & (1 << i) and (j+1) < 3 and v[j+1] & (1 << i)){
				vv = v;
				vv[j] = vv[j] & ~(1 << i);
				vv[j+1] = vv[j+1] & ~(1 << i);
				ans += chicos(vv, n, ult + 1);
			}
		}else{
			ans = chicos(v, n, ult+1);
		}
		// debug(v[0]);
	// debug(v[1]);
	// debug(ans);
	return ans;
	}
}

int f(int ml, int mr, tint m, int n){ // m cols llenas, ml extiende a izq, mr a der
	debug('F');
	debug(ml);
	debug(mr);
	debug(m);
	if (dp[ml][mr].find(m) == dp[ml][mr].end()){
		debug("not found");
		if (m == 0){
			dp[ml][mr][m] = chicos({ml, mr, 0}, n);
			debug("chico");
		}else if (m == 1){
			// ni idea

			dp[ml][mr][m] = chicos({ml, (1<<n)-1, mr}, n);
		}else{
			int m2 = m >> 1, m1 = (m >> 1) + (m & 1);
			m2--; m1--;
			int ans = 0;
			for (int i = 0; i < (1 << n); i++){
				ans += f(ml, i, m1, n) * f(i, mr, m2, n);
			}
		}
	}
	return dp[ml][mr][m];
}



int main() {
	int n;

	// debug(chicos({0b11, 0b10}, 2));
	debug(f(0,0,2,1));
	return 0;
	// debug(chicos({0b111, 0b000}, 3));
	while(cin >> n){
		tint m;
		cin >> m;

		forn(i, 1 << n) forn(j, 1 << n){
			dp[i][j].clear();
		}

		cout << f(0, 0, m, n) << endl;





	}	
	return 0;
}