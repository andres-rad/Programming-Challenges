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
	int mo=10*10*10*10*10*10*10*10*10+7;

	while (t<tests){

		string str;
		cin>>str;
		int q;
		cin>>q;

		vector< vector<int> > ind(25, vector<int>(0));

		forn (i, str.size()){
			ind[str[i]-'a'].pb(i);
		}
		forn(i,q){
			int t;
			cin>>t;
			if (t==0){
				int pl;
				char c;
				cin>>pl>>c;
				str[pl-1]=c;
			}else{
				int l,r,wh;
				cin>>l>>r>>p;

				l--;
				p--;

				int min=p-1;
				forn (i,25){
					bool br=false;
					forn (j, ind[i].size()){
						if 
	}
	return 0;
}
