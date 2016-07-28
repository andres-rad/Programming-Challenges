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
#define mp make_pair

#define MAXN 100024

using namespace std;

vector<vector<int > > g;
int d[MAXN], low[MAXN], bcc[MAXN], h[MAXN], pArti[MAXN], comp[MAXN*2], cont_d;

void _dfs(int no, int p){
	bcc[no] = low[no] = d[no] = cont_d++;
	forn(i, g[no].size()) {
		if (p != g[no][i]){
			if (d[g[no][i]] == 0) {
				h[no]++;
				comp[bcc[no]=cont_d++] = no;
				_dfs(g[no][i], no);
				low[no] = min(low[no],low[g[no][i]]);
				pArti[no] |= (low[g[no][i]] >= d[no]);
			} else {
				low[no] = min(low[no], bcc[g[no][i]]);
			}
		}
	}
}

void _dfs2(int no, int p){
	bcc[no] = -1;
	
	if(d[p] > low[no]){
		low[no] = low[p];
	}
	
	forn(i,g[no].size()){
		if(bcc[g[no][i]] > 0) _dfs2(g[no][i], no);
	}
}

void init(){
	cont_d = 1;
	forn(i, g.size()*2) comp[i] = -1;
	forn(i, g.size()) pArti[i] = d[i] = h[i] = 0;
	forn(i, g.size()) if(d[i] == 0) { _dfs(i,-1); pArti[i] = h[i] >=2;}
	forn(i, g.size()) if(bcc[i] > 0) _dfs(i,i);
}

vector<vector<int> > componentesBiconexas(){
	vector<vector<int> > res;
	map<int, int> mapeo; int cont = 1;
	forn (i, g.size()){
		if ( low[i] >= d[i]) continue;
		if (mapeo[low[i]]==0){
			mapeo[low[i]] = cont++;
			res.pb(vector<int>(1,comp[low[i]]));
		}
	}
		return res;
}

bool esPA(int i){
	return pArti[i];
}
bool esPuente(int i, int j){ return (low[i] != low[j] && comp[low[i]] != j && comp[low[j]] != i);}

int main(){
	int n, m;
	cin >> n >> m;
	g.insert(g.begin(), n+10, vector<int>(0));
	forn(i, m){
		int j,k;
		cin >> j >> k;
		g[j].pb(k); g[k].pb(j);
	}
	init();
	vector<vector<int> > comp = componentesBiconexas();
	cout << comp.size() << endl;
	forn(i, comp.size()){
		cout << comp[i].size() << "    ";
		forn(j, comp[i].size()){
			cout << comp[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}
