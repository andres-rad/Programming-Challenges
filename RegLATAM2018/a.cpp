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
	double r; cin >> r;
	r *= 100.0;
	tint n = round(r);

	cout << 36000 / (__gcd(36000ll, n)) << endl;


	return 0;
}