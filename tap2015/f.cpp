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
	int eq;

};

vector<vector<int> > disco;
vector<nodo> grafo;
vector<int> mindisco;
vector<int> vis;
int n,e;

vector<int> dfs(int start, bool raiz){
	
	vis[start]=1;

	int equipo = grafo[start].eq;
	vector<int> res(e,0);

	if (!raiz && grafo[start].adj.size()==1) {
		if (equipo != -1) return disco[equipo];
		return mindisco;
	}

	if (equipo != -1){
		if (!raiz){
			forn(i,e){
				res[i] = disco[i][equipo];
			}
		}

		forn(i, grafo[start].adj.size()){
			if (!vis[grafo[start].adj[i]]){
				vector<int> tempans=dfs(grafo[start].adj[i],false);
				forn (i,e){
					res[i] += tempans[equipo];
				}

			}

		}
	} else {
		// no tengo equipo

		vector<vector<int> > mimat;
		if (!raiz) mimat = disco;
		else mimat=vector<vector<int > > (e, vector<int> (e,0));

		forn(vi, grafo[start].adj.size()){
			int v = grafo[start].adj[vi];
			if (!vis[v]){
				vector<int> tempans = dfs(v,false);
				forn (i,e){
					forn(j,e){
						mimat[i][j] += tempans[j];
					}
				}
			}
		}

		forn (i,e){
			int mi=1000000;
			forn(j,e){
				mi=min(mi, mimat[i][j]);
			}
			res[i]=mi;
		}
	}
	
	return res;
}


int main() {

	while (cin>>n){
		cin>>e;

		vis=vector<int> (n,0);

		disco=vector< vector<int> > (e, vector<int> (e));
		mindisco=vector<int> (e,1000000);
		forn(i,e){
			int mi=100000;
			forn(j,e){
				int temp;
				cin>>temp;
				mi=min(mi,temp);
				disco[i][j]=temp;
			}
			mindisco[i]=mi;
		}

		nodo temp;
		temp.eq=-1;
		grafo=vector<nodo> (n,temp);

		forn (i,e){
			int k;
			cin>>k;
			forn (j,k){
				int t;
				cin>>t;

				grafo[t-1].eq=i;
			}
		}

		forn(i,n-1){
			int a,b;
			cin>>a>>b;

			grafo[a-1].adj.pb(b-1);
			grafo[b-1].adj.pb(a-1);

		}

		vector<int> res=dfs(0, true);

		int ans=res[0];

		forn(i,e){
			ans=min(ans, res[i]);
		}

		cout<<ans<<endl;
	}


	return 0;

}
