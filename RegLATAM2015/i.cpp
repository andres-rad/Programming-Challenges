#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back

int main() {
	int t;

	while(cin >> t) {
		int a,b,c,d,e;
		cin >> a >> b >> c >> d >> e;

		cout << (a==t) + (b==t) + (c==t) + (d==t) + (e==t);
		cout << endl;
	}
	
	return 0;
}