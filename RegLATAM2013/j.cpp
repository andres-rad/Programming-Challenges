#include <bits/stdc++.h>
#define forsn(i,s,n) for(int i = s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define fst first
#define snd second

using namespace std;

int dfs(int i, int nivel, vector<vector<int> > G){
	
	vector<bool> vis(G.size(), false);
	vis[i] = true;
	forn(j, G[i].size()){
		if(!visN[G[i][j]]){
			dfs(G[i][j], nivel + 1, G);
		}
	}
	caminoMaxN
}

int main() {
	long n;

	while(cin >> n){
		long q;
		cin >> q;

		vector<vector<int> > nlog(n);
		vector<vector<int> > quad(q);
		vector<int> caminoMaxN(n, 0);
		vector<int> caminoMaxQ(q, 0);
		
		forn(i, n){
			int j, k;
			cin >> j >> k;
			nlog[i-1].push_back(j-1);
			nlog[j-1].push_back(i-1);
		}

		forn(i, q){
			int j, k;
			cin >> j >> k;
			quad[i-1].push_back(j-1);
			quad[j-1].push_back(i-1); 
		}

		extremo = dfs(0, 0, nlog);

	}

	return 0;
}