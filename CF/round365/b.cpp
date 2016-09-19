<<<<<<< HEAD
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
=======
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
>>>>>>> bff007fc3750c113e4aecb89b73f259b55471335
#define pb push_back
#define mp make_pair

using namespace std;

<<<<<<< HEAD


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

=======
typedef pair<int,int> par;
typedef long long int tint;

int main(){

	int n, k;
	cin>>n>>k;

	vector <int> costos (n);
	vector<int> costosarr (n,0);

	forn (i,n){
		int c;
		cin>>c;
		costos[i]=c;
		costosarr[i]=c+costosarr[max(i-1,0)];
	}
	//costosarr[0]=costos[0];

	vector <int> capitales ;
	vector <bool> escap (n, false);

	forn (i,k){
		int cap;
		cin>>cap;
		capitales.pb(cap-1);
		escap[cap-1]=true;
	}

	tint res=0;

	forn (i,n){
		res+= costos[i]*costos[(i+1)%n];
	}

	forn (i,k){
		int capi=capitales[i];
		/*if ((capi+2)<=n){
			res+=(costosarr[0]-costosarr[max(capi+1,n-1)])*costos[capi];
		}
		if (capi-2>0){
			res+=(costosarr[capi-2])*costos[capi];
		}*/
		res+=(costosarr[n-1]-costos[capi]-costos[(capi-1)%n]-costos[(capi+1)%n])*costos[capi];
		for (int j=i+1; j<k; j++){
			if (capitales[j]!=(capi+1)%n && capitales[j]!=(capi-1)%n) res-=costos[capi]*costos[capitales[j]];
		}
		/*
		for (int i =capi+2;i-capi+1<n ;i++){
			if (!escap[i%n] || i%n>capi) res+=costos[capi]*costos[i%n];
		}
		*/
	}

	cout<<res<<endl;

	return 0;
>>>>>>> bff007fc3750c113e4aecb89b73f259b55471335
}
