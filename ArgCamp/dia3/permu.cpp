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

vector<int> facts(1000010);
int mod;

void factt(){
	facts[0]=1;
	for (int i=1; i<=1000000;i++){
		facts[i]=i*facts[i-1]%mod;
	}
	return;
}

int p(int n, int i){
	return facts[n];
}
			
int main(){
	mod=1000003;
	factt();
	int last=1;
	vector<int> res (1000000);
	res[0]=0;
	res[1]=1;
	
	int t;
	
	cin>>t;
	
	forn (i,t){
		int q;
		cin>>q;
		
		for (int j=last+1; j<=q;j++){
			last=j;
			res[j]=((res[j-1]*q/(q-1))%mod+(facts[q])%mod)%mod;
		}
		cout<<res[q]<<endl;
	}
	return 0;
}
