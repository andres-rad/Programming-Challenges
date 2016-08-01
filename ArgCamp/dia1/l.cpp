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
#define dforn(i,n) for(int i=n-1; i>=0; i--)
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
#define LMAX 100000

struct bint{
	int l;
	tint n[LMAX];
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
bint operator- (const bint&a, const bint&b){return lresta(a, b).first;}

bool operator<= (const bint &a, const bint &b){
	return lresta(b,a).second;
}


bool operator== (const bint &a, const bint &b){
	return a<=b && b<=a;
}

pair<bint, tint> ldiv(const bint& a, tint b){// c = a / b ; rm = a %b 79 bint c;
	tint rm = 0;
	bint c;
	dforn(i, a.l){
		rm = rm * BASE + a.n[i];
		c.n[i] = rm / b;
		rm %= b;
	}
	c.l = a.l;
	c.invar();
	return make_pair(c, rm);
}
bint operator/(const bint&a, tint b){return ldiv(a, b).first;}

tint operator%(const bint&a, tint b){return ldiv(a, b).second;}

bint operator*(const bint&a, tint b){
	bint c;
	tint q = 0;
	forn(i, a.l) q += a.n[i]*b, c.n[i] = q %BASE, q/=BASE; c.l = a.l;
	while(q) c.n[c.l++] = q %BASE, q/=BASE;
	c.invar();
	return c;
}


tint pow(tint num, tint mod, bint expo ){
	//Creo que la recursion chupa mucha memoria, hacer bottom up con un while
	expo.out();
	cout<<endl;
	if (expo==bint(0)) {
		return 1;
	}
	tint medio=pow(num,  mod, expo/2) % mod;
	tint res = medio*medio %mod;
	if (expo %2 ==1) res*= num % mod;
	return res;
}

string n;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	tint c,m;
	while (cin>>n>>c>>m){

		//cin>>c>>m;

		bint numero(n);
		//return 0;
		//Con el constructor se rompe todo con numeros grandes
		//tint res=pow(c,m,numero);
		tint res=c;
		while (!(numero== bint (0))){
			bint expo(1);

			cout<<res<<endl;

			int i=0;
			while(expo*32<=numero){
				res=res*res %m;
				res=res*res %m;
				res=res*res %m;
				res=res*res %m;
				res=res*res %m;
				expo=expo*32;
				//numero = numero /32;
				cout<<i<<'\n';
				i++;
				//(numero-expo).out();
				//cout<<'\n';
			}
			numero=numero-expo;
		}

		cout<<res<<'\n';
	}
	return 0;
}
