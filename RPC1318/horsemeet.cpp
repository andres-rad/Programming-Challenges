#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(tint i=(tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i=(tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long tint;
#define sz(C) ((tint) C.size())

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	double m [64*64+64][64*64+64];
	double b [64*64+64];

	int eq = 0;
	forn(i, 8) forn(j, 8){
		double esta[64*64+64];
	}




	double tabw[2][8][8];
	double tabb[2][8][8];
	int a, b, c, d; cin >> a >> b >> c >> d;
	a--; b--; c--; d--;
	int par = 0;
	forn(i, 8) forn(j, 8){
		tabb[par][i][j] = tabw[par][i][j] = 0;
	}
	tabw[par][a][b] = 1.0; tabb[par][c][d] = 1.0;

	double sum = 2.0;
	double answ = 0, ansb = 0;

	vector<int> dx = {1, 1, 2, 2, -1, -1, -2, -2};
	vector<int> dy = {2, -2, 1, -1, -2, 2, -1, 1};

	while(sum > 1e-5){
		// debug(sum);
		// par = 1 - par;
		forn(i, 8) forn(j, 8){
			tabb[1-par][i][j] = tabb[par][i][j];
			tabw[1-par][i][j] = 0;
		}
		forn(i, 8) forn(j, 8){
			
			if (tabw[par][i][j] > 1e-12){
							// debug("holaa");
				int cnt = 0;
				forn(d, 8){
					if (i + dx[d] < 8 and
						 i + dx[d] >= 0 and
						  j + dy[d] < 8 and
						   j + dy[d] >= 0){

						cnt++;
					}
				}
				double prob = tabw[par][i][j]/(double)cnt;
				forn(d, 8){
					if (i + dx[d] < 8 and
						 i + dx[d] >= 0 and
						  j + dy[d] < 8 and
						   j + dy[d] >= 0){

						if (tabb[par][i+dx[d]][j+dy[d]] < 1e-12){
							tabw[1-par][i+dx[d]][j+dy[d]] += prob;
						}else{
							tabw[1-par][i+dx[d]][j+dy[d]] += 
								prob * (1.0 - tabb[par][i+dx[d]][j+dy[d]]);
							tabb[1-par][i+dx[d]][j+dy[d]] -=
								tabb[par][i+dx[d]][j+dy[d]]*prob;
							sum -= tabb[par][i+dx[d]][j+dy[d]]*prob;
							sum -= tabb[par][i+dx[d]][j+dy[d]]*prob;
							answ += tabb[par][i+dx[d]][j+dy[d]]*prob;
						}
					}
				}
			}
		}

		par = 1 - par;
		forn(i, 8) forn(j, 8){
			tabw[1-par][i][j] = tabw[par][i][j];
			tabb[1-par][i][j] = 0;
		}
		forn(i, 8) forn(j, 8){
			if (tabb[par][i][j] > 1e-12){
				int cnt = 0;
				forn(d, 8){
					if (i + dx[d] < 8 and
						 i + dx[d] >= 0 and
						  j + dy[d] < 8 and
						   j + dy[d] >= 0){

						cnt++;
					}
				}
				double prob = tabb[par][i][j]/(double)cnt;
				forn(d, 8){
					if (i + dx[d] < 8 and
						 i + dx[d] >= 0 and
						  j + dy[d] < 8 and
						   j + dy[d] >= 0){
						if (tabw[par][i+dx[d]][j+dy[d]] < 1e-12){
							tabb[1-par][i+dx[d]][j+dy[d]] += prob;
						}else{
							// debug("holaa");
							tabb[1-par][i+dx[d]][j+dy[d]] += 
								prob * (1.0 - tabw[par][i+dx[d]][j+dy[d]]);
							tabw[1-par][i+dx[d]][j+dy[d]] -=
								tabw[par][i+dx[d]][j+dy[d]]*prob;
							sum -= tabw[par][i+dx[d]][j+dy[d]]*prob;
							sum -= tabw[par][i+dx[d]][j+dy[d]]*prob;
							ansb += tabw[par][i+dx[d]][j+dy[d]]*prob;
						}
					}
				}
			}
		}
		par = 1 - par;

	}

	debug(answ);
	debug(ansb);
	debug(sum);
	return 0;
}