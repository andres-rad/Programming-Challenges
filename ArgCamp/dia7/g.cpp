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
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int casos;
	cin>>casos;
	while (casos>0){
		casos--;
		
		tint ceros, unos;
		cin>>ceros>>unos;
		
		tint res= ceros*ceros;
		if (unos%2==0){
			res-= 2*((unos/2)*(unos/2));
		}else{
			res-= ((unos/2)*(unos/2))+(((unos+1)/2)*((unos+1)/2));
		}
		
		cout<<res<<'\n';
	}
	
	
	return 0;
}
