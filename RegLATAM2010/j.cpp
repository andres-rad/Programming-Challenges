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
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	while (a != 0){
		debug(a);
		set<int> vistas;
		vistas.insert(a);
		vistas.insert(b);
		vistas.insert(c);
		vistas.insert(x);
		vistas.insert(y);

		int el_del_medio = min(max(a,b), min(max(a,c), max(b,c)));
		int mayor = max(a,max(b,c));

		int res1, res2;
		res1 = res2 = -1;

		int ganax, ganay;
		ganay = ganax = 0;

		if (x > a) ganax++;
		if (x > b) ganax++;
		if (x > c) ganax++;

		if (y > a) ganay++;
		if (y > b) ganay++;
		if (y > c) ganay++;

		if (ganay == 3 and ganax == 3){
			int cur = 1;
			while(1){
				if (vistas.find(cur) == vistas.end()){
					cout << cur <<endl;;
					res1 = res2 = cur;
					break;
				}
				cur++;
			}
		} else if(ganax == 3){
			if(ganay == 2){
				bool encontre = false;
				forsn(i, el_del_medio+1, 53){
					if(vistas.find(i) == vistas.end()){
						cout << i << endl;
						encontre = true;
						break;
					}
				}
				if(!encontre)
					cout << -1 << endl;
			} else {
				bool encontre = false;
				forsn(i, mayor+1, 53){
					if(vistas.find(i) == vistas.end()){
						cout << i << endl;
						encontre = true;
						break;
					}
				}
				if(!encontre)
					cout << -1 << endl;
			}
		} else if(ganay == 3){
			if(ganax == 2){
				bool encontre = false;
				forsn(i, el_del_medio+1, 53){
					if(vistas.find(i) == vistas.end()){
						cout << i << endl;
						encontre = true;
						break;
					}
				}
				if(!encontre)
					cout << -1 << endl;
			} else {
				bool encontre = false;
				forsn(i, mayor+1, 53){
					if(vistas.find(i) == vistas.end()){
						cout << i << endl;
						encontre = true;
						break;
					}
				}
				if(!encontre)
					cout << -1 << endl;
			}
		} else if(ganax == 2 && ganay == 2){
				bool encontre = false;
				forsn(i, el_del_medio+1, 53){
					if(vistas.find(i) == vistas.end()){
						cout << i << endl;
						encontre = true;
						break;
					}
				}
				if(!encontre)
					cout << -1 << endl;
		} else {
			cout << -1 << endl;
		}

	
		cin >> a >> b >> c >> x >> y;

	}

	return 0;
}