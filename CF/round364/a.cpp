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
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

int main(){
	vector<pair<int,int> > cartas;
	
	int n;
	cin>>n;
	
	forn (i,n){
		int val;
		cin>>val;
		cartas.pb(mp(val,i+1));
	}
	
	sort(cartas.begin(), cartas.end());
	forn (i,n/2){
		cout<<cartas[i].second<<" "<<cartas[n-i-1].second<<endl;
	}
	return 0;
}
