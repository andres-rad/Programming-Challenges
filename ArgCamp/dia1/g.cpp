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

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

struct nodo{
	vector<int> ady;
};

vector<int> visitado;

void dfs(int desde, vector<nodo> & grafo){
	visitado[desde]=1;

	forn (i, grafo[desde].ady.size()){
		if (!visitado[grafo[desde].ady[i]]){
			dfs(grafo[desde].ady[i], grafo);
		}
	}
	return;
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,m,k;
	cin>>n>>m>>k;

	vector<int> tipos(n);

	vector<vector<int> > caminos (k, vector<int> (k, 30000));

	int t=0;

	//vectir<bool> optimo(k, false);
	vector<int> rep(k,0);

	forn (i,k){
		int hasta;
		cin>>hasta;
		if (hasta==1){
			caminos[i][i]=0;
			//optimo[i]=true;
		}
		rep[i]=t;
		for (int desde=t; desde<t+hasta; desde++){
			tipos[desde]=i;
		}
		t=t+hasta;
	}

	nodo temp;

	vector<nodo> grafo(n, temp);

	forn (i,m){
		int x,y,z;
		cin>>x>>y>>z;
		caminos[tipos[x-1]][tipos[y-1]]=min(caminos[tipos[x-1]][tipos[y-1]], z);
		caminos[tipos[y-1]][tipos[x-1]]=min(caminos[tipos[y-1]][tipos[x-1]], z);
		if (z==0){
			grafo[x-1].ady.pb(y-1);
			grafo[y-1].ady.pb(x-1);
		}
	}

	int tt=0;
	bool optimo=true;
	while (tt<n && optimo){
		visitado.clear();
		visitado.insert(visitado.begin(), n, 0);
		dfs(tt, grafo);

		int lasttipo=tipos[tt];
		while (tt<n && optimo && tipos[tt]==lasttipo){
			optimo=optimo && (visitado[tt]==1);
			tt++;
		}

	}








	forn(h, k){
		forn(i,k){
			forn(j,k){
				caminos[i][j]=min(caminos[i][j], caminos[i][h]+caminos[h][j]);
				/*
				if (i==j && caminos[i][j]!=0) {
					optimo =false;
				}
				*/
			}
		}
	}


	if (optimo){
		cout<<"Yes"<<endl;
		forn (i,k){
			forn(j,k-1){
				cout<<(caminos[i][j]==30000?-1:caminos[i][j])<<" ";
			}
			cout<<(caminos[i][k-1]==30000?-1:caminos[i][k-1])<<'\n';

		}
	}else{
		cout<<"No"<<endl;
	}

	return 0;
}
