#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;
#define EPS 1e-8

struct pto{
	double x, y;
	pto(double x = 0, double y=0):x(x), y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(double z){return pto(x+z, y+z);}
	pto operator*(double z){return pto(x*z, y*z);}
	pto operator/(double z){return pto(x/z, y/z);}

	double operator*(pto a){return x*a.x + y*a.y;}

	double operator^(pto a){return x*a.y - y*a.x;}

	bool left(pto q, pto r){return ((q-*this) ^ (r-*this))>0;}
	bool operator<(const pto &a) const{return x < a.x - EPS || (abs(x - a.x) < EPS && y < a.y-EPS);}
	bool operator==(pto a){return abs(x-a.x) < EPS && abs(y-a.y) < EPS;}
	double norm(){return sqrt(x*x + y*y);}
	double norm_sq(){return x*x + y*y;}
};
double dist(pto a, pto b){return (b-a).norm();}




void CH(vector<pto>& P, vector<pto> &S){
	S.clear();
	sort(P.begin(), P.end());
	forn(i, P.size()){
		while (S.size() >= 2 && S[S.size() - 1].left(S[S.size() - 2], P[i]))
			S.pop_back();
		S.pb(P[i]);
	}

	S.pop_back();
	int k = S.size();
	for(int i = P.size() - 1; i >= 0; i--){
		while(S.size() >= k+2 && S[S.size() - 1].left(S[S.size()-2], P[i]))
			S.pop_back();
		S.push_back(P[i]);

	}
	S.pop_back();
}

double dis(pto a, pto b, pto c){
	b = (b-a)/(b-a).norm();
	return abs((c-a)^b);
}

int main() {
	int n;

	while(cin >> n){
		int r;
		cin >> r;
		vector<pto> P(n);
		vector<pto> S;
		forn(i, n){
			double a, b;
			cin >> a >> b;
			P[i] = {a,b};

		}
		CH(P, S);

		int prox = 0;

		double ans = 2*r;

		forn(i, S.size()){
			// veo la linea P[i] -> P[i+1]
			pto a = S[i], b = S[(i+1)%S.size()];

			int localprox = prox;
			if (localprox == i) localprox = (localprox + 2)%S.size();
			else if (localprox == (i+1)%S.size()) localprox = (localprox + 1)%S.size();


			while ((localprox+1)%S.size() != i and dis(a,b,S[localprox]) < dis(a, b, S[(localprox + 1)%S.size()])){
				localprox++;
				localprox %= S.size();
			}

			prox = localprox;
			// cerr << localprox << endl;

			if (ans > dis(a,b,S[prox])){
				ans = dis(a,b,S[prox]);
				// cerr << ans << endl;
			}

			// cerr << S[i].x << ' ' << S[i].y << endl;

		}

		cout << setprecision(100) << ans << endl;
		
	}	
	return 0;
}