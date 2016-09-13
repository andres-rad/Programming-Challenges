#include "math.h"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "unordered_map"
#include "iostream"
#include "cstring"
#include "stdlib.h"


#define tint long long
#define utint unsigned long long
#define forsn(i,s,n) for(tint i = s; i < n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define mp make_pair
#define umap unordered_map

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	int n;
	while(cin >> n){
		vector<int> tarros(n,0);
		forn(i,n){
			cin >> tarros[i];
		}	
		sort(tarros.begin(), tarros.end());
		
		if (tarros[0] % (n+1) == 0){
			cout << 'S' << endl;
		} else {
			cout << 'N' << endl;
		}
	}
	
	return 0;

}
