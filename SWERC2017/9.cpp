#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;

int main() {
	int n;

	while(cin >> n){
		int m;
		char elem;
		cin >> m;
		vector<vector<int>> filas(n, vector<int>(m, 0));
		vector<vector<int>> escaleras(n);
		vector<vector<int>> add(n, vector<int>(m, 0));
		vector<vector<int>> izq(n, vector<int>(m, 0));
		vector<vector<int>> der(n, vector<int>(m, 0));
		
		forn(i, n){
			forn(j, m){
				cin >> elem;
				if(elem != '-') {
					elem -= '0';
					filas[i][j] = elem;
					if(j != 0){
						add[i][j] += add[i][j-1] + elem;
					} else {
						add[i][j] = elem;
					}
				}
			}

			forn(j,m){
				cin >> elem;
				if(elem == '|')	escaleras[i].pb(j);
			}
		}

		forn(i, n){
			int latest = 0;
			forn(j, m){
				if(filas[i][j]){
					latest = j;
				}
				izq[i][j] = latest;
			}

			latest = n-1;

			for(int j=m-1; j>=0; j--){
				if(filas[i][j]){
					latest=j;
				}
				der[i][j] = latest;
			}
		}

		vector<unordered_map<pair<int, int>, int>> dp(n);

		for(int i=n-1; i>=0; i++){
			for(auto it_izq = escaleras[i].begin(); it_izq != escaleras[i].end(); it_izq++){
				for(auto it_der = it_izq; it_izq != escaleras[i].end(); it_izq++){
					if(i = n-1){
						dp[mp(*it_izq, *it_der)] = izq[n-1][*it_izq] + der[n-1][*it_der];
					}
			}
		}
	}	
	return 0;
}