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




			
int main(){
	int xx,yy;
	
	cin>>xx>>yy;
	int p,f;
	
	cin>>p>>f;
	
	
	vector<vector<int> > campo (xx ,vector<int> (yy, 0));
	/*
	forn (i,xx+1){
		campo[i][0]=2;
	}
	forn (i,yy+1){
		campo[0][i]=2;
	}
	*/
	
	forn (i,p){
		int introx, introy;
		cin>>introx>>introy;
		campo[introx-1][introy-1]=2;
	}
	
	vector<pair<int,int> > frutas;
	forn (i,f){
		int introx, introy;
		cin>>introx>>introy;
		frutas.pb(mp(introx-1,introy-1));
		campo[introx-1][introy-1]=1;
	}
	
	vector<vector< pair<int,int> > > add (xx+1 ,vector<pair<int,int> > (yy+1, mp(0,0)));
	
	forn (i,xx+1){
		add[i][0]=mp(0,1);
	}
	forn (i,yy+1){
		add[0][i]=mp(0,1);
	}
	
	forn (i,xx){
		forn(j,yy){
			add[i+1][j+1].first=add[i+1][j].first+add[i][j+1].first-add[i][j].first;
			add[i+1][j+1].second=add[i+1][j].second+add[i][j+1].second-add[i][j].second;
			
			if (campo[i][j]==2){
				add[i+1][j+1].second++;
			}else if (campo[i][j]==1){
				add[i+1][j+1].first++;
			}
		}
	}
	
	int cntf=0;
	
	forn(i,p){
		pair<int,int> pos = frutas[cntf];
		cntf++;
		
		pair<int,int> lo=pos;
		pair<int,int> hi=mp(min(xx-pos.x,yy-pos.y),min(xx-pos.x,yy-pos.y));
		
		int lo=0;
		int hi=min(xx-pos.x,yy-pos.y);
		
		int pinos=add[pos.x][pos.y].y;
		
		while (lo+1<hi){
			int me=(lo+hi)/2;
			
			if (add[pos.x+me][pos.y+me].y - pinos==0){
				lo=me;
			}else{
				hi=me;
			}
			
		
		
		
		
			
			
	
	return 0;
}
