#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back


int main() {
	int n,a,d;
	cin>>n;
	a=d=0;
	
	forn(i,n){
		char b;
		cin>>b;
		
		if (b=='A'){
			a++;
		}else{
			d++;
		}
	}
	
	if (a>d){
		cout<<"Anton"<<endl;
	}else if(d>a){
		cout<<"Danik"<<endl;
	}else{
		cout<<"Friendship"<<endl;
		
	}


	return 0;
}
