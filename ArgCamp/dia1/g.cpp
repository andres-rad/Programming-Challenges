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

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	vector<int> tipos(n);
	
	vector<vector<int> > caminos (k, vector<int> (k, 30));
	
	int t=0;
	forn (i,k){
		int hasta;
		cin>>hasta;
		if (hasta==1){
			caminos[i][i]=0;
		}
		for (int desde=t; desde<t+hasta; desde++){
			tipos[desde]=i;
		}
		t=t+hasta;
	}
	
	
	
	
	forn (i,m){
		int x,y,z;
		cin>>x>>y>>z;
		caminos[tipos[x-1]][tipos[y-1]]=min(caminos[tipos[x-1]][tipos[y-1]], z);
		caminos[tipos[y-1]][tipos[x-1]]=min(caminos[tipos[y-1]][tipos[x-1]], z);
	}
	
		

	bool optimo =true;
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
	
	forn (i,k){
		optimo=optimo& caminos[i][i]==0;
	}
	
	if (optimo){
		cout<<"YES"<<endl;
		forn (i,k){
			forn(j,k-1){
				cout<<(caminos[i][j]==30?-1:caminos[i][j])<<" ";
			}
			cout<<(caminos[i][k-1]==30?-1:caminos[i][k-1])<<'\n';
			
		}
	}else{
		cout<<"NO"<<endl;
	}
	
	return 0;
}
