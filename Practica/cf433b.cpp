//touch {a..m}.in; tee {a..m}.cpp < template.cpp
//#include <bits/stdc++.h>

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef long long int tint;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)

const int MAXN=100100;
int n;

int main() {
	int n;
    while(cin >> n){
		vector<tint> normal;
		vector<tint> ordenados;
		normal.pb(0); ordenados.pb(0);
		
		forn(i,n){
			int t;
			cin>>t;
			ordenados.pb(t);
			
			normal.pb(t+normal[normal.size()-1]);
		}
		
		sort(ordenados.begin(), ordenados.end());
		
		forr (i,1,n+1){
			ordenados[i]=ordenados[i]+ordenados[i-1];
		}
		
		int m;
		cin>>m;
		
		forn (i,m){
			int t;
			cin>>t;
			int l ,r;
			cin>>l>>r;
			
			if (t==1){
				cout<<normal[r]-normal[l-1]<<endl;
				
			}else{
				cout<<ordenados[r]-ordenados[l-1]<<endl;
				
			}
		}
			
		




    }

    return 0;
}
