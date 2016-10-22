#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef long long tint;

vector<int> posibles;
vector<int> monedas;
int c, n;

void puedo(int desde){
	if (desde<n){
		puedo(desde+1);
	}else{
		posibles[monedas[desde]]=1;
	}
	
	int actual=monedas[desde];
	forn (i,c+1){
		if (posibles[i] && i+actual <= c){
			posibles[i+actual]=1;
		}
	}
	
	
}
	

int main(){
	
	cin>>c;

	cin>>n;
	
	forn(i,n){
		int t;
		cin>>t;
		monedas.pb(t);
	}
	
	posibles= vector<int>(c+1, 0);
	posibles[0]=1;
	
	puedo(0);
	
	
	
	sort(monedas.begin(), monedas.end(), greater<int>());
	
	int maxNP=-1;
	
	forn (i,c+1){
		if (!posibles[i]) maxNP=i;
	}
	
	
	if (maxNP==-1){
		cout<<"Greed is good"<<endl;
		return 0;
	}
	
	int res=c-maxNP;
	
	int i=0;
	int suma=0;
	
	forn (i,n){
		if (suma+monedas[i]<=c){
			suma+=monedas[i];
		}
	}
	
	if (suma!=c){
		cout<<0<<endl;return 0;
	}
	
	res=c;
	
	
	while (i<n-1 && (res-monedas[i]>monedas[i+1])){
		
		res-=monedas[i];
		i++;
		
	}
	
	int j=0;
	int superres=res;
	
	while (j<c+1){
		if (!posibles[j] && res-j>monedas[i]){
			superres=res-j;
		}
		
		j++;
	}
	
	cout<<superres<<endl;

	
	
	
	
	return 0;
} 
