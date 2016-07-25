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
	
	bool nulo(){
		return x==0.0 && y==0.0;
	}
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

punto operator* (const punto & a, const double b){
	punto temp;
	temp.x=a.x*b;
	temp.y=a.y*b;
	return temp;
}

punto operator* (const double b, const punto & a ){
	punto temp;
	temp.x=a.x*b;
	temp.y=a.y*b;
	return temp;
}




int main(){
	
	punto a,b,c,d,e,f;
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y>>e.x>>e.y>>f.x>>f.y;
	while(!(a.nulo() && b.nulo() && c.nulo() && d.nulo() && e.nulo() && f.nulo()   )){
		
		double k =abs(((f-d)^(e-d))/2);
		
		double p=((b-a).y*(c.x-a.x) - (b-a).x*(c.y-a.y));
		
		double t= k/abs(p);
		//cout<<t<<endl;
		
		punto h= a+(t*(c-a));

		punto g=(h-a)+(b-a)+a;
		
		printf("%.3f %.3f %.3f %.3f\n", g.x, g.y, h.x, h.y);	
		cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y>>e.x>>e.y>>f.x>>f.y;

		
	}
	return 0;
}
