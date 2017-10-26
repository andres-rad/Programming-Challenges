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

#undef DEBUG

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << v << endl;
#else
#define debug(v) 
#endif

tint a,b;
vector<tint> pad;
vector<tint> unp;
vector<tint> power10;

void dar(const string &s, const array<tint,10> &a) {
#ifdef DEBUG
	cerr << s << " ";
	forn(i,10) {
		cerr << a[i] << " ";
	}
	cerr << endl;
#endif
}

array<tint, 10> count(int n) {
	array<tint, 10> res;
	res.fill(0);

	stack<int> digs;
	int n2 = n;
	while(n2 > 0) {
		digs.push(n2 % 10);
		n2 /= 10;
	}

	array<tint, 10> consumed;
	consumed.fill(0);

	int restN = n;
	bool first = true;
	while(digs.size()) {
		int top = digs.top();
		int p = digs.size();
		digs.pop();

		debug(top);
		debug(p);
		debug(restN);
		dar("initial res", res);

		// head case
		if(first) {
			res[0] += unp[p-1] + pad[p-1] * (top-1);
			forsn(d,1,10) {
				res[d] += pad[p-1] * top;
			}
			forsn(d,1,top) {
				res[d] += power10[p-1];
			}
		} else {
			forn(d,10) {
				res[d] += consumed[d] * power10[p-1] * top;
				res[d] += pad[p-1] * top;
			}
			dar("res", res);
			forn(d,top) {
				res[d] += power10[p-1];
			}
			dar("res", res);
		}

		restN -= top * power10[p-1];
		consumed[top] += 1;
		first = false;
	}

	forn(d,10) {
		res[d] += consumed[d];
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	pad = vector<tint>(10);
	unp = vector<tint>(10);
	power10 = vector<tint>(10);
	power10[0] = 1;
	forsn(i,1,10) {
		power10[i] = 10 * power10[i-1];
		pad[i] = power10[i-1] * i;

		tint sum = 0;
		forn(j, i) {
			sum += power10[j];
		}
		unp[i] = pad[i] - sum;
	}

	debug(unp[0]);
	debug(unp[1]);
	debug(unp[2]);
	debug(pad[0]);
	debug(pad[1]);
	debug(pad[2]);

	while(cin >> a >> b){
		if(a == 0) break;

		auto arB = count(b);
		array<tint, 10> arA;
		if(a > 1)
			arA = count(a-1);
		else
			arA.fill(0);

		dar("arA", arA);
		dar("arB", arB);

		forn(i,10) {
			cout << arB[i] - arA[i];
			if(i != 9) cout << " ";
		}
		cout << endl;
	}

	return 0;
}