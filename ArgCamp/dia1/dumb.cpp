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

bool mayor(int a, int b){
	return a>b;
}

bool mayorV (const vector<int> & a,const vector<int> & b){
	bool res=false;
	if (a.size()==b.size()&&a.size()>0){
		//cout<<"MAY "<<a[0]<<"  "<<b[0]<<endl;
		res=a[0]>b[0];
	}else{
		res=a.size()>b.size();
	}
	return res; 
}
bool mayorP (const vector<int> & a,const vector<int> & b){
	bool res=false;
		//cout<<"MAY "<<a[0]<<"  "<<b[0]<<endl;
		res=a[0]>b[0];
	return res; 
}


int main(){
	int k,n;
	
	cin>>n>>k;
	
	vector<vector<int> > v (4010, vector<int> (1,0));
	forn(i,n){
		int m,c;
		cin>>m>>c;
		
		v[m].pb(c);
	}
	forn (i,4008){
		sort(v[i].begin()+1, v[i].end(), mayor);
	}
	
	sort(v.begin(),v.end(), mayorV);
	
	int t=v[k-1].size()-1;
	
	
	if (t==0){
		cout << "0 0"<<endl;
		return 0;
	}
	
	
	
	
	int max=0;
	forn(i,4008){
		forn(j,t){
			if (v[i].size()>=t+1){
				v[i][0]+=v[i][j+1];
				max=i;
			}
		}
		//cout<<i<<"V  "<< v[i][0]<<endl;
	}
	//cout<<max<<endl;
	sort(v.begin(),v.begin()+max+1, mayorP);
	
	int s=0;
	
	forn (i, k){
		s+=v[i][0];
		//cout<<v[i][0];
	}
	
	cout<<t<<" "<<s<<endl;
	
	return 0;
}
