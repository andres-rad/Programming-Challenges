#include "math.h"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "iostream"
#include "cstring"
#include "stdlib.h"


#define tint long long
#define utint unsigned long long
#define forsn(i,s,n) for(tint i = s; i < n; i++)
#define forn(i,n) forsn(i,0,n)

using namespace std;

int main() {
	string n;
	string ordenada;
	ios::sync_with_stdio(false);

	while(cin >> n){

		int nn, iordenada, cuenta = 0;
		
		ordenada = n;
		sort(ordenada.begin(), ordenada.end());
		nn = stoi(n);
		iordenada = stoi(ordenada);

		while(iordenada != 0){
			nn = iordenada - nn;
			n = to_string(nn);
			ordenada = n;
			sort(ordenada.begin(), ordenada.end());
			iordenada = stoi(ordenada);
			cuenta++;
		}
		cout << cuenta<< endl;
	}	
	return 0;
}
