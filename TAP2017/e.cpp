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


int solve (set<int> mias, set<int> otro){
	int res = 0;
	for (auto c:mias){
		debug (c);
		auto it = otro.lower_bound(c);
		set<int> miat = mias;
		miat.erase(c);
		if (it != otro.begin()){
			it--;
			set<int> otrotemp = otro;
			otrotemp.erase(*it);
			res = max(res, (int)mias.size() - 1 - solve(otrotemp, miat));
		}
		it = otro.end();
		it--;
		if (*it > c){
			set<int> otrotemp = otro;
			//cerr << otrotemp.size() << endl;
			otrotemp.erase(*it);
			res = max(res, 1+ solve(miat, otrotemp));
		}
		debug (res);
	}
	return res;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int cnt = 0;

	if (a<4) cnt++;
	if (b<4) cnt++;
	if (c<4) cnt++;
	set<int> m;
	m.insert(a);
	m.insert(b);
	m.insert(c);


	bool res = false;
	if (m.find(1) != m.end()){
		if(m.find(2) != m.end() || m.find(3) != m.end()){
			cout << 'S' << endl;
			return 0;
		}

		res =  res || ((m.find(6) == m.end() && m.find(7) == m.end()));

	}
	else {
		res = res || (m.find(2) != m.end() && m.find(3) != m.end() && m.find(4) != m.end());
	}
		cout << (res ? 'S' : 'N') << endl;

	return 0;
}