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
	vector<tint> s (2*n+1);
	s[0] = 0;
	forn(i, n){
		cin >> s[i+1];
		s[i+1] += s[i];
	}
	forn(i, n){
		s[i+n+1] = s[i+1] + s[n];
	}

	tint todo = s[n];
	tint t1 = 0, t2 = 0;
	tint diags = 0;
	debug(todo);

	while(t2<= n and diags < 2){
		// tint diff = t2 > t1 ? s[t2] - s[t1] : s[t1] - s[t2]
		t1++;
		if (t1 >= t2)
			t2 = t1+1;
		while((s[t2] - s[t1])*2 < todo){
			t2++;
			// t2 %= n;
		}
		debug(t1); debug(t2);
			debug(s[t2] - s[t1]);
		if ((s[t2] - s[t1])*2 == todo){
			diags++;
			// t2++;
		}
		// while((s[t2] - s[t1])*2 < todo){
		// 	t1++;
		// 	// t1 %= n;
		// }
		// if ((s[t2] - s[t1])*2 == todo){
		// 	diags++;
		// 	t1++;
		// }
	}

	cout << ((diags > 1) ? "Y" : "N") << endl;



	return 0;
}