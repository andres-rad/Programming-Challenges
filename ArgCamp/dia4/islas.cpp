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
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

int main(){

	int n;
	
	cin>>n;
	
	vector<int> alt;
	set<pair<int,int> > miset;
	int nn=0;
	int ant=-1;
	forn(i,n){
		int h;
		cin>>h;
		if (h==ant){
			nn++;
		}else{
			alt.pb(h);
			miset.insert(mp(h,i-nn));
		}
		ant=h;
	}
	nn=n-nn;
	int maxislas=0;
	int islas=0;
	
	while (!miset.empty()){
		int altura;
		altura=miset.rbegin()->x;
		
		//pos=*miset.rbegin().y;
		
		while (!miset.empty() && miset.rbegin()->x==altura){
			int curalt, curpos;
			curalt=miset.rbegin()->x;
			
			curpos=miset.rbegin()->y;
			set<pair<int,int> > ::iterator it=miset.end();
			it--;
			miset.erase(it);
			
			//cout<<curpos<<endl;
			if (curpos==0 || alt[curpos-1]<curalt){
				
				if (curpos ==nn-1 || alt[curpos+1]<curalt){
					islas++;
				}
				
			}else if (alt[curpos-1]>curalt){
				if (curpos!=nn-1 &&    alt[curpos+1]>curalt){
					islas--;
				}
			}
			
			
			
		}
		maxislas=max(maxislas,islas);
	}
	
	cout<<maxislas<<endl;
			
			
	return 0;
}
