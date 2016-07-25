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

typedef  long long int tint;

using namespace std;
int MP = (int) (700000);
int CANT = 800000;
__int128 primo[800000];

void criba()
{
	int maxsqrt = (int)(sqrt(double(MP)));
	maxsqrt++;
	bool *esPrimo = new bool[MP+1];
	memset(esPrimo, true, sizeof(bool)*(MP+1));
	int cont = 1; __int128 k,m;
	primo[0] = 2;
	for(m = 3;m <= maxsqrt; m+=2){
		if(esPrimo[m]){
			primo[cont] = m;
			//cout<<maxsqrt-m<<endl;
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

bool esPrimo(__int128 n){
	int i = 0;
	while((primo[i]*primo[i])<n+3){
		if(n % primo[i] == 0) {
			//cout << n << "   " << primo[i] << endl;
			return false;
		}
		i++;
	}
	return true;
}  

int main(){
	criba();
	//cout << primo[0];
	int test=0,t;
	cin>>t;
	while (t>test){
		test++;
		__int128 n;
		
		cin>>n;	
		
		while (!esPrimo(n)){
			n++;
		}
		cout << n << endl;
	}	
	
	return 0;
}
