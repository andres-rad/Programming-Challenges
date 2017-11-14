#include <bits/stdc++.h>
using namespace std;
#define tint double
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define febug(f, v) //cerr<<f<< ' '<<#v << " = "<< (v) <<endl;
#define debug(v) 	//cerr << #v << " = " << (v) << endl;
#define pb push_back
#define mp make_pair

int w,d,a,k;
vector<tint> p1, p2, q1, q2;

#define BINS 2700

vector<double> memo1, memo2;
inline double eval(int a, double x){
	double ansp = 0;
	double ansq = 0;
	double xx = 1;

	forn(i, p1.size()){
		ansp += xx*(a ? p1[i]:p2[i]);
		ansq += xx*(a ? q1[i]:q2[i]);
		xx*=x;
	}
	//febug("eval", ans);
	return ansp/ansq;
}

double tryd(double d){
	double bin = (double) w/((double) BINS);

	//double curr = bin;
	double ans = 0;

	forn(i, BINS){
		//debug(curr);
		double top = max(d, memo1[i]);
		double bottom;
		if (top!=d)
			bottom = max(d, memo2[i]);
		else bottom = d;
		ans += (top-bottom)*bin;
		//curr += bin;
		//febug("tryd ", d );
		//febug("tryd ", eval(p1,curr)/eval(q1, curr) );
		//febug("tryd ", top );
	}
	return ans;
}

unordered_map<double, double> mm [2];

double f(double x, double d, int i){
	if (mm[i][x] == 0){
		mm[i][x]= eval(i, x);
	}

	return min(d, mm[i][x]);
}

double integral(double a, double b, int n, double d, int j){
	double area=0, h=(b-a)/n, fa= f(0., d, j), fb;
	forn(i,n){
		fb = f(a+h*(i+1), d, j);
		area += fa + fb + 4*(f(a+h*(i+0.5), d, j));
		fa=fb;
		//cerr<<i<<endl;
	}
	return (area*h)/6.;
}


int main() {
//	memo1 = memo2 = vector<double> (BINS);

	while(cin>>w){
		cin>>d>>a>>k;
		mm[0].clear();
		mm[1].clear();


		//vector<tint> p1, p2, q1, q2;

		p1.clear();
		p2.clear();
		q1.clear();
		q2.clear();
		forn(i,k+1){
			tint temp;
			cin>>temp;
			p1.pb(-temp);
		}
		forn(i,k+1){
			tint temp;
			cin>>temp;
			q1.pb(temp);
		}
		forn(i,k+1){
			tint temp;
			cin>>temp;
			p2.pb(-temp);
		}
		forn(i,k+1){
			tint temp;
			cin>>temp;
			q2.pb(temp);
		}
/*
		double bin = (double) w/((double) BINS);

		forn(i,BINS){
			memo1[i] = eval(1, i*bin);
			memo2[i] = eval(0, i*bin);
		}
*/
		debug(integral(0, w, BINS, 5.51 , 0));// -
		debug(integral(0, w, BINS, 5.51 , 1));
		double lo = 0;
		double hi = d;

		while (hi-lo>1e-6){
			double m = (hi+lo)/2;
			debug(m);
			//debug(tryd(m));
			//double integral(double a, double b, int n, double d, int i){

			double area = integral(0, w, BINS, m, 0) -integral(0, w, BINS, m, 1);
			debug(area);
			if (area  < a){
				lo = m;
			}else{
				hi = m;
			}
		}

		cout<<setprecision(5)<<fixed<<hi<<endl;
	}
	return 0;
}
