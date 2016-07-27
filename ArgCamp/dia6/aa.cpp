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
#define mp make_pair

using namespace std;

typedef long long int tint;

vector<int> clases;
vector<int> minimos;
vector<int> cantidad;
vector<int> altura;


void init(){
	clases.clear();
	clases.insert(clases.begin(), 100000, -1);
	
	minimos.clear();
	minimos.insert(minimos.begin(), 100000, 0);
	
	cantidad.clear();
	cantidad.insert(cantidad.begin(), 100000, 1);
	
	
	
	return;
}

int cl(int h){
	return (clases[h]==-1? h : clases[h]=cl(clases[h]));
}

int join (int i1, int j1, int i2, int j2){
	int res=0;
	if (cl(hashi(i1, j1))!=cl(hashi(i2, j2))){
		clases[cl(hashi(i1, j1))]=cl(hashi(i2, j2));
		
	}
	return;
}
			
int hashi (int i, int j){
	return i*302+j;
}


vector<vector<int> > vis;
pair<int, int> movs[4];
int w,h;

void dfs(vector<vector<int> > & campo, int i, int j){
	
	
	vis[i][j]=1;
	
	forn (l, 4){
		
		
		if ( i+movs[l].first!=-1 && j+movs[l].second!=-1 &&  i+movs[l].first<w && j+movs[l].second<h && 
			!vis[i+movs[l].first][j+movs[l].second] && campo[i][j]<=campo[i+movs[l].first][j+movs[l].second]) {
				
			// seguir aca
			join(i,j,i+movs[l].first,j+movs[l].second);
			dfs (campo,i+movs[l].first,j+movs[l].second);
			
			
		}
		
		
	}
	
	
	return;
}
	

int main(){
	vis.clear();
		
	vis.insert(vis.begin(), 100000, 0);
	
	movs[0]= mp(1,0);
	movs[1]= mp(-1,0);
	movs[2]= mp(0,1);
	movs[3]= mp(0,-1);
	
	init ();
	
	cin>>w>>h;
	
	vector<vector<int > > campo (h, vector<int> (w));
	
	vector<pair<int, pair<int, int> > > orden;
	
	forn (i,w){
		forn (j, h){
			int temp;
			cin>>temp;
			campo[i][j]=temp;
			orden.pb(temp, mp(i,j));
		}
	}
	
	orden.sort(orden.begin(), orden.end());
	
	forn (i,w){
		
		dfs(campo, i, 0);
		dfs(campo, i, h-1);
	}
	
	forn (i, h){
		dfs(campo, 0, i);
		dfs(campo, w-1, i);
	}
	
	int res=0;
	
	int altura;
	
	for (int i=1; i<h-1; i++){
		for (int j=1; j<w; j++){
			
			forn (l, 4){
		
		
			if ( i+movs[l].first!=-1 && j+movs[l].second!=-1 &&  
				i+movs[l].first<w && j+movs[l].second<h && 
				!vis[i+movs[l].first][j+movs[l].second] && 
				campo[i][j]<=campo[i+movs[l].first][j+movs[l].second]) {
						
					// seguir aca
					join(i,j,i+movs[l].first,j+movs[l].second);
					dfs (campo,i+movs[l].first,j+movs[l].second);
					
					
				}
				
				
			}
			
			
		}
	}
			
			
			
	return 0;
}
