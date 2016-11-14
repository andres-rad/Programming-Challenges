#include <bits/stdc++.h>
#include <math.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

#define PI 3.141592653589793

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	forn(i,n) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	vector<int> ps(n);
	forn(i,n) {
		if(i % 2) {
			ps[n-1-i/2] = v[i];
		} else {
			ps[i/2] = v[i];
		}
	}

	//forn(i,n) {
	//	cerr << ps[i] << " " ;
	//}
	//cerr << endl;

	vector<pair<double,double>> cs(n);

	cs[0].fst = ps[0];
	cs[0].snd = 0;

	forsn(i,1,n) {
		double theta = (i*2*PI/n);
		double x = ps[i] * cos(theta);
		double y = ps[i] * sin(theta);
		cs[i] = {x,y};
	}

	//forn(i,n) {
	//	cerr << cs[i].fst << " " << cs[i].snd << endl;
	//}
	//cerr << endl;

	//return 0;

	double area = 0;
	forsn(i,1,n-1) {
		double dax = cs[i].fst - cs[0].fst;
		double day = cs[i].snd - cs[0].snd;
		double dbx = cs[i+1].fst - cs[0].fst;
		double dby = cs[i+1].snd - cs[0].snd;

		double a = dax * dby - day * dbx;
		area += a;
		//cerr << dax << "," << day << " " << dbx << "," << dby << " -  	" << a << endl;
		//cerr << "i ---- " << i << endl;
	}

	cout << fixed << setprecision(3) << abs(area/2.0) << endl;

	return 0;
}