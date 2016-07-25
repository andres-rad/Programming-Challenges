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

int cantcomp;
vector<set<int> > componentes;

void init(){
	clases.clear();
	clases.insert(clases.begin(), 100000, -1);
	cantcomp=100000;
	
	componentes.clear();
	componentes.insert(componentes.begin(), 100000, set<int>);
	
	return;
}

int cl(int h){
	return (clases[h]==-1? h : clases[h]=cl(clases[h]));
}

void join (int i1, int j1, int i2, int j2){
	if (cl(hashi(i1, j1))!=cl(hashi(i2, j2))){
		cantcomp--;
		if (componentes[cl(hashi(i1, j1))].size() <componentes[cl(hashi(i2, j2))].size()){
			clases[cl(hashi(i1, j1))]=cl(hashi(i2, j2));
			componentes[cl(hashi(i2, j2))].insert(componentes[cl(hashi(i1, j1))].begin(), componentes[cl(hashi(i1, j1))].end());
			componentes[cl(hashi(i1, j1))].clear();
		}else {
			clases[cl(hashi(i2, j2))]=cl(hashi(i1, j1));
			componentes[cl(hashi(i1, j1))].insert(componentes[cl(hashi(i2, j2))].begin(), componentes[cl(hashi(i2, j2))].end());
			componentes[cl(hashi(i2, j2))].clear();
		}
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
	
	forn (h, 4){
		
		
		if ( i+movs[h].first!=0 && j+movs[h].second!=0 &&  i+movs[h].first<w && j+movs[h].second<h && 
			!vis[i+movs[h].first][j+movs[h].second] && campo[i][j]<=campo[i+movs[h].first][j+movs[h].second]) {
				
			// seguir aca
			join(i,j,i+movs[h].first,j+movs[h].second);
			dfs (campo,i+movs[h].first,j+movs[h].second);
			
			
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
	
	int j=0;
	int altura;
	
	while (j<orden.size()){
		altura= orden[j].first;
		
		while (orden[j].first<=altura){
			int x=orden[j].second.first, y=orden[j].second.second;
			j++;
			
			forn (h, 4){
				
				if ( i+movs[h].first!=0 && j+movs[h].second!=0 &&  i+movs[h].first<w && j+movs[h].second<h && 
					!vis[i+movs[h].first][j+movs[h].second] && campo[i][j]<=campo[i+movs[h].first][j+movs[h].second]) {
						
					// seguir aca
					join(i,j,i+movs[h].first,j+movs[h].second);
					dfs (campo,i+movs[h].first,j+movs[h].second);
					
					
				}
				
				
			}
			
			
		}
		
	}
			
			
			
	return 0;
}
