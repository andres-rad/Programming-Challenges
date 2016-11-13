#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first
#define ull unsigned long long

using namespace std;

int main(){

	int n;
	cin>>n;
	cout <<(min(n,11)) <<endl;
}

/*

ull mcd(ull a, ull b) {
	return (a==0) ? b : mcd(b%a, a);
}

struct frac {
	ull p,q;
	frac(ull num=0, ull den=1) : p(num), q(den) {norm();}
	frac operator+(const frac o) {
		ull a = mcd(q, o.q);
		ull np = p*(o.q/a) + o.p * (q/a);
		ull nq = q*(o.q/a);
		norm();
		return frac(np,nq);
	}
	frac operator*(const frac& o) {
		ull a = mcd(q,o.p);
		ull b = mcd(o.q, p);
		ull np = (p/b) * (o.p/a);
		ull nq = (q/a) * (o.q/b);
		if(np >= ((ull)1<<32) || nq >= ((ull)1<<32)) {
			np /= 2;
			nq /= 2;
		}
		return frac(np,nq);
	}
	bool operator<=(const frac& o) {
		return p * o.q < q * o.p;
	}
	void norm() {
		ull aux = mcd(p,q);
		if(aux) {
			p /= aux;
			q/= aux;
		} else {
			q=1;
		}
		if(q<0) {
			q=-q;
			p=-p;
		}
	}
	ostream& operator<<(ostream &os) {
		return os<<p<<"/"<<q;
	}
};

int main() {

	long n;
	cin >> n;

	frac a(0);
	frac b(1, n-1); 

	frac minV(999999);
	long minT = 1;

	//cerr << " a " << a.p << "/" <<a.q << " b " << b.p << "/" << b.q << endl;

	forsn(t,2,n+1) {
		frac la = a, lb = b;
		a = frac(n-1.0) * lb * lb + la * la;
		b = frac(2) * la * lb + frac(n-2) * lb * lb;

	//	cerr << "t " << t << " a " << a.p << "/" <<a.q
	//		 << " b " << b.p << "/" << b.q << endl;

		a = lb;
		b = la * frac(1,n-1) + lb * frac(n-2,n-1);

	//	cerr << "   (a " << a.p << "/" <<a.q
	//		 << " b " << b.p << "/" << b.q << ")" << endl;

	//	cerr << "   " << ((double)a.p / (double)a.q) << " vs " << ((double)minV.p / (double)minV.q) << endl;
		if(a <= minV) {
	//		cerr << "    new best " << endl;
			minT = t;
			minV = a;
		}
	}

	cout << minT << endl;

	return 0;
}
*/