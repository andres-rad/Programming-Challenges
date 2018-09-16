#include <bits/stdc++.h>
using namespace std;

#define tint long long

#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) cerr << #v << ": " << (v) << endl
typedef long long tint;

unordered_map<tint, int> dp [260][260];


int f(int ml, int mr, tint long){
	if (dp[ml][mr])
}

int main() {
	int n;

	while(cin >> n){
		tint m;
		cin >> m;

		forn(i, 1 << n) forn(j, 1 << n){
			dp[i][j].clear();
		}





	}	
	return 0;
}