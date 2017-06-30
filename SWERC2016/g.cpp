#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
#define INF 1e9
typedef long long ll;
typedef pair<int,int> ii;
typedef double tipo;

const int MAXN=100100;

struct nodo{
	int bordes[4];
	int libre;
	vector<int> adj;
	bool vis;
}

int code(int i, int j, int a){
	return i*2 + j*251*2 + a;
}

int n, m;
vector<node> g;
int borde_minimo[4];
int error[1] = { -1 };

int esborden(int i, int j, int a, int borde){
	if (a){
		if (borde==1 && j==0 ){
			return 1;
		}else if (borde==2 && i==0){
			return 1;
		}else if (borde==3 && j==m-1 && i%2==0){
			return 1;
		}else if (borde==4 && i==n-1 && j%2==0){
			return 1;
		}


	}else{
		if (borde==3 && j==m-1 ){
			return 1;
		}else if (borde==4 && i==n-1){
			return 1;
		}else if (borde==1 && j==0 && i%2==0){
			return 1;
		}else if (borde==2 && i==0 && j%2==0){
			return 1;
		}

	}
	return 0;
}

int[] dfs(int v){

	int sig;
	if(v.vis) return error;
	g[v].vis = 1;

	stack<int> pila;
	forn(i, g[v].size()) pila.push(g[v].adj[i]);


}



int main() {
  int t;
	cin>>t;
	forn(jjj,t){
		g(n*2 + m*251*2 +100);
		cin>>n>>m;

		forn(i,n){
			forn(j,m){
				int a, b;
				cin>>a>>b;

				auto codea = code(i ,j, 1);
				auto codeb = code(i, j, 0);

				g[codea].libre = a;
				g[codeb].libre = b;

				g[codea].vis = g[codeb].vis = 0;

				g[codea].bordes={esborden(i,j,1, 1),esborden(i,j,1, 2),esborden(i,j,1, 3),esborden(i,j,1, 4)};
				g[codeb].bordes={esborden(i,j,0, 1),esborden(i,j,0, 2),esborden(i,j,0, 3),esborden(i,j,0, 4)};

				g[codea].adj.pb(codeb);
				g[codeb].adj.pb(codea);

				if(i>0) {
					g[codea].adj.pb(code(i-1, j, 1));
					g[codea].adj.pb(code(i-1, j, 0));
				}

				if (j > 0) {
					g[codea].adj.pb(code(i, j-1, 0));
					g[codeb].adj.pb(code(i, j-1, 0));

				}

				if (j < m-1) {
					g[codea].adj.pb(code(i, j+1, 1));
					g[codeb].adj.pb(code(i, j+1, 1));
				}

				if (i < n-1) {
					g[codeb].adj.pb(code(i+1, j, 1));
					g[codeb].adj.pb(code(i+1, j, 0));
				}

			}
		}
	}
  return 0;
}
