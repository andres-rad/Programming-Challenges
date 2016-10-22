#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef long long tint;



int main(){
	
	int n;
	cin>>n;
	
	int res=0;
	
	string inp;
	cin>>inp;
	
	forn(i,n){
		if (inp[i]=='>') break;
		res++;
	}
	
	
	forn(i,n){
		if (inp[n-1-i]=='<') break;
		res++;
	}
	
	cout<<res<<endl;
	
	
	return 0;
} 
