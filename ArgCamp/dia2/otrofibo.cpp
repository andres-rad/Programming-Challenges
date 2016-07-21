#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <numeric>
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

vector<int> fibo (100,1);



#define MAXN 100000
struct rmq {
	int MAX;
	int vec[4*MAXN];
	int* init(int n){
		MAX=1<< (32-__builtin_clz(n));
		fill(vec, vec+2*MAX, 0);
		return vec+MAX;
	}
	void updall() { for (int i=MAX-1;i>=0;i--) vec[i]=vec[2*i+2]+vec[2*i+1];}
	void pset(int i, int v){
		vec[i+=MAX] =v;
		while (i){i/=2; vec[i]=vec[2*i+2]+vec[2*i+1];}
	}
	int pget (int i, int j) { return _pget(i+MAX, j+MAX);}
	int _pget(int i, int j){
		int res=0;
		if (j-i<=0) return res;
		if (i%2) res += vec[i++];
		res+= _pget(i/2, j/2);
		if (j%2) res+=vec[--j];
		return res;
	}
};
	
void fibonacci(){
	for (int i =2;i<100;i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
	return;
}

bool eshijo(int c){
	bool f=false;
	forn(i,100){
		int temp=c-fibo[i];
		
		forn (j,100){
			if (fibo[j]==temp) return true;
		}
	}
	return f;
}

int main(){
	fibonacci();
	int n,q;
	cin>>n>>q;
	
	rmq seg;
	int* primero;
	primero = seg.init(n);
	
	forn (i,n){
		tint t;
		cin>>t;
		
		bool f=eshijo(t);
		if (f){
			seg.vec[primero+i]=1;
		}else {
			seg.vec[primero+i]=0;
		}
	}
	
	seg.updall();
	
	forn (i,q){
		int caso;
		cin>>caso;
		if (caso==1){
			int tot=0;
			int h,j;
			cin>>h>>j;
			cout<<seg.pget(h-1,j)<< endl;
		}else if (caso==2){
			int h,cam;
			cin>>h>>cam;
			if (eshijo(cam)){
				seg.pset(h-1,1);
			}else{
				seg.pset(h-1,0);
			}
			seg.updall();
			forn (i,primero+2*n){
				//cout<<seg.vec[i]<<"  ";
			}
			//cout<<endl;
		}
	}
