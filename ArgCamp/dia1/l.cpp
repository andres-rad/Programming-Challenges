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

//BIGINT - Caloventor
#define BASEXP 6
#define BASE 1000000
#define LMAX 1000

struct bint{
	int l;
	tint n[MAX];
	bint(tint x=0){
		l=1;
		forn (i, LMAX){
			if (x) l=i+1;
			n[i]=x%BASE;
			x/=BASE;
		}
	}
	bint(string x){
		l=(x.size()-1)/BASEXP+1;
		fill(n, n+LMAX,0);
		tint r=1;
		forn(i,x.size()){
			n[i/BASEXP] += r*(x[x.size()-1-i]-'0');
			r*=10;
			if (r==BASE)r=1;
		}
	}
	void out(){
		cout<<n[l-1];
		dforn(i, l-1) printf("%6.6llu", n[i]); //6=BASEXP!!
	}
	void invar(){
		fill(n+l, n+LMAX, 0);
		while (l>1 && !n[l-1]) l--;
	}
};

bint operator+(const bint&a, const bint&b){
	bint c;
	c.l=max(a.l, b.l);
	tint q=0;
	forn (i, c.l){
		q+=a.n[i]+b.n[i];
		c.n[i]=q %BASE;
		q/=BASE;
	}
	if (q) c.n[c.l++]=q;
	c.invar();
	return c;
}

pair<bint, bool> lresta(const bint &a, const bint &b){
	bint c;
	c.l=max(a.l, b.l);
	tint q=0;
	forn (i,c.l){
		q+=a.n[i]-b.n[i];
		c.n[i]=(q+BASE) % BASE;
		q=(q+BASE)/BASE-1;
	}
	c.invar();
	return mp(c, !q);
}

bool operator<= (const bint &a, const bint &b){
	return lresta(b,a).second;
}


bool operator== (const bint &a, const bint &b){
	return a<=b && b<=a;
}
	


int main(){
	int casos;
	int caso = 0;
	cin >> casos;
	while(caso < casos){
		caso++;
		int n,m;
		cin >> n >> m;
		vector<int> votos(n,0);
		forn(i,m){
			forn(j,n){
				int voto;
				cin >> voto;
				votos[i]+= voto;
				i++;
			}
			j++;
		}
	int ganador = 1;
	forn(i,n){		
		if(votos[i] > votos[ganador]){
			ganador = i;
	}
	return 0;
}
