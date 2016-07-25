#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
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

typedef  long long int tint;

using namespace std;

struct node{
	vector<int> adj;
	int lo;
	int prof;
	bool punto;
};

vector<int> vis;
vector<node> graph;

tint res, combs;

stack <pair<int, int> > pila;

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
					}
					//cout<<adonde<<"  "<<graph[adonde].punto<<endl;
					//cout<<n<<"  "<<cntp<<endl;
					
					pila.pop();
					//res++;
					cant++;
				}
				pila.pop();
				
				if (!cntp){
					cout<<n<<"  "<<cntp<<endl;
					res++;
					
					combs*=cant;
				}
				
				/*
				if (!(cant==1 && graph[graph[n].adj[i]].adj.size()>1)) {
					res++;
					
				}else if (cant>1){
					res++;
				}
				*/
				
				// cant>1 &&
					
					
				//puentes.pb(mp(n, graph[n].adj[i]));
				//join(n, graph[n].adj[i]);
			}
			espunto=espunto||graph[graph[n].adj[i]].lo >= graph[n].prof;
		}
		
		
		
	}
	
	graph[n].lo=curlo;
	graph[n].punto=espunto;
	return;
}

int main(){
	
	int n;
	cin>>n;
	
	int caso=1;
	
	
	
	
	
	
	while (n!=0){
		
		graph.clear();
		vis.clear();
		vis.insert(vis.begin(),200000, 0); 
		res=0;
		combs=1;
		
		node temp;
		temp.lo=10000000;
		temp.punto=false;
		graph.insert(graph.begin(), 200000, temp);
		int a,b;
		forn (i,n){
			
			cin>>a>>b;
			
			graph[a].adj.pb(b);
			graph[b].adj.pb(a);
			
		}
		
		dfs(1, -1, 0);
		
		/*
		if (graph[1].adj.size()==1){
			res++;
		}
		*/
		
		cout<<"Case "<<caso<<": "<<res<<" "<<combs<<'\n';
		caso++;
			
			
			
		cin>>n;
		
	}
	
	
	return 0;
}
