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

int lnds(vector<int> &a){
	vector<int> longest (a.size(), 1);
	int ans=1;
	forr (i,1,n){
		forn(j,i){
			if (a[j]<=a[i]){
				//dprint(i);dprint(j);
				longest[i]=max(longest[i], longest[j]+1);
			}
		}
		ans=max(ans, longest[i]);
	}
	
	return ans;
}
int main() {
	
    while(cin >> n){
		int m;
		cin>>m;
		
		vector<int> tipos;
		
		forn (i,n){
			int a;
			double b;
			cin>>a>>b;
			tipos.pb(a);
		}
		
		
		cout<<n-lnds(tipos)<<endl;
	}

    return 0;
}
