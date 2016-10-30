//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define mp make_pair

int main() {

	int p, v;

	cin>>p>>v;

	vector<pair<int, int> > plantas;
	forn (i,p){
		int a, b;
		cin>>a>>b;
		plantas.pb(mp(a,b));
	}

	return 0;
}
