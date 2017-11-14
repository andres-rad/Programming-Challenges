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

tint calc(tint k) {
	tint res = 0;

	res += max((tint)0, k-0) * 2;
	res += max((tint)0, k-100) * 1;
	res += max((tint)0, k-10000) * 2;
	res += max((tint)0, k-1000000) * 2;
	return res;
}

void restar2(tint &k, tint &res, tint num, tint mul) {
	tint tmp = min(num*mul,k);
	tmp /= mul;
	tmp *= mul;
	res += tmp / mul;
	k -= tmp;
}

tint inv(tint k) {
	tint res = 0;
	restar2(k,res,100,2);
	restar2(k,res,10000-100,3);
	restar2(k,res,1000000-10000,5);
	restar2(k,res,1000000000000,7);
	//res += k / 7;
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	debug(calc(10123));
	debug(inv(30515));
	debug(inv(1100));
	debug(inv(2900));
	debug(inv(2975));

	debug(calc(1000900));
	debug(inv(calc(1000900)));

	forn(i, 434){
		break;
		if (i*10009 != inv(calc(i*10009))){
			debug(i*10009);
		}
	}

	tint a,b;
	while(cin >> a >> b) {
		if(a == 0) break;

		tint sum = inv(a);
		tint l = 0, r = sum/2 + 1;

		debug(sum);
		debug(calc(sum));
		debug(r);
		debug(calc(sum-0) - calc(0));
		debug(calc(sum-r) - calc(r));

		while(r - l > 1) {
			tint m = (r+l) / 2;
			tint val = calc(sum-m) - calc(m);
			if(val < b) {
				r = m;
			} else {
				l = m;
			}
		}

		debug(l);
		debug(calc(sum-l));
		debug(calc(l));
		debug(calc(sum-l) - calc(l));

		cout << calc(l) << endl;
	}

	return 0;
}
