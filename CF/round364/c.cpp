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
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

int main(){
	int n;
	cin>>n;
	vector<int> vistos(130, 0);
	
	vector<char> cadena ;
	
	forn (i,n){
		char temp;
		cin>>temp;
		vistos[temp]=-1;
		cadena.pb(temp);
	}
	
	vector<int> res (n, 200000);
	
	int start=0;
	int end=0;
	
	int cntzer=0;
	forn (i, vistos.size()){
		if (vistos[i]==0) cntzer++;
	}
	
	while (start<n){
		//cout<<cadena[start]<<endl;
		while (end<n && cntzer!=vistos.size()){
			
			vistos[cadena[end]]++;
			//if (vistos[cadena[end]]==1) cntzer--;
			if (vistos[cadena[end]]==0) cntzer++;
			end++;
		}
		if (cntzer==vistos.size()) res[start]=end-start;
		vistos[cadena[start]]--;
		if (vistos[cadena[start]]==-1) cntzer--;
		//if (vistos[cadena[start]]==0) cntzer++;
		start++;
	}
	
	int mini=2000000;
	
	forn (i, res.size()){
		mini=min(mini, res[i]);
	}
	
	cout<<mini<<endl;
		
	return 0;
}
