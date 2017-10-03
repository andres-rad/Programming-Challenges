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

tint l,o,s,t;

tint consume(tint ll, tint oo, tint ss, tint tt) {
	tint c = l+o+s+t;
	if(ll) c = min(c, l/ll);
	if(oo) c = min(c, o/oo);
	if(ss) c = min(c, s/ss);
	if(tt) c = min(c, t/tt);
	l -= ll * c;
	o -= oo * c;
	s -= ss * c;
	t -= tt * c;
	return c;
}

int main() {
	tint lll,ooo,sss,ttt;
	cin >> lll >> ooo >> sss >> ttt;

	tint res = 0;

	vector<int> v = {1,2,3,4,5,6};
	map<int, int> m0 = {{1,0}, {2, 0}, {3,2}, {4, 1}, {5,2}, {6, 4}};
	map<int, int> m1 = {{1,4}, {2, 0}, {3,0}, {4, 0}, {5,2}, {6, 0}};
	map<int, int> m2 = {{1,0}, {2, 0}, {3,2}, {4, 1}, {5,0}, {6, 0}};
	map<int, int> m3 = {{1,0}, {2, 4}, {3,0}, {4, 2}, {5,0}, {6, 0}};
	int cnt = 0;
	do{
		l = lll;
		o = ooo;
		s = sss;
		t = ttt;
		debug(cnt++);
		tint curr = 0;
		for (auto e: v){
			curr += consume(m0[e], m1[e],m2[e], m3[e]);
		}
		res = max(res, curr);

	}while (next_permutation(v.begin(), v.end()));

	

	cout << res << endl;

	return 0;
}