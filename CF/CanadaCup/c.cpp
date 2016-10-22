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
	
	string s;
	cin>>s;
	
	vector<int> count(1000, 0);
	
	forn(i,s.size()){
		count[int(s[i])]++;
	}
	
	
	
	
	char rep;
	forr(i, int('A'), int('Z')+1){
		if (count[i]==2) rep=char(i);
	}
	
	
	
	//cout<<rep<<endl;
	
	int pos1=-1; int pos2;
	
	forn(i, s.size()){
		if (s[i]==rep && pos1==-1) pos1=i;
		else if(s[i]==rep) pos2=i;
	}
	
	//cout<<pos1<<" "<<pos2<<endl;
	
	if (pos2-pos1==1){
		cout<<"Impossible"<<endl;
		return 0;
		
		
	}
	
	vector<char>res (26);
	
	int put=12-(pos2-pos1-1)/2;
	
	res[put]=rep;
	
	put++;
	int donde=pos1+1;
	while (donde!=pos1){
		res[put]=s[donde];
		donde++;
		put++;
		if(donde==pos2) donde++;
		put=put%26;
		donde=donde%27;
	}
	
	forn(i,13){
		cout<<res[i];
	}
	cout<<endl;
	
	forn (i,13){
		cout<<res[25-i];
	}
	cout<<endl;
	
	
	return 0;
} 
