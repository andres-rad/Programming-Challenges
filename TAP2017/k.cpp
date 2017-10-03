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


int main() {
	tint n;
	cin >> n;

	tint imp = 0;
	forn(i,n) {
		tint m;
		cin >> m;
		if(m % 2) imp++;
	}

	tint res = ((imp+1)/2);

	cout << res << endl;

	return 0;
}