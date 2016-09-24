#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <functional>

using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair


int main () {

	int t=0, tests;
	cin>>tests;

	while (t<tests){
		t++;

		long long int n,m,k,e;
		cin>>n>>k>>e>>m;

		long long int puntos[n]={0};

		forn (i,n-1){
			forn (j, e){
				long long int te;
				cin>>te;
				puntos[i]+=te;
			}
		}

		forn (j, e-1){
			long long int t;
			cin>>t;
			puntos[n-1]+=t;
		}
		sort(puntos, puntos+n-1);

		long int last=puntos[n-k-1];
		long int ser=puntos[n-1];
		ser=1+last-ser;

		if (ser<=0){
			cout<<0<<endl;
		}else if (ser>m){
			cout<<"Impossible"<<endl;
		}else {
			cout<<ser<<endl;
		}


	}
	return 0;
}
