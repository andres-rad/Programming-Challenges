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
#define debug(v) 	cerr << #v << " = " << (v) << endl;
#define pb push_back

int w,d,a,k;
vector<tint> p1, p2, q1, q2;

#define BINS 1250000

vector<double> memo1, memo2, add1, add2;
vector<int> max1, max2 ;
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

	forn(i, max1.size()-1){
		if (memo1[max1[i]] > memo1[max1[i+1]]){
			/// decreciente
			auto u = memo1.rend() - max1[i] + 1;
			auto v = memo1.rend() - max1[i+1];
			auto dit = lower_bound(v,u ,d );
			//if (dit != u){
				ans -= add1[ memo1.rend() - dit ]  - add1[max1[i]];
				ans -= (max1[i+1] -( memo1.rend() - dit) ) *d;
				//ans -= (max1[i+1] - max1[i]) * min(0., d-memo1[max1[i+1]]);

			//}

		}else {
			/// creciente
			auto u = memo1.begin() + max1[i] ;
			auto v = memo1.begin() + max1[i+1] + 1;
			auto dit = lower_bound(u, v, d);
			//if (dit != v){
				ans -= - add1[ dit - memo1.begin()]  + add1[max1[i+1]];
				ans -= ((dit - memo1.begin())  - max1[i]) *d;

				//ans += (max1[i+1] - max1[i]) * min(0., d-memo1[max1[i]]);

			//}

		}
	}

	forn(i, max2.size()-1){
		cerr << "y2 from to " << max2[i] << " " << max2[i+1] << " ";
		if (memo2[max2[i]] > memo2[max2[i+1]]){
			/// decreciente
			cerr << "es dec";
			auto u = memo2.rend() - max2[i] + 1;
			auto v = memo2.rend() - max2[i+1];
			auto dit = lower_bound(v,u ,d );
			//if (dit != u){
				ans += add2[ memo2.rend() - dit ]  - add2[max2[i]];
				ans += (max2[i+1] - (memo2.rend() - dit )) *d;
				//ans -= (max2[i+1] - max2[i]) * min(0., d-memo2[max2[i+1]]);

				auto debugTmp = add2[ memo2.rend() - dit ]  - add2[max2[i]] + (max2[i+1] - max2[i]) * min(0., d-memo2[max2[i+1]]);
				cerr << " integra " << debugTmp;
		//	}

		}else {
			/// creciente
			cerr << "es cre";
			auto u = memo2.begin() + max2[i] ;
			auto v = memo2.begin() + max2[i+1] + 1;
			auto dit = lower_bound(u, v, d);
			//if (dit != v){
				ans += - add2[ dit - memo2.begin()]  + add2[max2[i+1]];
				ans += ((dit - memo2.begin())  - max2[i]) *d;

				//ans -= (max2[i+1] - max2[i]) * min(0., d-memo2[max2[i]]);

				auto debugTmp = add2[ dit - memo2.begin()]  - add2[max2[i]] + (max2[i+1] - max2[i]) * min(0., d-memo2[max2[i]]);
				cerr << " integra " << debugTmp;
			//}

		}
		cerr << endl;
	}

	return ans*bin;
}

int main() {
	memo1 = memo2 = vector<double> (BINS, 0);
	add1 = add2 = vector<double> (BINS+1, 0);

	while(cin>>w){
		cin>>d>>a>>k;

		cerr << endl;

		//vector<tint> p1, p2, q1, q2;

		p1.clear();
		p2.clear();
		q1.clear();
		q2.clear();
		forn(i,k+1){
			tint temp;
			cin>>temp;
			p1.pb(temp);
		}
		forn(i,k+1){
			tint temp;
			cin>>temp;
			q1.pb(temp);
		}
		forn(i,k+1){
			tint temp;
			cin>>temp;
			p2.pb(temp);
		}
		forn(i,k+1){
			tint temp;
			cin>>temp;
			q2.pb(temp);
		}

		double bin = (double) w/((double) BINS);

		//
		max1.clear();
		max1.pb(0);
		max2.clear();
		max2.pb(0);
		int crece1, crece2;
		crece1 = crece2 = 0;

		forn(i,BINS){
			memo1[i] = eval(1, i*bin);

			memo2[i] = eval(0, i*bin);

			if (i==1){
				crece1 = memo1[i] > memo1[i-1];
				crece2 = memo2[i] > memo2[i-1];
			}
			if (i>=2){
				if (crece1 ^ (memo1[i] < memo1[i-1])){
					crece1 = not crece1;
					max1.pb(i);
				}
				if (crece2 ^ (memo2[i] < memo2[i-1])){
					crece2 = not crece2;
					max2.pb(i);
				}
			}
		}

		max1.pb(BINS-1);
		max2.pb(BINS-1);

		forn(i,BINS){
			add1[i+1] = add1[i] + memo1[i];
			add2[i+1] = add2[i] + memo2[i];
		}

		cerr << "HARDCODEADO: ";
		debug(tryd(-5.51389));
		double lo = -d;
		double hi = 0;

		while (hi-lo>1e-6){
			double m = (hi+lo)/2;
			debug(m);
			debug(tryd(m));
			if (tryd(m) > a){
				lo = m;
			}else{
				hi = m;
			}
		}

		cout<<setprecision(5)<<fixed<<-hi<<endl;
	}
	return 0;
}
