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

int CANT = 79000;

using namespace std;

int primo[79000];
int cnt [1000004]={0};
int sum [1000004]={0};
int esPrimo[1000004];
vector<vector<int > > nivels(1000004, vector<int>(14));
//int maxn=0;

void criba()
{
	int maxsqrt = (int)(sqrt(double(MP)));
	maxsqrt++;
	//bool *esPrimo = new bool[MP+1];
	//memset(esPrimo, true, sizeof(bool)*(MP+1));
	int cont = 1; int k,m;
	primo[0] = 2;
	for(m = 3;m <= maxsqrt; m+=2){
		if(!esPrimo[m]){
			primo[cont] = m;
			
			cont++;
			for(k = m*m; k <= MP; k += m) esPrimo[k] = m;
		}
	}
	if(maxsqrt % 2 == 0) maxsqrt++;
	for(int j = maxsqrt+2; j <= MP; j += 2){
		if(!esPrimo[j]){
			primo[cont] = j;
			cont++;
		}
	}
	//cout << cont << endl;
}



int nivel (int m){
	int n=m;
	//cout<<m<<endl;
	if (n==1||cnt[n]!=0) return cnt[n];
	if (m%2==0&&m!=2) esPrimo[m]=2;

	int tot=0;
	


	
	//cout<<m<<endl;

	int i=0;
	/*while (primo[i]<=n&&sum[n]==0){
		//cout<<"p "<<primo[i]<<endl;
		if (n % primo[i] == 0){
			tot += primo[i];
			while (n%primo[i]==0){
				n /= primo[i];
			}

			
		}
		
		
		i++;
	}*/
	tot+=esPrimo[m];
	//cout<<m<<"  "<<esPrimo[m]<<endl;
	while (n%esPrimo[m]==0){
				n /= esPrimo[m];
	}
	tot+=sum[n];
	//if(m == n);
	sum[m]=tot;
	
	

	cnt[m]=cnt[tot]+1;
	//maxn=max(maxn, cnt[m]);
	/*for(int i=m;i<=1000000;i++){
		nivels[cnt[m]][i]++;
	}*/


	return cnt[m];
}

int main(){
	int n;
	criba();
	sum[1]=0;

	forn (i, CANT ){
		cnt[primo[i]]=1;
		sum[primo[i]]=primo[i];
	}


	cin >> n;
	for (int i=2;i<1000001;i++){
		nivel(i);

	}

	for (int i=2; i<1000001;i++){
		for (int j =1; j<14;j++){
			int suma;
			if (cnt[i]==j) suma=1;
			else suma=0;
			nivels[i][j]=nivels[i-1][j]+suma;
		}
	}

	forn(i,n) {
		int A,B, k;

		cin >> A >> B >> k;

		if (k>=14){
			cout<<"0"<<endl;
		}else{
			cout<<nivels[B][k]-nivels[A-1][k]<<endl;
		}
		
	}
	return 0;
}