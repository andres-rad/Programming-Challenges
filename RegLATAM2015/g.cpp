#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define TMAX 1440.0
#define INF 1e9
#define MAX_V 250001
#define add(a,b,w) G[a].pb(make_pair(w,b))

double t = 0;

struct recta{
	int m;
	int b;

	double evaluar(double t){
		return m*t + b;
	}

	bool operator<(recta &a){
		return evaluar(t) < a.evaluar(t);
	}
}

double minCosto(d){
	priority_queue<pair<double, int>, vector<pair<double, int> > > Q;
	vector<double> dist(N, INF); vector<int> dad(N, -1);
	Q.push(make_pair(0, s)); dist[i];
	while(!Q.empty()){
		pair<double, int> p = Q.top(); Q.pop();
		if p.snd == tiempo
	}  
}


int main() {
	int n, m;
	while(cin >> n){
		cin >> m;
		vector<vector<pair< int, recta> > g(n);
		forn(k, m){
			int i,j,a,b;
			cin >> i >> j >> a >> b;
			double v1 = 0;
			double v2 = TMAX / 3;
			double v3 = 2* v2;
			double v4 = TMAX;
			double res0 = 0;
			while(v4 - v1 < 10e-8){
				t=v1;
				double res1 = minCosto(1, n);
				t=v2;
				double res2 = minCosto(1, n);
				t=v3;
				double res3 = minCosto(1, n);
				if(res2 > res1 && res3 > res2){
					v1 = v2;
				} else {
					v4 = v3;
				}
				v2 = v4/3;
				v3 = 2*v2;


			}
			cout << res0 << endl;
		}
	}
	return 0;
}