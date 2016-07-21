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

vector<int> estado (4,0);

vector <int> dist(vector<int> est , int i){
	if (i==0){
		est[1]-=1;
		est[3]-=2;
		est[0]-=2;
	}else if(i==1){
		forn (j,4) {
			est[j]--;
		}
	}else if (i==2){
		est[0]--;
		est[3]--;
	}else if (i==3){
		est[2]--;
		est[3]--;
	}else{
		est[1]-=3;
	}
	return est;
}
//vector<vector<vector<vector<int> > > > mem (8,vector<vector<vector<int> > > (8,vector<vector<int> > (8, vector<int> (8, -1))));

bool dfs(vector<int> estado, int cnt,vector<vector<vector<vector<int> > > > & memo ){
	
	forn (i,4){
		if (estado[i]<0) {
			return cnt%2==0?true:false;
		}
	}
	if (memo[estado[0]][estado[1]][estado[2]][estado[3]]!=-1) {
		return memo[estado[0]][estado[1]][estado[2]][estado[3]]==1?true:false;
	}
	
	bool ganop[5];
	forn (i,5){
		//cout<<cnt<<":  "<<dist(estado,i)[0]<<"  "<<dist(estado,i)[1]<<"  "<<dist(estado,i)[2]<<"  "<<dist(estado,i)[3]<<endl;
		ganop[i]=dfs(dist(estado,i), cnt+1,memo);
		
		
		//ganop[i]=!ganop[i];
		
		//cout<<cnt<<":  "<<(ganop[i]?"Patrick":"Roland")<<endl;
		//ganop[i]=cnt%2==0?ganop[i]:!ganop[i];
	}
	
	bool ganoPP;
	
	
	if (cnt%2==0){
		ganoPP=ganop[1]||ganop[2]||ganop[3]||ganop[4]||ganop[0];
	}else{
		ganoPP=ganop[1]&&ganop[2]&&ganop[3]&&ganop[4]&&ganop[0];
	}
	memo[estado[0]][estado[1]][estado[2]][estado[3]]=ganoPP?1:0;
	
	return ganoPP; 
}

int main(){
	
	int casos;
	int caso=0;
	cin>>casos;
	
	while (caso<casos){
		caso++;
		vector<vector<vector<vector<int> > > > mem (9,vector<vector<vector<int> > > (9,vector<vector<int> > (9, vector<int> (9, -1))));
		vector <int> est;
		
		forn (i,4){
			int c;
			cin>>c;
			est.pb(c);
		}
		cout<<(dfs(est,0, mem)?"Patrick":"Roland")<<endl;
		
	}
	return 0;
}
