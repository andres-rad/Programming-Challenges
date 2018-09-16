#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forsn(i,s,n) for(tint i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;

int main() {
	tint w;

	while(cin >> w){
		tint n, li, wi;
		tint area = 0;
		cin >> n;
		forn(i, n){
			cin >> wi >> li;
			area += wi * li;
		}

		cout << area / w << endl;
	}	
	return 0;
}