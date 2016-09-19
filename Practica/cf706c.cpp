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

bool lexo( string a, string b){
	if (a==b) return true;
	int i=0, tot=min(a.size(), b.size());
	while (i<tot && a[i]==b[i]){
		i++;
	}
	
	if (i== tot) return a.size()<b.size();
	
	return a[i]<b[i];
}
	
int main() {
	int n;
    while(cin >> n){
		
		vector<tint> costo, rever, norm;
		forn (i,n){
			int t;
			cin>>t;
			costo.pb(t);
			rever.pb(200000000000000);
			norm.pb(200000000000000);
		}
		
		string ant;
		cin>>ant;
		rever[0]=costo[0], norm[0]=0;
		
		forr (i,1,n){
			string cur;
			
			cin>>cur;
			
			string rcur, rant;
			rant=ant; reverse(rant.begin(), rant.end());
			rcur=cur; reverse(rcur.begin(), rcur.end());
			
			bool poss=false;
			if (lexo(ant,cur)){
				norm[i]=min(norm[i-1], norm[i]);
				poss=true;
			}
			if (lexo(rant,cur)){
				norm[i]=min(rever[i-1], norm[i]);
				poss=true;
			}
			if (lexo(ant,rcur)){
				rever[i]=min(norm[i-1]+costo[i], rever[i]);
				poss=true;
			}
			if (lexo(rant,rcur)){
				rever[i]=min(rever[i-1]+costo[i], rever[i]);
				poss=true;
			}
			ant=cur;
			
		}
		
		if (min(rever[n-1], norm[n-1])==200000000000000){
			cout<<"-1"<<endl; return 0;
		}
		
		cout<<min(rever[n-1], norm[n-1])<<endl;
		




    }

    return 0;
}
