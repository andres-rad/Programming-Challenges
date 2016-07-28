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

typedef long long int tint;

struct node{
	vector<int> adj;
	int lo;
	int prof;
	bool punto;
};

vector<int> vis;
vector<int> articulacion;
vector<node> graph;

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
	return;
}

stack <pair<int, int> > pila;

vector<set<int> > compsbi;
vector<pair<int, int> > puentes;

void dfs(int n, int padre, int prof){
	
	graph[n].prof=prof;
	
	vis[n]=1;
	int curlo=prof;
	bool espunto=false;
	
	forn (i, graph[n].adj.size()){
		if (graph[n].adj[i]==padre){
			padre=-1;
		}
		
		else if (vis[graph[n].adj[i]]) {
			curlo=min(curlo, graph[graph[n].adj[i]].prof);
		}
		else{
			pila.push(mp(n,graph[n].adj[i]));
			dfs (graph[n].adj[i], n, prof+1);
			
			
			curlo=min(curlo, graph[graph[n].adj[i]].lo);
			if (graph[graph[n].adj[i]].lo>=graph[n].prof) {
				articulacion.pb(n);
				int comp=compsbi.size();
				compsbi.pb(set<int>);
			
				while ( pila.top()!=mp(n,graph[n].adj[i])){
					
					
					int adonde=pila.top().y;
					int dedonde=pila.top().x;
					join(adonde, dedonde);
					pila.pop();
				}
				articulacion.pb(n);
				pila.pop();
			}
			espunto=espunto||graph[graph[n].adj[i]].lo >= graph[n].prof;
		}
		
		
		
	}
	
	graph[n].lo=curlo;
	graph[n].punto=espunto;
	return;
}
}

int main(){
	int n, m;
	cin >> n >> m;
	node temp;
	temp.lo = 10000000;
	vis.insert(vis.begin(), n+10, 0);
	graph.insert(graph.begin(), n+10, temp);

	
	forn(i,m){
		int j,k;
		cin >> j >> k;
		graph[j].adj.pb(k);
		graph[k].adj.pb(j);
	}
	
	dfs(1,-1,0);
	return 0;
}
