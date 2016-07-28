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
#include <sstream>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef long long int tint;

vector<int> _cl;
int cl (int i ){
	return ((_cl[i]==-1)?i:_cl[i]=cl(_cl[i]));
}

void join (int i, int j){
	if (cl(i)!=cl(j)){
		_cl[cl(i)]=cl(j);
	}
	return;
}

void init (int n){
	_cl.clear();
	_cl.insert(_cl.begin(), n, -1);
}

int main(){
	
	int n;
	cin>>n;
	vector<pair<int, int> > circulos;
	
	forn (i,n){
		int x, r;
		cin>>x>>r;
		
		circulos.pb(mp(x-r, i));
		circulos.pb(mp(x+r,i));
	}
	
	sort(circulos.begin(), circulos.end());
	
	vector<pair<int, int> > circles(n, mp(-1,-1));
	int last=0;
	int lasti=n+3000;
	forn(i, circulos.size()){
		int circ=circulos[i].second;
		if (circulos[i].first==last && i>0){
			if (circles[circ].first==-1){
				circles[circ].first=lasti;
			}else{
				circles[circ].second=lasti;
			}
			
		}else if (circles[circ].first==-1){
			circles[circ].first=i;
			last=circulos[i].first;
			lasti=i;
		}else{
			
			circles[circ].second=i;
			last=circulos[i].first;
			lasti=i;
		}
		//cout<<circles[circ].first<<"  "<<circles[circ].second<<endl;
	}
	
	init(700000);
	
	int res=1;
	
	forn (i,n){
		int l=circles[i].first, r=circles[i].second;
		
		//cout<<l<<"   "<<r<<endl;
		//
		if (cl(l)==cl(r)){
			res+=2;
		}else {
			res++;
		}
		join(l,r);
	}
	
	cout<<res<<endl;
		
	
	
	return 0;
}
