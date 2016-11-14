#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

using namespace std;

int main() {
	int n,c,s;

	cin >> n >> c >> s;
	s--;

	int act = 0;
	int res = 0;
	if(s == 0) res++;
	forn(i,c) {
		int com;

		cin >> com;

		act += com;
		act %= n;
		act += n;
		act %= n;
		if(act == s) res++;

	}

	cout << res << endl;


	return 0;
}