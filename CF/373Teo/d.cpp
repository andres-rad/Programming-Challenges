#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define fs first
#define sd second

	vector<int> t;
	vector<int> lista;

bool (f(int copias, int segundos,int maq)){

	int ans=0;
	forn (i,maq){
		if (lista[i]<=segundos){
			ans+=(segundos-lista[i])/t[i];
		}
	}

	return (ans>=copias);
}


int main () {
	int n, m;

	cin>>n;
	cin>>m;




	forn (i,n){
		int temp;
		cin>>temp;
		t.pb(temp);
	}

	sort(t.begin(), t.end());

	vector<int> queries;

	forn(i,m){
		int temp;
		cin>>temp;
		queries.pb(temp);
	}

	lista=vector<int> (n,0);
	lista[0]=0;
	for(int i=1;i<n;i++){
		long long int hi=1000000000, lo=lista[i-1], copias=i;

		while (lo<hi-1){
			int m=(lo+hi)/2;
			if (f(copias, m, i)){
				hi=m;
			}else{
				lo=m;
			}
		}
		lista[i]=hi;
	}

	forn (i,m){
		long long int hi=1000000000, lo=0, copias=queries[i];

		while (lo<hi-1){
			int m=(lo+hi)/2;
			if (f(copias, m, n)){
				hi=m;
			}else{
				lo=m;
			}
		}
		cout<<hi<<endl;
		//lista[i]=lo;
	}

	return 0;
}