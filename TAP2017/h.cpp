#include <bits/stdc++.h>
using namespace std;
#define tint long long 
#define ii pair<tint,tint>
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define fst first
#define snd second
#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

int main() {
	tint n;
	cin >> n;

	bool climb = true;
	tint res = 0;
	tint last = 0;
	forn(i,n) {
		tint k;
		cin >> k;
		if((k < last) && climb) {
			res++;
			climb = false;
		}
		if(k > last) {
			climb = true;
		}
		last = k;
	}
	if(climb && last != 0) res++;

	cout << res << endl;

	return 0;
}