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

//UNION FIND
vector<int> clases (101*1000);

void init (){
	forn (i,102){
		forn (j,102){
			clases[i*103+j]=-1;
		}
	}
	return;
}

int hashi (int i, int j){
	return i*103+j;
}
int cl(int j){
	if (clases[j]==-1) return j;
	else return clases[j]=cl(clases[j]);
}

void join (int i1, int j1, int i2, int j2){
	if (cl(hashi(i1,j1))!=cl(hashi(i2,j2))) clases[cl(hashi(i1,j1))]=cl(hashi(i2,j2));
	//				104					207
	return;
}
	


int claseext;

int n;
int huecos;
vector<vector<char> > campo(102, vector<char>(102, 'H'));
vector<pair<int,int> > paja;

bool hueco(vector<vector<char> > &campo, int i, int j){
	return cl(i*103+j)!=claseext;
	//return  ((i>0 && campo[i-1][j] == 'B') && (j>0 && campo[i][j-1] == 'B') && (i<99 && campo[i+1][j] == 'B') && (j<99 && campo[i][j+1] == 'B'));
}
int perim(vector<vector<char> > &campo, int i, int j, int &h){
	int tot = 0;
	if(i==1){
		tot++;
	}else if(campo[i-1][j] == 'H'){
		//tot++;
		if(!hueco(campo, i-1, j))tot++;
			
	}
	
	if(j==1){
		tot++;
	} else if(campo[i][j-1] == 'H'){
		//tot++;
		if(!hueco(campo, i, j-1))tot++;
	}
	
	if(i==100){
		tot++;
	} else if(campo[i+1][j] == 'H'){
		//tot++;
		if(!hueco(campo, i+1, j))tot++;
	}
	
	if(j==100){
		tot++;
	} else if(campo[i][j+1] == 'H'){
		//tot++;
		if(!hueco(campo, i, j+1))tot++;
		//cout<<i<<" "<<j<<(hueco(campo, i, j+1)?1:0)<<endl;
		/*
		if(hueco(campo, i, j+1)) {
			//cout<<"fjd";
			h=h+1;
		}
		*/
	}
	
	return tot;
}

int main(){
	cin >> n;
	int huecos=0;
	int h=0;
	init();
	
	forn(i,n){
			int k, l;
			cin >> k >> l;
			paja.pb(mp(k,l));
			campo[k][l] = 'B'; 
	}
	forn (i,102){
		forn (j,101){
			//cout<<i<<" "<<j<<endl;
			if (campo[i][j]!='B'){
				if (i<101){
					
					if (campo[i+1][j]=='H') join(i,j,i+1,j);
				}
				//cout<< "OK"<<endl;
				if (campo[i][j+1]=='H') join(i,j,i,j+1);
			}
		}
	}

	claseext=cl(hashi(0,0));
	//cout<<claseext<<endl;		
			
	int res = 0;
	forn(i,n){
		res+= perim(campo, paja[i].x, paja[i].y, h);
		//cout <<"  "<< paja[i].x << " " << paja[i].y << "     " << res<<  endl;
	}
	
	cout << res << endl;
	return 0;
}
