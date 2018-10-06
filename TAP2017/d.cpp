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

vector<double> cambio;
vector<vector<int> > mat (n, vector<int> (n, INF));

vector<double> deuno;
vector<double> deotro;

tint n, m;

void dijkstra(int curr, double guita){
	if (desde == 0){
		vector<int> &a = deuno;
	}else{
		vector<int> &a = deotro;
	}
	a = vector<double> (n, 0.0);
	a[curr] = (double)guita;
	// en a tengo que guardar la maxima cantidad de plata con la que puedo llegar sin ciclos

	vector<int> vis (n, 0);
	vis[curr] = 1;

	while(1){
		int prox = -1;
		forn (i,n){
			if ((not vis[i]) and (prox == -1 or a[i] < a[prox]){
				prox = i;
			}
		}
		if (prox == -1){
			break;
		}
		vis[prox] = 1;
		double tarasca = a[prox];


		forn(j, mat[prox].size()){
			if (prox==j or mat[prox][j] == INF){
				continue;
			}
			double tasa = max(1.0, cambio[prox]/cambio[j]);


			a[j] = max(a[j], (a[prox] - (double)mat[prox][j])*tasa  );
		}

	}
}

int main() {
	//tint n, m;
	cin >> n >> m;

	cambio = vector<double>  (n);
	forn(i,n){
		cin >> cambio[i];
	}

	mat = vector<vector<int> >  (n, vector<int> (n, INF));

	forn(i,m){
		int a, b, p;
		cin >> a >> b >> p;
		mat[--a][--b] = p;
		mat[b][a] = p;
	}

	int lo = 0, hi = 1123456;
	int res = INF;

	while (hi - lo > 1){
		double m = (hi+lo)/2;
		dijkstra(0, m);

		forn(i, n){
			if (deuno[i] <=)
			if (i != 0){
				dijkstra(i, deuno[i]);
			}
			forn(j, n){
				if (i==j){
					continue;
				}
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

	}
	/*
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
*/
	cout << (res == INF ? -1 : res) << endl;

	return 0;
}
