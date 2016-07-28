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
#include <sstream>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef long long int tint;


vector<vector<int> > ady;
vector<int> vis;
vector<set<int> > conexas;
vector<set<pair<int,int> > > ariconexas;

void dfs(int n, int comp){
	vis[n] = 1;
	conexas[comp].insert(n);
	
	forn(i, ady[n].size()){
		ariconexas[comp].insert(mp(min(n,ady[n][i]), max(n, ady[n][i])));
		if(!vis[ady[n][i]]){
			dfs(ady[n][i], comp);
		}
	}
	
	return;
}

int main(){
	
	tint n,m,r,e;
	cin >> n >> m >> r >> e;
	
	ady.clear();
	vis.clear();
	conexas.clear();
	ariconexas.clear();
	
	ady.insert(ady.begin(),n+2, vector<int>(0));
	vis.insert(vis.begin(),n+2, 0);
	
	set<int> temp;
	conexas.insert(conexas.begin(),n+2, temp);
	
	set<pair<int, int> > tempp;
	ariconexas.insert(ariconexas.begin(), n+2, tempp);
	
	forn(i,m){
		int j, k;
		cin >> j >> k;
		ady[j].pb(k); 
		ady[k].pb(j);
	}
	
	int comp=0;
	int i=1;
	tint res=0;
	
	while (i<=n){
		if (!vis[i]){
			
			dfs(i, comp);
		
			
			tint mi=e*(tint)conexas[comp].size();
			tint cantciudad=conexas[comp].size();
			tint construidas= ((cantciudad*(cantciudad-1))/2-(tint)ariconexas[comp].size())*r;
		
			mi = min(mi, construidas);
			res+=mi;
			comp++;
		}
		i++;
	}
	
	cout<<res<<endl;
	
	return 0;
}
