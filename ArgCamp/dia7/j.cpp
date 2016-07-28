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

int tipos(int num){
	int res=0;
	if (num%2==0) res++;
	if (num%3==0) res++;
	if (num%5==0) res++;

	return res;
}

int main(){
	int n;
	
	cin>>n;
	int comida[n];
	
	forn (i,n){
		char a;
		cin>>a;
		int b;
		if (a=='B') b=2;
		else if (a=='M') b=3;
		else if (a=='F') b=5;
		comida[i]=b;
	}
	
	int lasty=1, lastx=1, lastyy=1, lastxx=1;
	
	int res=0;
	int cnty=0, cntx=0;
	forn (i,n){
		if (tipos(lasty*lastyy*comida[i])==tipos(lastx*lastxx*comida[i]) && cnty<cntx){
			res+=tipos(lasty*lastyy*comida[i]);
			cnty++;
			//cout<<comida[i]<<"  y "<<tipos(lasty*lastyy*comida[i])<<"  "<<tipos(lastx*lastxx*comida[i])<<endl;
			if (cnty>=2) {
				lastyy=lasty;
				
			}
			lasty=comida[i];
		}else if (tipos(lasty*lastyy*comida[i])>tipos(lastx*lastxx*comida[i])){
			res+=tipos(lasty*lastyy*comida[i]);
			cnty++;
			//cout<<comida[i]<<"  y "<<tipos(lasty*lastyy*comida[i])<<"  "<<tipos(lastx*lastxx*comida[i])<<endl;
			if (cnty>=2) {
				lastyy=lasty;
				
			}
			lasty=comida[i];
		}else{
			res+=tipos(lastx*lastxx*comida[i]);
			cntx++;
			//cout<<comida[i]<<"  x "<<tipos(lasty*lastyy*comida[i])<<"  "<<tipos(lastx*lastxx*comida[i])<<endl;
			if (cntx>=2) {
				lastxx=lastx;
				
			}
			lastx=comida[i];
		}
		
		
	}
	
	cout<<res<<endl;
	return 0;
}
