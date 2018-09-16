#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;

int main() {
	int n;

	while(cin >> n){

		tint val = 0;
		
		vector<tint> totales(3, 0);
		vector<tint> filas(3, 0);
		
		int color = 0;

		forn(i, n){
			cin >> val;
			filas[color] += val;
			color = (color + 1) % 3; 
		}

		color = 0; 
		forn(i, n){
			cin >> val;
			forn(j, 3){
				totales[(color+j)%3] += val * filas[j];
			}
			color = (color + 1) % 3; 
		}
		
		cout << totales[1] << " " << totales[2] << " " << totales[0] << endl;
	}	
	return 0;
}