#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back

int m,n,x0,y12,x,y,dir;
long mod;
char pl[1010][1010];
pair<int,long> vis[1010][1010][4];
queue <tuple<int,int, int>> q;
int dx[4] = {-1,0,1,0};
int dy[4] = { 0,1,0,-1};
bool flag =false;

bool valid (int a, int b){
	return (a>=0 && a<m && b>=0 && b<n && pl[a][b]=='.');
}

void agr (int dd, int ee, int ff, int d,int e,int f){

if (valid (dd,ee)) {
			
			if (!vis[dd][ee][ff].first) {
				if (dd==x && ee==y) flag=true;
				if (!flag) q.push (make_tuple(dd,ee,ff));

				vis[dd][ee][ff].first=vis[d][e][f].first+1;
			}
						
			if (vis[dd][ee][ff].first==vis[d][e][f].first+1){
				vis[dd][ee][ff].second+=vis[d][e][f].second;
				vis[dd][ee][ff].second%=mod;
					
}		
		}

}

void bfs (int a, int b,int c){
	q.push(make_tuple(a,b,c));
	while (!q.empty()){
		tuple<int,int, int> w=q.front();
		q.pop();
		int d=get<0>(w);
		int e=get<1>(w);
		int f=get<2>(w);
		int dd=d+dx[f], ee=e+dy[f], ff1=(f+1)%4, ff2=(f+3)%4;
		agr (dd,ee,f,d,e,f);
		agr (d,e,ff1,d,e,f);
		agr (d,e,ff2,d,e,f);
		
	
	}

}

int main () {

	char bas;
	int cas=1;
	m=1;
	n=0;
	//cin>>m>>n>>mod;	
	while (cin>>m>>n>>mod and m){
	forn (i,m){
		forn (k,n){
			forn (j,4){
				vis[i][k][j]=make_pair (0,0);
}
}
}
	flag=false;
	
//scanf ("%d %d %ld \n", &m, &n, &mod);
	//if (m==0) return 0;


	forn (i,m){
		forn (j,n){
			cin>>pl[i][j];			
//scanf ("%c", &pl[i][j]);
		}

	//scanf("%c",&bas);
	}
 	char d;
	cin >>x0>>y12>>x>>y>>d;
	//scanf ("%d %d %d %d %c \n", &x0, &y12, &x, &y, &d);
	switch (d) {

		case 'N': 
			dir =0;
			break;
		case 'E':
			dir =1;
			break;
		case 'S': 
			dir =2;
			break;
		default:
			dir =3;
			break;
	}
	vis[x0][y12][dir].second=1;
	
	bfs (x0,y12,dir);

	int res=0;
	forn (i,4){
		res+=vis[x][y][i].second;
		res %=mod;
	}
	
	cout<<"Case "<< cas<<": "<<mod<<" "<<(res ? res:-1) <<endl;
	cas++;

	//cin>>m>>n>>mod;	
}


	return 0;
}
