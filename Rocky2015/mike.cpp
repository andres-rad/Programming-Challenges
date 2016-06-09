#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define matriz vector<vector<char> >
#define mp make_pair
int main () {

	int t=0, tests;
	cin>>tests;



	while (t<tests){
		t++;
		int p,q;
		int votos=0;
		
		int n;
		cin>>n;
		vector<pair <int, int> > mano;
		forn (i,n){
			pair<int, int> carta;
			cin>>p>>q;
			carta = mp(p, q);
			mano.pb(carta);
		}
		sort();



		if (empate){
			cout<<"no winner"<<endl;
		}else if (2*max>votos){
			cout<<"majority winner "<<maxi<<endl;

		}else {
			cout<<"minority winner "<<maxi<<endl;
		}
	}

		



	return 0;
	}