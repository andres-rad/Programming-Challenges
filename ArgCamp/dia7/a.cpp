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
#define mp make_pair

using namespace std;

typedef long long int tint;

struct punto{
	double x,y;
};

punto operator+ (const punto & a, const punto &b){
	punto temp;
	temp.x=a.x+b.x;
	temp.y=a.y+b.y;
	return temp;
}

punto operator- (const punto & a, const punto &b){
	punto temp;
	temp.x=a.x-b.x;
	temp.y=a.y-b.y;
	return temp;
}

double operator^ (const punto & a, const punto &b){
	double temp=a.x*b.y-a.y*b.x;
	return temp;
}

punto operator* (const punto & a, const int b){
	punto temp;
	temp.x=a.x*b;
	temp.y=a.y*b;
	return temp;
}

bool operator< (const punto & a, const punto & b){
	return a.y<=b.y;
}

punto operator* (const int b, const punto & a ){
	punto temp;
	temp.x=a.x*b;
	temp.y=a.y*b;
	return temp;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int casos;
	cin>>casos;
	while (casos>0){
		casos--;
		int n;
		cin>>n;
		
		vector<punto> soldados;
		
		forn (i,n){
			double a,b;
			cin>>a>>b;
			punto temp;
			temp.x=a;
			temp.y=b;
			soldados.pb(temp);
		}
		
		sort(soldados.begin(), soldados.end());
		
		int m;
		cin>>m;
		
		forn (i,m){
			
			int a,r;
			
			cin>>a>>r;
			
			int  last;
			
			int lo=0, hi=n-1;
			
			
		
			
			if (soldados[n-1].x<=r){
				last=n-1;
			}else{
				lo=0;
				hi=n-1;
			
				while (hi>lo+1){
					int med = (hi+lo)/2;

					if(soldados[med].y>r){
						hi=med;
					}else{
						lo=med;
					}
				}
				
				last=lo;
			}
			
			punto A,B,C;
			A.x=a-r;
			A.y=0;
			
			B.x=a+r;
			B.y=0;
			
			C.x=a;
			C.y=r;
			
			punto ac, bc;
			ac=C-A;
			bc=C-B;
			
			int res=0;
			
			for (int i=0;i<=last; i++){
				if ((ac^(soldados[i]-A))<=0.0 && (bc^(soldados[i]-B))>=0.0) res++;
			}
			
			cout<<res<<'\n';
			
		}
		

			

			
	}
	
			return 0;
}
