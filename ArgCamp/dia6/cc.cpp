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

typedef long long int tint;





int main(){
	
	int l, n;
	cin>>l>>n;
	
	vector<int> toneles;
	
	forn (i,n){
		int a;
		cin>>a;
		toneles.pb(a);
		
	}
	
	set<int> primerospasos;
	
	int movs=0;
	
	int flag=toneles[0];
	int prpaso=0;
	forn (i,n-1){
		if ( flag+toneles[i+1]<=l){
			
			flag+=toneles[i+1];
		}else{
			prpaso=i+1;
			flag= toneles[i+1];
		}
	}
	
	
	forn (i, primerospasos.size()){
		cout<<*primerospasos.begin()<<endl;
		primerospasos.eras(primerospasos.begin());
	}
	
	
	return 0;
}
