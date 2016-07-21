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
/*
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
-------------------
*/

int n,m;
vector<vector<char> > estado (20, vector<char> (20));
vector<vector<vector<vector<int> > > > memo (20,vector<vector<vector<int> > >(20, vector<vector<int> >(20, vector<int> (20, -1))));


bool f(int i1, int j1, int i2, int j2, int turno){
	if (i1==i2 || j1==j2) return false;//(turno%2==0?true:false);
	
	if (memo[i1][j1][i2][j2] !=-1) {
		//cout <<"f"<<endl;
		if (memo[i1][j1][i2][j2]==0){
			return false;
		}else{
			return true;
		}
	}
	
	bool fll=false;
	for (int i=i1; i<= i2; i++){
		for (int j=j1; j<j2;j++){
			bool fl=true;
			
			
			
			if (estado[i][j] == '|'){
				if (i>0){
					memo[i1][j1][i-1][j2]=f(i1,j1, i-1,j2,turno+1);
					fl=fl&&!memo[i1][j1][i-1][j2];
				}
				if (i<n-1){
					memo[i+1][j1][i2][j2]=f(i+1,j1, i2,j2,turno+1);
					fl=fl&&!memo[i+1][j1][i2][j2];
				}
			}else if (estado[i][j] == '+'){
				if (i>0 && j>0){
					memo[i1][j1][i-1][j-1]=f(i1,j1, i-1,j2,turno+1);
					fl=fl&&!memo[i1][j1][i-1][j-1];
				}
				if (i<n-1 && j>0){
					memo[i+1][j1][i2][j-1]=f(i1,j1, i-1,j2,turno+1);
					fl=fl&&!memo[i+1][j1][i2][j-1];
				}
				if (j<m-1 && i>0){
					memo[i1][j+1][i-1][j2]=f(i1,j1, i-1,j2,turno+1);
					fl=fl&&!memo[i1][j+1][i-1][j2];
				}
				if (i<n-1 && j<m-1){
					memo[i+1][j+1][i2][j2]=f(i1,j1, i-1,j2,turno+1);
					fl=fl&&!memo[i+1][j+1][i2][j2];
				}
			}else if (estado[i][j] == '-'){
				if (j>0){
					
					memo[i1][j1][i2][j-1]=f(i1,j1, i-1,j2,turno+1);
					cout<<memo[i1][j1][i2][j-1]<<endl;
					fl=fl&&!memo[i1][j1][i2][j-1];
				}
				if (j<m-1){
					cout<<"dkjf"<<endl;
					memo[i1][j+1][i2][j2]=f(i1,j1, i-1,j2,turno+1);
					cout<<memo[i1][j+1][i2][j2]<<endl;
					fl=fl&&!memo[i1][j+1][i2][j2];
				}
			}
			
			
			fll=fll||fl;
			
		}
		
	}
	//if (turno%2!=0) fll=!fll;
	return fll;
}
			
int main(){
	cin>>n>>m;
	
	forn (i,n){
		forn (j,m){
			char t;
			cin>>t;
			estado[i][j]=t;
		}
	}
	cout<<(f(0,0,n-1,m-1,0)?"WIN":"LOSE")<<endl;
	return 0;
}
