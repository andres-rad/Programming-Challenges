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

/* bsearch example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort, bsearch, NULL */

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

int MP = (int) (1e6);

int CANT = 78498;

using namespace std;

tint primo[78498];
tint primorial[1000010];
//int last[1000010];
tint u=10000000000;
int maxi;
int maxchico;

void criba()
{
	int maxsqrt = (int)(sqrt(double(MP)));
	maxsqrt++;
	bool *esPrimo = new bool[MP+1];
	memset(esPrimo, true, sizeof(bool)*(MP+1));
	int cont = 1; tint k,m;
	primo[0] = 2;
	int lastp=0;
	//last[2]=0;
	for(m = 3;m <= maxsqrt; m+=2){
		if(esPrimo[m]){
			lastp=cont;
			primo[cont] = m;
			cont++;
			for(k = m*m; k <= MP; k += m) esPrimo[k] = false;
		}
		//cout<<m<<endl;
		//last[m+1]=cont;
		//last[m]=cont;
	}
	int maxi=maxsqrt;
	if(maxsqrt % 2 == 0) {maxsqrt++;}
	//last[maxsqrt+1]=cont;
	for(int j = maxsqrt+2; j <= MP; j += 2){
		if(esPrimo[j]){
			lastp=cont;
			primo[cont] = j;
			cont++;
		}
		//cout<<j<<endl;
		//last[j+1]=cont;
		//last[j]=cont;
	}
	//cout << cont << endl;
}

void primorialcriba(){
	primorial[0]=2;
	int cntp=0;
	
	primorial[1]=1;
	primorial[2]=2;
	maxchico=0;
	for (int i=3;i<=1000005;i++){
		if (i==primo[cntp+1]) {
			cntp++;
			
		
			primorial[i]=(primorial[i-1]*primo[cntp]);
		}else{
			primorial[i]=primorial[i-1];
		}
				
		if (primorial[i]>=u){
			primorial[i]=primorial[i]%u;
			if (!maxchico){
				
				maxchico=i;
			}
		}
		
		
	}
	return;
		
	
}




int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	criba();
	
	primorialcriba();
	tint t,n;
	/*
	for (int i=999900; i<=1000000; i++){
		cout<<i<<"  "<<primorial[i]<<endl;
	}*/
	
	cin>>t;
	cout.fill('0');
	
	forn (h,t){
		
		cin>>n;
		
		if (n<maxchico){
			cout.width(1);
		}else{
			cout.width(10);
		}
		
		cout<<primorial[n]<<'\n';
	}
	
	
	
	
		
	return 0;
}
