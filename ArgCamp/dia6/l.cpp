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

struct nodo{
	vector<int> ady;
	vector<int> adyinv;
}
vector<nodo> grafo;
vector<int>vis;
stack<int> componentes;

void dfs(int n){
	
	vis[n]=1;
	forn(i, grafo[n].ady.size()){
		if(!vis[grafo[n].ady[i]]){
			dfs(grafo[n].ady[i]);
		}
	}
	
	componentes.push(n);
	return;
}

void inv_dfs(int n){
	
	vis[n]=1;
	forn(i, grafo[n].adyinv.size()){
		if(!vis[grafo[n].adyinv[i]]){
			dfs(grafo[n].adyinv[i]);
		}
	}
	
	componentes.push(n);
	return;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int casos;
	cin >> casos;
	int caso = 0;
	while(caso < casos){
		caso++;
		int n, int m;
		cin >> n >> m;
		nodo temp;
		grafo.clear();
		grafo.insert(grafo.begin(), n, temp);
		
		forn(i, m){
			int i, j;
			cin >> i >> j;
			grafo[i].ady.pb(j);
			grafo[j].adyinv.pb(i);
		}
		
		
	}
	
	cin>>lineas;
	
	
		
	return 0;
}
