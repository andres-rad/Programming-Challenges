#include "math.h"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "iostream"
#include "cstring"
#include "stdlib.h"


#define tint long long
#define utint unsigned long long
#define forsn(i,s,n) for(tint i = s; i < n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define mp make_pair

using namespace std;


struct nodo{
	vector<int> adj;

};

pair<int,int> dfs(int start, vector<int> & vis , const vector<nodo> & grafo ){
	if (vis[start]) return mp(0,0);

	vis[start]=1;
	pair<int,int> ans = mp(1,0);
	forn(i, grafo[start].adj.size()){
		pair<int,int> tempans=dfs(grafo[start].adj[i], vis, grafo);
		ans.first+=tempans.first;
		ans.second+=tempans.second+1;
	}
	//ans.second--;

	//cout<<start<<endl<<ans.first<<endl<<ans.second<<endl;
	return ans;
}


int main() {
	

	int n,m,r,e;

	while (cin>>n){
		cin>>m>>r>>e;

		vector<nodo> grafo (n+2);

		forn(i,m){
			int a,b;
			cin>>a>>b;

			grafo[a].adj.pb(b);
			grafo[b].adj.pb(a);
		}

		int ans=0;

		int i=1;
		vector<int> vis (n+2, 0);

		while (i<n+1){
			pair<int,int> anspair=dfs(i,vis,grafo);
			//anspair.second++;
			anspair.second=anspair.second/2;

			ans+=min(anspair.first*e, ((anspair.first*(anspair.first-1))/2-anspair.second)*r);

			while (i<n+1 && vis[i]){
				i++;
			}

		}

		cout<<ans<<endl;

	}




	return 0;

}
