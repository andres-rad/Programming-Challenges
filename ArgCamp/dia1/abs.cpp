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

typedef pair<int,int> par;
typedef long long int tint;

int MP = (int) (1e6);

int CANT = 78498;

using namespace std;

int primo[78498];

void criba()
{
	int maxsqrt = (int)(sqrt(double(MP)));
	maxsqrt++;
	bool *esPrimo = new bool[MP+1];
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
	int casos;
	int caso = 0;
	cin >> casos;
	while(caso < casos){
		caso++;
		tint n;
		cin>>n;
		
		criba();
		
		tint c=n;
		tint tot=0;
		
		
		vector<pair<int,int> > divs;
		
		forn (i,78498){
			if (n%primo[i]==0){
				//divs.pb(primo[i]);
				int cnt=0;
				//cout<<primo[i]<<endl;
				while (c%primo[i]==0){
					cnt++;
					
					c=c/primo[i];
					tot++;
				}
				
				divs.pb(mp(primo[i], cnt));
			}
			
		}
		
		if (tot==1&&c>1){
			cout<<"Molek"<<endl;
		}else if (tot==0||(tot==1&&c==1)){
			cout<<"Vasha"<<endl<<0<<endl;
		}else if(tot==2&&c==1){
			cout<<"Molek"<<endl;
		}else{
		
			cout<<"Vasha"<<endl;
			
			
		
		if (divs[0].y>1){
				//cout<<(divs[divs.size()-1].x*divs[divs.size()-1].x)<<endl;
				cout<<(divs[0].x*divs[0].x)<<endl;
			}else{
				//cout<<(divs[divs.size()-1].x*divs[divs.size()-2].x)<<endl;
				cout<<(divs[0].x*divs[1].x)<<endl;
			}
		}
		
		
	}
	return 0;
}
