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

int n;
	
struct node{
	int vengo;
	pair<int,int> pos;
};	

int distancia(int vengo, int voy, char sentido){
	if (sentido=='H'){
		return (4+voy-vengo)%4;
	}else{
		return (4+vengo-voy)%4;
	}
}

bool enRango (pair<int,int> pos){
	return (pos.x>=0 && pos.x<n && pos.y>=0 && pos.y<n) || (pos.x==n && pos.y==n-1);
}

class menor{
	public:
		bool operator()(const pair<int,node> &a, const pair<int,node> &b){
			return a.x >= b.x;
		}
};

/*
	0
3		1
	2
*/


int main(){
	cin>>n;
	
	vector<vector<char> > sent (n, vector<char> (n));
	
	forn(i,n){
		forn(j,n){
			char app;
			cin>>app;
			sent[j][i]=app;
		}
	}
	priority_queue< pair<int, node>, vector<pair<int,node> >, menor> cola;
	vector<vector<int> > visto(n+1,vector<int>(n,false));
	
	node cur;
	cur.pos=mp(0,0);
	cur.vengo=3;

	cola.push(mp(0,cur));
	int dist;

	while (!cola.empty() && cur.pos!=mp(n,n-1)){
		cur=cola.top().y;
		dist=cola.top().x;
		cola.pop();

		if (!visto[cur.pos.x][cur.pos.y]){
			visto[cur.pos.x][cur.pos.y]=true;

			if (enRango(mp(cur.pos.x+1, cur.pos.y)) && !visto[cur.pos.x+1][ cur.pos.y]){
				node temp;
				temp.pos=mp(cur.pos.x+1, cur.pos.y);
				temp.vengo=3;
				int distemp=dist+distancia(cur.vengo, 1, sent[cur.pos.x][cur.pos.y]);
				cola.push(mp(distemp, temp));
			}
			if (enRango(mp(cur.pos.x-1, cur.pos.y)) && !visto[cur.pos.x-1][ cur.pos.y]){
				node temp;
				temp.pos=mp(cur.pos.x-1, cur.pos.y);
				temp.vengo=1;
				int distemp=dist+distancia(cur.vengo, 3, sent[cur.pos.x][cur.pos.y]);
				cola.push(mp(distemp, temp));
			}
			if (enRango(mp(cur.pos.x, cur.pos.y+1)) && !visto[cur.pos.x][ cur.pos.y+1]){
				node temp;
				temp.pos=mp(cur.pos.x, cur.pos.y+1);
				temp.vengo=0;
				int distemp=dist+distancia(cur.vengo, 2, sent[cur.pos.x][cur.pos.y]);
				cola.push(mp(distemp, temp));
			}
			if (enRango(mp(cur.pos.x, cur.pos.y-1)) && !visto[cur.pos.x][ cur.pos.y-1]){
				node temp;
				temp.pos=mp(cur.pos.x, cur.pos.y-1);
				temp.vengo=2;
				int distemp=dist+distancia(cur.vengo, 0, sent[cur.pos.x][cur.pos.y]);
				cola.push(mp(distemp, temp));
			}
		}
	}

	cout<<dist<<endl;
	
	return 0;
}
