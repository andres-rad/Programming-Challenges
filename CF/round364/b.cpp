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
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

int main(){
	tint n,m, cells;
	cin>>n>>m;
	cells=n*n;
	
	vector<int> filas(n+1,false);
	vector<int> columnas(n+1,false);
	int filasocu=0;
	int columocu=0;
	
	forn (i,m){
		int x,y;
		cin>>x>>y;
		if (columnas[x] && filas[y]){
			cells=cells;
		}else if (!(columnas[x] || filas[y])){
			cells=cells-(n+n-1-filasocu-columocu);
			filasocu++;
			columocu++;
		}else if (!columnas[x]){
			cells=cells-(n-filasocu);
			columocu++;
		}else{
			cells=cells-(n-columocu);
			filasocu++;
		}
		
		
		
		cout<<cells<<endl;
		filas[y]=true;
		columnas[x]=true;
	}
		
	return 0;
}
