#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) //cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;

vector<int> vals;

const int INF = 1000;

int dp[502][502][8][2]; 
//dp[i][j][k][b] min de pasos para el intervalo [i, j), si el objetivo es k, y puedo rotar todo el intervalo sii b == 1

int solve(int i, int j, int k, int b){
	if (dp[i][j][k][b] == INF){
	
		assert(i < j);
		if (i == j-1){
			return (vals[i] == k ? 0 : 1);
		}
		int ans = INF;
		if (b){
			forsn(h, 1, 7)
				ans = min(ans, 1+solve(i, j, (k+h)%7, 0));
		}

		forsn(h, i+1, j){
			ans = min(ans, solve(i, h, k, 1) + solve(h, j, k, 1));
		}
		dp[i][j][k][b] = ans;
	debug(i);
	debug(j);
	debug(k);
	debug(b);
	debug(dp[i][j][k][b]);
	debug("======================");
	}	
	return dp[i][j][k][b];
}

int main() {
	int n;

	while(cin >> n){
		vals.clear();
		forn(i, n){
			string g;
			cin >> g;
			int maxi = 0;
			string maxs = g;

			forn(i, 7){
				rotate(g.begin(), g.begin() + 1, g.end());
				if (g > maxs){
					maxi = i+1;
					maxs=g;
				}
			}

			vals.pb(maxi);
			debug(maxi);
		}

		forn(i, n){
			forn(j, n+1){
				forn(k, 8){
					forn(b, 2) dp[i][j][k][b] = INF;
				}
			}
		}

		cout << solve(0, n, 0, 1) << endl;
		
	}	
	return 0;
}