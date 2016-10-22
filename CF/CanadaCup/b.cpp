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
	
	
	tint n;
	cin>>n;
	char s;
	
	cin>>s;
	
	tint res=1;
	res+=((n-1)/4)*16;
	if (n%2==0) res+=7;
	
	if (s=='e'){
		res+=1;
	}else if (s=='d'){
		res+=2;
	}else if (s=='a'){
		res+=3;
	}else if (s=='b'){
		res+=4;
	}else if (s=='c'){
		res+=5;
	}
	
	cout<<res<<endl;
	return 0;
} 
