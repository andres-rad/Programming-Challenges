#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back


int main() {
	long long int n,m ,k;
	cin>>n>>m>>k;
	
	long long int x,s;
	cin>>x>>s;
	
	vector<long long int> prim(m);
	vector<long long int> primcost(m);
	
	forn(i,m){
		cin>>prim[i];
	}
	
	forn(i,m){
		cin>>primcost[i];
	}
	
	vector<long long int> sec(k);
	vector<long long int> seccost(k);
	
	seccost.pb(0);
	sec.pb(0);
	
	forn(i,k){
		cin>>sec[i+1];
	}
	
	forn(i,k){
		cin>>seccost[i+1];
	}
	
	long long int ans=n*x;
	
	prim.pb(x);
	prim.pb(0);
	
	forn(i,m+1){
		long long int cur=s-primcost[i];
		
		if(cur<0) continue;
		
		long long int hi=k;
		long long int lo=0;
		
		while (lo+1<hi){
			long long int me=(hi-lo)/2 + lo;
			
			if (seccost[me]> cur){
				hi=me;
			}else{
				lo=me;
			}
			
		}
		
		
		
		cerr<<"lo "<<lo<<" hi "<<hi<<endl;
		
		if(seccost[hi]<=cur){
			lo=hi;
		}
		
		cerr<<"lo "<<lo<<endl;
		
		ans=min(ans, (n-sec[lo])*prim[i]);
		
		
		
		
		
		
	}
	
	cout<<ans<<endl;
	
	


	return 0;
}
