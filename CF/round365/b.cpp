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
}
