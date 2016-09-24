
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
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define mp make_pair

using namespace std;



int main() {
	int n,k;
	
	cin>>n>>k;
	
	vector<long long int> costo(n);
	vector<int> capital(k);
	vector<int> escap(n,0);
	
	long long int sumacostos=0;
	forn (i,n){
		int temp;
		cin>>temp;
		sumacostos+=temp;
		costo[i]=temp;
	}
	
	forn (i,k){
		int temp;
		cin>>temp;
		capital[i]=temp-1;
		escap[temp-1]=1;
	}
	
	long long int ans=0;
	vector<int> vis(n,0);
	forn (i,k){
		int cur=capital[i];
		sumacostos-=costo[cur];
		vis[cur]=1;
		ans+=costo[cur]*sumacostos;
	}
	forn (i,n){
		if (!escap[i] && !vis[(i+1)%n]){
			ans+=costo[i]*costo[(i+1)%n];
			vis[(i+1)%n]=1;
			//cout<<i<<" "<<ans<<endl;
		}
	}
	
	cout<<ans<<endl;
		
		
	
	
	
	return 0;

}
