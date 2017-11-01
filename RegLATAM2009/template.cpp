#include <bits/stdc++.h>
using namespace std;
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n); i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long tint;

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << v << endl;
#else
#define debug(v)
#endif

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, r, c, k;
	while (cin >> n >> r >> c >> k ){
		if (n == 0){
			return 0;
		}

		vector<vector<pair<int, int > > > mat (r, vector<int> (c));

		forn(i, r){
			forn(j, c){
				cin >> mat[i][j].fst;
			}
		}


	}


	return 0;
}
