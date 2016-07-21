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

string elChiquito, elGrandote;

int main(){
	//criba();
	
	/*for (char c = 'A'; c-0<='A'+60; c=(char)c+1){
		cout<<c<<c-0<<endl;
	}*/
	int g,n;
	cin>>g>>n;
	
	
	
	vector<int> pg(60,0);

	cin >> elChiquito >> elGrandote;
	int cntz=60, cnt1=0;
	forn(i,g) {
		if (pg[elChiquito[i]-'A'] ==0){
			cntz--;
			cnt1++;
		}
		pg[elChiquito[i]-'A']++;
		
	}
	
	//vector<int> ps(60,0);
	
	forn(i,g){
		char c=elGrandote[i];
		if (pg[c-'A']==1){
			cntz++;
			cnt1--;
		}else if(pg[c-'A']==0){
			cntz--;
			cnt1++;
		}
		pg[c-'A']--;
	}
	
	tint tot=0;
	
	for (int i=0; i+g<=n;i++){
		//bool flag=true;
		//int j=0;
		/*while (j<60 && flag){
			
			flag=ps[j]==pg[j];
			j++;
		}*/
		//if (flag) tot++;
		//cout<<cntz<<endl;
		if (cntz==60) tot++;
		if (pg[elGrandote[i]-'A']==-1){
			cntz++;
			cnt1--;
		}
		if (pg[elGrandote[i]-'A']==0){
			cntz--;
			cnt1++;
		}
		
		pg[elGrandote[i]-'A']++;
		if (pg[elGrandote[i+g]-'A']==0){
			cntz--;
			cnt1++;
		}
		if (pg[elGrandote[i+g]-'A']==1){
			cntz++;
			cnt1--;
		}
		if (i+g<n) pg[elGrandote[i+g]-'A']--;
		//if (ps==pg) tot++;
		//if (i+g<n) ps=ps*primo[ss[i+g]];
		//ps=ps/primo[ss[i]];
	}
	cout<<tot<<endl;
	
	return 0;
}
