#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define debug(v) cerr << #v << " = " << (v) << endl;
#define pb push_back

#define MAXN 330
#define MOD 1000000007

vector<vector<int> > comb;


ll lucas (ll n, ll k, int p){ //Calcula (n,k) %p teniendo comb[p][p] precalculado.
	ll aux = 1;
	while (n + k) aux = (aux * comb[n %p][k %p]) %p, n/=p, k/=p;
	return aux;
}

int sab(int stars, int boxes){
	return comb[stars+boxes-1][boxes-1];
}

int main() {
	comb = vector<vector<int> > (MAXN, vector<int> (MAXN));
	forn(i, MAXN+1){//comb[i][k]=i tomados de a k
		comb[i][0]=comb[i][i]=1;
		forr(k, 1, i) comb[i][k]=(comb[i-1][k]+comb[i-1][k-1]) %MOD;
	}
	int s, b;
	while(cin>>s){
		cin>>b;

		int ans = 0;

		forn(i, b){
			// si la piedra que gana esta en la caja i
			for (int j = b - i -1; j>=0; j--){
				// si tengo que avanzar j veces
				int mini
			}
		}
	}
	return 0;
}
