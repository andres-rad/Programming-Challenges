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
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

int main(){
	int n,k;
	double  l, vp, vb;
	cin>>n>>l>>vp>>vb>>k;
	
	double v1=vp, v2=vb;
	double grupos=n/k;
	if (n%k!=0) grupos++;
	
	double tiempo=l*(grupos/(v2-v1)+(grupos-1)/(v2+v1))/(1+grupos*v1/(v2-v1) + (grupos-1)*v1/(v2+v1));
	 
	cout<<setprecision(12)<<tiempo<<endl;
	/*
	double res=0;
	
	while (n>0){
		double time= l/vb;
		l=l-time*vp;
		res+=time;
		cout<<time<<" "<<l<<endl;
		n-=k;
	
		
	}
	
	cout<<res<<endl;
	* */
		
	return 0;
}
