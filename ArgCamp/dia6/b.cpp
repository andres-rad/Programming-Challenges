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

punto operator* (const int b, const punto & a ){
	punto temp;
	temp.x=a.x*b;
	temp.y=a.y*b;
	return temp;
}


int main(){
	int casos;
	cin >> casos;
	int caso = 0;
	while(caso < casos){
		caso++;
		
		double x,y,z;
		
		punto a,b,c,rq,rp;
		
		cin>>x>>y>>z;
		
		c.x=(x*x+y*y-z*z)/(2*x);
		c.y=sqrt(y*y-c.x*c.x);
		
		a.x=0;
		a.y=0;
		b.x=x;
		b.y=0;
		
		rq=(c-b)+2*(c-a);
		
		rp=(c-a)+2*(b-a);
		
		double res=	abs((rq^rp)/2);

		
		printf("%.1f\n", res);
		
	}
	return 0;
}
