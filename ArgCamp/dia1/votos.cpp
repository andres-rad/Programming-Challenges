#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <cassert>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

int main(){
	int casos;
	int caso = 0;
	cin >> casos;
	while(caso < casos){
		caso++;
		int n,m;
		cin >> n >> m;
		vector<int> votos(n,0);
		forn(i,m){
			forn(j,n){
				int voto;
				cin >> voto;
				//cout << voto << endl;
				votos[j] += voto;
			}
		}
		int ganador = 0;
		forn(i,n){		
			if(votos[i] > votos[ganador]){
				ganador = i;
			}
		}
		cout << ganador+1 << endl;
	}
	return 0;
}
