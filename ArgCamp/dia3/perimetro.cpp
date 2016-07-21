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

int n;
int huecos;
vector<vector<char> > campo(100, vector<char>(100, 'H'));
vector<pair<int,int> > paja;

bool hueco(vector<vector<char> > &campo, int i, int j){
	return  ((i>0 && campo[i-1][j] == 'B') && (j>0 && campo[i][j-1] == 'B') && 
			(i<99 && campo[i+1][j] == 'B') && (j<99 && campo[i][j+1] == 'B'));
}
int perim(vector<vector<char> > &campo, int i, int j, int &h){
	int tot = 0;
	if(i==0){
		tot++;
	}else if(campo[i-1][j] == 'H'){
		tot++;
		//if(!hueco(campo, i-1, j))tot++;
	}
	
	if(j==0){
		tot++;
	} else if(campo[i][j-1] == 'H'){
		tot++;
		//if(!hueco(campo, i, j-1))tot++;
	}
	
	if(i==99){
		tot++;
	} else if(campo[i+1][j] == 'H'){
		tot++;
		//if(!hueco(campo, i+1, j))tot++;
	}
	
	if(j==99){
		tot++;
	} else if(campo[i][j+1] == 'H'){
		tot++;
		//cout<<i<<" "<<j<<(hueco(campo, i, j+1)?1:0)<<endl;
		if(hueco(campo, i, j+1)) {
			//cout<<"fjd";
			h=h+1;
		}
	}
	
	return tot;
}

int main(){
	cin >> n;
	int huecos=0;
	int h=0;
	forn(i,n){
			int k, l;
			cin >> k >> l;
			paja.pb(mp(k-1,l-1));
			campo[k-1][l-1] = 'B'; 
	}
	int res = 0;
	forn(i,n){
		res+= perim(campo, paja[i].x, paja[i].y, h);
		//cout <<h<<"  "<< paja[i].x << " " << paja[i].y << "     " << perim(campo, paja[i].x, paja[i].y,h) <<  endl;
	}
	
	cout << res-4*h << endl;
	return 0;
}
