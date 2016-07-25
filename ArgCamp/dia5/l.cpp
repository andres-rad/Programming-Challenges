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


int MP = (int) (1e6);

int CANT = 78498;

using namespace std;

int primo[78498];

void criba(bool esPrimo[])
{
	int maxsqrt = (int)(sqrt(double(MP)));
	maxsqrt++;
	
	memset(esPrimo, true, sizeof(bool)*(MP+1));
	int cont = 1; int k,m;
	primo[0] =2;
	for(m = 3;m <= maxsqrt; m+=2){
		if(esPrimo[m]){
			primo[cont]=m;
			cont++;
			for(k = m*m; k <= MP; k += m) esPrimo[k] = false;
		}
	}
	/*
	if(maxsqrt % 2 == 0) maxsqrt++;
	for(int j = maxsqrt+2; j <= MP; j += 2){
		if(esPrimo[j]){
			primo[cont]=j;
			cont++;
		}
	}
	*/
	//cout << cont << endl;
}


int main(){
	
	int n;
	cin>>n;
	
	bool *esPrimo = new bool[MP+1];
	
	criba(esPrimo);
	
	//vector<pair<int, int> > res (1000010, mp(0,0));
	/*
	forsn (i,1, 78498){
		for (int j=i; primo[i]+primo[j]<1000005 && j<78498; j++){
			res[primo[i]+primo[j]]=mp(primo[i], primo[j]);
			cout<<i<<"  "<<j<<endl;
		}
	}
	*/
	
	
	while (n!=0){
		
		bool ans=false;
		int i=1;
		int b;
		while (!ans){
			b= n-primo[i];
			if (esPrimo[b]){
				ans=true;
				i--;
			}
			i++;
		}
		
		
		
		cout<<n<<" = "<<primo[i]<<" + "<<b<<'\n';
		
			
			
		cin>>n;
		
	}
	
	
	return 0;
}
