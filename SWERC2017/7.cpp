#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;

#undef debug
#define debug(v)

pair<int,int> r = {0,0};

int dst(pair<int,int> p) {
	return abs(r.fst - p.fst) + abs(r.snd - p.snd);
}
int dst2(pair<int,int> p, pair<int,int> q) {
	return abs(q.fst - p.fst) + abs(q.snd - p.snd);
}


int main() {
	int n;
	int m;

	cin >> n >> m;

	vector<pair<int,int>> ws(n);
	vector<pair<int,int>> cs(m);
	vector<int> dws(n);
	vector<int> dcs(m);
	vector<bool> taken(n, false);

	forn(i, n) {
		cin >> ws[i].fst >> ws[i].snd;
	}
	forn(i, m) {
		cin >> cs[i].fst >> cs[i].snd;
	}

	cin >> r.fst >> r.snd;

	tint res = 0;

	forn(i, n) {
		dws[i] = dst(ws[i]);
		res += dws[i] * 2;
	}

	debug(res);


	vector<pair<int,int>> perm(m);
	forn(i,m) {
		perm[i].snd = i;
		perm[i].fst = dst(cs[i]);
	}
	sort(perm.rbegin(), perm.rend());





	bool anyCour = false;
	tint bestNeg = dws[0] - dst2(cs[0], ws[0]);

	forn(i2,m) {
		tint i = perm[i2].snd;

		tint best = -1;
		tint bestJ = -1;

		debug(i);
		forn(j,n) {
			if(taken[j]) continue;

			tint dif = dws[j] - dst2(ws[j], cs[i]);
			debug(j);
			debug(dif);
			if(dif >= 0 && best < dif) {
				best = dif;
				bestJ = j;
			}
			if(bestNeg < dif) {
				bestNeg = dif;
			}
		}

		if(best >= 0) {
			anyCour = true;
			taken[bestJ] = true;
			res -= best;
		}
	}

	debug(anyCour);
	debug(bestNeg);

	if(!anyCour) {
		res += (-bestNeg);
	}

	cout << res << endl;

	return 0;
}