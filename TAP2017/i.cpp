#include <bits/stdc++.h>
using namespace std;
#define tint long long 
#define ii pair<tint,tint>
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

struct pto{
	double x, y;
	pto(double x = 0, double y = 0):x(x), y(y){};
	double operator^(pto a){return x*a.y - y*a.x;}
	double operator*(pto a){return x*a.x + y*a.y;}
	double norm(){return (x*x + y*y);}
	pto operator-(pto a ) { return pto(x-a.x, y-a.y);}
};

#define eps 1e-5
	double angle(pto a, pto o, pto b){
		pto oa = a-o;
		pto ob = b-o;
		return atan2(oa^ob, oa*ob);
	}
	double dist(pto a, pto b){
		return (b-a).norm();
	}
int main() {

	double pi = 3.141592653589793;
	tint n;
	cin >> n;

	vector<pto > v1, v2;

	forn(i, n){
		int a, b;
		cin >> a >> b ;
		v1.pb(pto(a,b));
	}

	forn(i, n){
		int a, b;
		cin >> a >> b ;
		v2.pb(pto(a,b));
	}

	vector<double> a1, a2;

	forn(i, n){
		double ang;
		pto a = v1[(i-1+n)%n];
		pto b = v1[(i+n)%n];
		pto c = v1[(i+1+n)%n];

		ang = angle(a, b, c);
		if (1) {
			a1.pb(ang);
			//debug(ang);
		}

	}
	forn(i, n){
		double ang;
		pto a = v2[(i-1+n)%n];
		pto b = v2[(i+n)%n];
		pto c = v2[(i+1+n)%n];

		ang = angle(a, b, c);
		if (1) {
			a2.pb(ang);
			//debug(ang);
		}
	}


	bool res = false;
	forn (d, n){
		bool cur = true;
		double cte = (dist(v1[d], v1[(d+1)%n]))/(dist(v2[0], v2[1]));
		//debug(cte);
		forn(i, n){
			cur = cur && fabs(a1[(i+d)%n] - a2[i]) < eps; 
			cur = cur && fabs(cte - (dist(v1[(i+d)%n], v1[(i+d+1)%n]))/(dist(v2[(i)], v2[(i+1)%n]))) < eps;
			cur = cur && fabs(cte - (dist(v1[(i+d)%n], v1[(i+d-1+n)%n]))/(dist(v2[(i)], v2[(i-1+n)%n]))) < eps;
			//debug(fabs(cte - (dist(v1[(i+d)%n], v1[(i+d+1)%n]))/(dist(v2[(i)], v2[(i+1)%n]))));
			//debug(fabs(cte - (dist(v1[(i+d)%n], v1[(i+d-1+n)%n]))/(dist(v2[(i)], v2[(i-1+n)%n]))));

		}

		res = res || cur;
	}

	cout << (res ? "MISMO" : "OTRO") <<endl;

	return 0;
}