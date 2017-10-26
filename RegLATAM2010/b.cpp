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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	tint n, b;
	cin >> n;
	while(n != 0){
		bool puedo_todas = true;
		cin >> b;
		vector<tint> lo_use(n+1, 0); 
		vector<tint> restantes(b+1);
		forn(i, b){ 
			cin >> restantes[i];
		}

		forn(i, b)
			forn(j,b)
				lo_use[abs(restantes[i] - restantes[j])]++;
			
		
		for(tint j: lo_use){
			if(j == 0)
				puedo_todas = false;
		}

		cout << (puedo_todas ? 'Y' : 'N') << endl;
		cin >> n;
	}

	return 0;
}