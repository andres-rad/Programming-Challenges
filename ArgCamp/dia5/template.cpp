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


int MP = (int) (1e9);

int CANT = 50847534;

using namespace std;

set<int> primo[50847534];

void criba()
{
	int maxsqrt = (int)(sqrt(double(MP)));
	maxsqrt++;
	bool *esPrimo = new bool[MP+1];
	memset(esPrimo, true, sizeof(bool)*(MP+1));
	int cont = 1; int k,m;
	primo.insert(2);
	for(m = 3;m <= maxsqrt; m+=2){
		if(esPrimo[m]){
			primo.insert(m);
			cont++;
			for(k = m*m; k <= MP; k += m) esPrimo[k] = false;
		}
	}
	if(maxsqrt % 2 == 0) maxsqrt++;
	for(int j = maxsqrt+2; j <= MP; j += 2){
		if(esPrimo[j]){
			primo.insert(j);
			cont++;
		}
	}
	//cout << cont << endl;
}


int main(){
	
	int n;
	cin>>n;
	
	while (n!=0){
		
		
	
		
		set<int>::iterator it = primo.begin();
		it++;
		
		while (it!= primo.end() && *it<n){
			int a=*it;
			int b=n-a;
			
			if (primo.set(b)!=primo.end()){
				cout<<n<<" = "<<a<<" + "<<b<<'\n';
				it=primo.end();
			}
		}
		
			
		cin>>n;
		
	}
	
	
	return 0;
}
