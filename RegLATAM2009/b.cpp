#include <bits/stdc++.h>
using namespace std;
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n); i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long tint;

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << v << endl;
#else
#define debug(v)
#endif

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, r, c, k;
	while (cin >> n >> r >> c >> k ){
		if (n == 0){
			return 0;
		}

		vector<vector<pair<int, int > > > mat (r, vector<pair<int, int> > (c));

		forn(i, r){
			forn(j, c){
				cin >> mat[i][j].fst;
				mat[i][j].snd = mat[i][j].fst;
			}
		}


		forn(h, k){
			if ((h & 1)== 0){
				forn(i, r){
					forn(j, c){
						int atacante = (mat[i][j].fst + n - 1)%n;
						bool esta = false;
						if (i > 0){
							esta = esta or atacante == mat[i-1][j].fst;
						}
						if (j > 0){
							esta = esta or atacante == mat[i][j-1].fst;
						}
						if (i < r -1){
							esta = esta or atacante == mat[i+1][j].fst;
						}
						if (j < c - 1){
							esta = esta or atacante == mat[i][j+1].fst;
						}
						if (esta){
							mat[i][j].snd = atacante;
						}else{
							mat[i][j].snd = mat[i][j].fst;
						}
					}
				}
			}else{
				forn(i, r){
					forn(j, c){
						int atacante = (n + mat[i][j].snd - 1)%n;
						bool esta = false;
						if (i > 0){
							esta = esta or atacante == mat[i-1][j].snd;
						}
						if (j > 0){
							esta = esta or atacante == mat[i][j-1].snd;
						}
						if (i < r -1){
							esta = esta or atacante == mat[i+1][j].snd;
						}
						if (j < c - 1){
							esta = esta or atacante == mat[i][j+1].snd;
						}
						if (esta){
							mat[i][j].fst = atacante;
						}else{
							mat[i][j].fst = mat[i][j].snd;
						}
					}
				}
			}
		}

		if ((k & 1) == 0){
			forn(i, r){
				forn(j, c){
					cout << mat[i][j].fst << (j != c - 1 ? ' ' : '\n');
				}
			}
		}else{
			forn(i, r){
				forn(j, c){
					cout << mat[i][j].snd << (j != c - 1 ? ' ' : '\n');
				}
			}
		}


	}


	return 0;
}
