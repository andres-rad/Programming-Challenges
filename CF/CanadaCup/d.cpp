#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define dprint(v) cout<<#v"="<<v<<endl;

typedef long long tint;



int main(){
	
	int n;
	cin>>n;
	
	tint globos, peso;
	cin>>globos>>peso;
	
	priority_queue<pair<tint, tint>, vector<pair<tint, tint> >, less<pair<tint, tint> > > eqs;
	priority_queue<tint, vector<tint>, greater<tint> > eqmej;
	
	
	forn(i, n-1){
		tint a, b;
		cin>>a>>b;
		if (a>globos){
			eqmej.push(b-a+1);
			//dprint(b-a+1);
			//cout<<"aca"<<endl;
		}else{
			eqs.push(mp(a,b));
		}
	}
	
	tint pos=eqmej.size();
	
	//dprint(globos); dprint(eqmej.top());

	while((!eqmej.empty()) && globos>=eqmej.top()){
		tint prox=eqmej.top();
		eqmej.pop();
		
		globos-=prox;
		//cout<<prox<<endl;
		
		while(!eqs.empty() && eqs.top().fst>globos){
			//cout<<"pongo "<< eqs.top().fst<<" "<<eqs.top().snd<<endl;
			tint aponer=eqs.top().snd-eqs.top().fst+1;
			eqs.pop();
			eqmej.push(aponer);
		}
		pos=min(pos, tint(eqmej.size()));
	}
	
	cout<<pos+1<<endl;
	
	
	
	
	return 0;
} 
