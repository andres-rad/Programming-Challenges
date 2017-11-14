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

tint n;
vector<array<int,1001>> divs;
vector<int> sizes;
vector<int> values;

tint calc(tint t) {
	tint res = 0;
	forn(i,n) {
		if(t > 1000) res += sizes[i];
		else res += abs(divs[i][t] - (sizes[i] - divs[i][t]));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while(cin >> n) {
		if(n == 0) break;

		divs = vector<array<int,1001>>(n);
		sizes = vector<int>(n);

		set<int> sval;

		forn(i,n) {
			tint k;
			cin >> k;

			divs[i].fill(0);
			sizes[i] = k;

			forn(j,k) {
				tint sc;
				cin >> sc;
				divs[i][sc]++;
			}

			tint acum = 0;
			forn(t,1001) {
				acum += divs[i][t];
				divs[i][t] = acum;
			}
		}


		tint resMin = calc(0);
		forn(i,1001) {
			resMin = min(resMin, calc(i));
		}
		cout << resMin << endl;
	}

	return 0;
}
