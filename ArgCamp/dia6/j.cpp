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

typedef long long int tint;


int MP = (int) (1e4);

int CANT = 1229;

using namespace std;

int primo[1229];

void criba(bool esPrimo[])
{
	int maxsqrt = (int)(sqrt(double(MP)));
	maxsqrt++;
	
	memset(esPrimo, true, sizeof(bool)*(MP+1));
	int cont = 1; int k,m;
	primo[0] = 2;
	for(m = 3;m <= maxsqrt; m+=2){
		if(esPrimo[m]){
			primo[cont] = m;
			cont++;
			for(k = m*m; k <= MP; k += m) esPrimo[k] = false;
		}
	}
	if(maxsqrt % 2 == 0) maxsqrt++;
	for(int j = maxsqrt+2; j <= MP; j += 2){
		if(esPrimo[j]){
			primo[cont] = j;
			cont++;
		}
	}
	//cout << cont << endl;
}


int main(){
	bool *esPrimo = new bool[MP+1];
	criba(esPrimo);
	
	for(int k = 4; k <= 3500; k += 2) esPrimo[k] = false;
	int n;
	cin>>n;
	
	int cant=0;
	
	vector<int> res (n+10,0);
	int last=2;
	for (int i=2; i<=n;i++){
		last=i;
		if (!esPrimo[i]){
			bool flag=true;
			int j=0;
			while (flag){
				if (last%primo[j]==0){
					while (last%primo[j]==0){
						last/=primo[j];
					}
					flag=false;
				}
				j++;
			}
			
			if (last==1){
				res[i]=1;
			}else{
				res[i]=1+res[last];
				if (res[i]==2){
					cant++;
				}
					
			}
					
		}else{
			res[i]=1;
		}
		
		
	}
	cout<<cant<<endl;
	
	
	return 0;
}
