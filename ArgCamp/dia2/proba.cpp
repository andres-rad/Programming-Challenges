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

double po(double d,int i){
	if (i<1) return 1.0;
	double res=1.0;
	while (i>0){
		res*=d;
		i--;
	}
	return res;
}


int main(){
	int n;
	double t;
	
	cin>>n;
	cin>>t;
	while (n!=0){
		double ma=1.0;
		int i=1;
		
		double ant=1.0;
		
		while(i<=n){
			double temp;
			if (t>=0.5){
				temp=po(2.0,i)*po((1.0+t)/2.0,i);
				//temp=ant*(1.0+t);
			}else{
				//temp=ant*(1.0+t)*(0.5/(1.0-t))+ant*(0.5-t)/(1.0-t);
				//temp=po(2.0,i-1)*po((1.0+t)/2.0,i-1)+(/*po(2.0,i)*/ 2.0*(0.5/(1.0-t))+po(2.0, i-1)*(0.5-t)/(1.0-t));
				//temp/=po(2.0, i);
				temp=po(2.0,i-1)*po((0.5/1.0-t)*(1.5)/2.0,i-1)*( 2.0*(0.5/(1.0-t))*(1.0+0.5)/2.0+0*(0.5-t)/(1.0-t));
				cout<<"T "<< temp<<endl;
			}
			
			ant=po(2.0,i)*po((0.5/(1.0-t))*(1.0+t)/2.0,i);;
			ma=max(ma,temp);
			
			
			i++;
		}
		cout<<ma<<endl;
		cin>>n;
		cin>>t;
	}	
	return 0;
}
