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
	vector<int> adjinv;
	int capacidad;
};



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
				int cant=1;
				
				int cntp=0;
				while (!cntp && pila.top()!=mp(n,graph[n].adj[i])){
					
					int adonde=pila.top().y;
					if (graph[adonde].punto){
						cntp++;
					}op();
	
					cant++;
				}
				pila.pop();
				if (!cntp){
					cout<<n<<"  "<<cntp<<endl;
					res++;
					
					combs*=cant;
				}
			}
			espunto=espunto||graph[graph[n].adj[i]].lo >= graph[n].prof;
		}
		
		
		
	}
	
	graph[n].lo=curlo;
	graph[n].punto=espunto;
	return;
}
}

void bfs(int  rank[]){
	queue<int> cola;
	vector<int> vis (20020, 0);
	
	cola.push(10015);
	rank[10015]=0;
	
	while (!cola.empty()){
		int n=cola.front;
		vis[n]=1;
		cola.pop;
		
		forn (i, grafo[n].adjinv.size()){
			if (!vis[grafo[n].adjinv[i]]){
				cola.push(grafo[n].adjinv[i]);
				rank[grafo[n].adjinv[i]]=rank[n]+1;
			}
		}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	while (n!=0 && m != 0 ){
		
		node grafo[20020];
		
		forn (i, m){
			int a,b;
			cin>>a>>b;
			grafo[a].adj.pb(b+10010);
			grafo[b+10010].adjinv.pb(a);
		}
		
		forsn (i,1,n+1){
			grafo[0].adj.pb(n);
			grafo[i].adjinv.pb(0);
		}
		
		forsn (i,1+10010,n+10010+1){
			grafo[20015].adj.pb(i);
			grafo[i].adjinv.pb(20015);
		}
		
		while (alcanzo){
			rank[20020]={0};
			
			bfs(rank);
		
		
			
		
		cin>>n>>m;
	}
	return 0;
}

