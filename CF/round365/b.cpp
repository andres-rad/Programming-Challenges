#include "math.h"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "iostream"
#include "cstring"
#include "stdlib.h"


#define tint long long
#define utint unsigned long long
#define forsn(i,s,n) for(tint i = s; i < n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define mp make_pair

using namespace std;



int main() {
	int n,k;
	
	cin>>n>>k;
	
	vector<int> costo(n);
	vector<int> capital(n,0);
	
	int suma=0;
	
	forn(i,n){
		int t;
		cin>>t;
		suma+=t;
		costo[i]=t;
	}
	vector<int> costor=costo;
	
	forn(i,k){
		int t;
		cin>>t;
		capital[t-1]=1;
	}
	
	long long int ans=0;
	forn(i,n){
		if (capital[i]){
			suma-=costo[i];
			if (i-1>0)suma-=costor[i-1];
			ans+=costo[i]*(suma);
			costo[i]=0;
		}else{
			ans+=costo[i]*(costo[(i-1+n)%n]+costo[(i+1+n)%n]);
			costo[i]=0;
		}
		
		//cout<<i<<" "<<ans<<endl;
	}
	
	cout<<ans<<endl;
	
	
	return 0;

}
