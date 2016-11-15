#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define mp make_pair



int main() {
	cin.tie(NULL);
	
	int n;
	
	cin>>n;
	
	vector<pair<int, int> > puntosx (0);
	vector<pair<int, int> > puntosy (0);
	vector<pair<int, int> > puntosrotx (0);
	vector<pair<int, int> > puntosroty (0);
	
	int rx,ry;
	cin>>rx>>ry;
	
	
	
	
	forn(i,n){
		char a;
		long long int x,y;
		cin>>a>>x>>y;
		
		if (ry==y) puntosx.pb(mp(x,(a=='R' || a=='Q'?1:0)));
		if (rx==x) puntosy.pb(mp(y,(a=='R' || a=='Q'?1:0)));
		
		if (rx+ry==x+y) puntosrotx.pb(mp(x-y, (a=='B' || a=='Q'?1:0)));
		if (rx-ry==x-y) puntosroty.pb(mp(x+y, (a=='B' || a=='Q'?1:0)));
	}
	
	int res=0;
	
	
	sort(puntosx.begin(), puntosx.end());
	
	int hi=puntosx.size();
	int lo=0;
	
	while(lo+1<hi){
		int m=(hi-lo)/2+lo;
		
		if (rx<puntosx[m].first){
			lo=m;
		}else{
			hi=m;
		}
	}
	
	res=res|puntosx[lo].second|(hi<puntosx.size() && puntosx[hi].second);
	
	sort(puntosy.begin(), puntosy.end());
	
	 hi=puntosy.size();
	 lo=0;
	
	while(lo+1<hi){
		int m=(hi-lo)/2+lo;
		
		if (rx<puntosy[m].first){
			lo=m;
		}else{
			hi=m;
		}
	}
	
	res=res|puntosy[lo].second|(hi<puntosy.size() && puntosy[hi].second);
	
	sort(puntosroty.begin(), puntosroty.end());
	
	 hi=puntosroty.size();
	 lo=0;
	
	while(lo+1<hi){
		int m=(hi-lo)/2+lo;
		
		if (rx<puntosroty[m].first){
			lo=m;
		}else{
			hi=m;
		}
	}
	
	res=res|puntosroty[lo].second|(hi<puntosroty.size() && puntosroty[hi].second);
	
	sort(puntosrotx.begin(), puntosrotx.end());
	
	 hi=puntosrotx.size();
	 lo=0;
	
	while(lo+1<hi){
		int m=(hi-lo)/2+lo;
		
		if (rx<puntosrotx[m].first){
			lo=m;
		}else{
			hi=m;
		}
	}
	
	res=res|puntosrotx[lo].second|(hi<puntosrotx.size() && puntosrotx[hi].second);
		
	cout<<(res?"YES":"NO")<<endl;
		

	return 0;
}
