#include <bits/stdc++.h>
#define forsn(i,s,n) for(unsigned long i = s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define fst first
#define snd second

using namespace std;

vector<long> counts(64,0);

unsigned long count(unsigned long n) {
	unsigned long ones = 0;
	unsigned long res = 0;
	//cerr << "count " << n << endl;
	forn(i,64) {
		//cerr << "i " << i << endl;
		unsigned long mult = (unsigned long)1<<(63-i);
		if(n & mult) {
			res += (63-i) * (mult/2);
			res += ones * mult;
			ones++;
			//cerr << "- " << (63-i) << " " << mult
			//	 << " res " << res << " ones " << ones << endl;
		}
	}
	return res;
}

int main() {
	unsigned long a,b;

	while(cin >> a) {
		cin >> b;

		//cerr << count(a) << " " << count(b+1) << endl;
		cout << count(b+1) - count(a) << endl;
	}

	return 0;
}