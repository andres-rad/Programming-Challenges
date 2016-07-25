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

//UNION FIND
vector<int> clases (100000);

void init (){
	
	forn (i, 50000){
		clases[i]=-1;
	}
	
	return;
}


int cl(int j){
	if (clases[j]==-1) return j;
	else return clases[j]=cl(clases[j]);
}

void join (int i, int j){
	if (cl(i)!=cl(j)) clases[cl(i)]=cl(j);
	//				104					207
	return;
}
	
struct node{
	vector<int> adj;
	int lo;
	int prof;
};

vector<int> vis;
vector<node> graph;
//vector<pair<int,int> > puentes;

void dfs(int n, int padre, int prof){
	
	graph[n].prof=prof;
	
	vis[n]=1;
	
	int curlo=prof;
	
	forn (i, graph[n].adj.size()){
		if (graph[n].adj[i]==padre){
			padre=-1;
		}
		
		else if (vis[graph[n].adj[i]]) {
			curlo=min(curlo, graph[graph[n].adj[i]].prof);
		}
		else{
			dfs (graph[n].adj[i], n, prof+1);
			curlo=min(curlo, graph[graph[n].adj[i]].lo);
			if (graph[graph[n].adj[i]].lo> graph[n].prof) {
				//puentes.pb(mp(n, graph[n].adj[i]));
				join(n, graph[n].adj[i]);
			}
		}
		
		
	}
	
	graph[n].lo=curlo;
	
	return;
}



int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	
	
	
	int r,c, q;
	
	cin>>r>>c>>q;
	
	
	while (r!=0){
		init();
	
		node temp;
		temp.lo=10000000;
		
		vis.clear();
		
		vis.insert(vis.begin(), r+10, 0);
		
		graph.clear();
		
		graph.insert(graph.begin(),r+10,temp);
		
		forn (i,c){
			int h,j;
			cin>>h>>j;
			graph[j].adj.pb(h);
			graph[h].adj.pb(j);
		}
		
		dfs(1,-1,0);
		
		forn (i,q){
			int a,b;
			cin>>a>>b;
			
			cout<<(cl(a)==cl(b)?'Y':'N')<<'\n';
			
		}
		cout<<'-'<<'\n';
		
		cin>>r>>c>>q;
	}
	
	return 0;
	
}
