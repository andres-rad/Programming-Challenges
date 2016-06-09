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


int main () {

	int t=0, tests;
	cin>>tests;



	while (t<tests){
		t++;
		int max=0,maxi;
		int votos=0;
		bool empate=false;

		int n;
		cin>>n;

		forn (i,n){
			int v;
			cin>>v;

			if (v>max) {max=v; 
				empate=false;
				maxi=i+1;
			}
			else if (v==max) {
				empate=true;
			}
			votos+=v;
		}

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