#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back


vector<vector<int> > adj;
vector<int> color;
vector<int> vis;

void dfs(int node){
	if (vis[node]) return;
	
	//cerr<<"dfs "<<node<<endl;
	
	vis[node]=1;
	
	forn(i, adj[node].size()){
		int hijo=adj[node][i];
		if (color[node]==color[hijo]){
			dfs(hijo);
		}
	}
	
	return;
}

int main() {
	
	int n;
	cin>>n;
	
	color=vector<int> (n,0);
	forn(i,n){
		cin>>color[i];
	}
	
	adj=vector<vector<int> > (n, vector<int> (0));
	vis=vector<int>(n,0);
	
	forn(i,n-1){
		int a, b;
		cin>>a>>b;
		
		a--;b--;
		adj[a].pb(b);
		adj[b].pb(a);
		
	}
	
	vector<int> blane(2,0);
	
	int i=0;
	while(i<n){
		dfs(i);
		blane[color[i]]++;
		while(i<n && vis[i]) i++;
		
		cerr<<"veo "<<i<<endl;
	}
	
	cout<<min(blane[0],blane[1])<<endl;


	return 0;
}
