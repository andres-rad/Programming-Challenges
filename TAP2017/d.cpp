#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define ii pair<tint,tint>
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

#define INF 4234567


int main() {
	tint n, m;
	cin >> n >> m;

	vector<double> cambio (n);
	forn(i,n){
		cin >> cambio[i];
	}

	vector<vector<int> > mat (n, vector<int> (n, INF));

	forn(i,m){
		int a, b, p;
		cin >> a >> b >> p;
		mat[--a][--b] = p;
		mat[b][a] = p;
	}

	forn(i, n) mat[i][i] = 0;

	forn(k, n){
		forn(i, n){
			forn(j, n){
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}

	int res = INF;
	forn(i, n){
		forn(j, n){
			// quiero ver si comprando dolares en i y vendiendo en j, cuanto necesito
			double ratio = cambio[i]/cambio[j];
			if (ratio <= 1.0001 or mat[i][j] >= INF)
				continue;
			// por cada peso k con que llego a i, gano ratio*k cuando llego a j, ahora cuando
			// compro dolares, necesito quedarme minimo con mat[i][j] pesos...
			double camino = mat[i][j];
			double x = camino * (ratio + 1)/(ratio - 1);
			if (fabs(x - ceil(x)) < 1e-6)
				x = x+1.0;
			int xint = (int)x;
			debug(xint);
			debug(mat[0][i]);
			res = min(res, mat[0][i] + xint);

		}
	}

	cout << (res == INF ? -1 : res) << endl;

	return 0;
}
