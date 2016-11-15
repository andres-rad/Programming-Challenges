#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back


int main() {
	
	int k2,k3,k5,k6;
	cin>>k2>>k3>>k5>>k6;
	
	int k256, k32;
	k256=k32=0;
	
	k256=min(k2,min(k5,k6));
	
	k2=max(0, k2-k256);
	cerr<<k2-k256<<endl;
	
	k32=min(k2,k3);
	
	cout<<k32*32+k256*256<<endl;


	return 0;
}
