#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define debug(v) cerr << #v << " = " << (v) << endl;
#define pb push_back

const tint MOD = 10e9 + 7;

int main() {
	tint s,b;

	while(cin >> s) {
		cin >> b;
		b--;

		// Bolitas usadas - cajas disponibles - bolitas con que se llega al ultimo
		vector<vector<vector<tint>>> mtx(s+1, vector<vector<tint>>(b+1, vector<tint>(s+1)));

		forn(caj, b)
			mtx[0][caj][0] = 1;

		forsn(bol, 1, s+1) {
			mtx[bol][0][bol] = 1;

			forsn(caj, 1, b) {
				forn(bopt, bol+1) {
					mtx[bol][caj][bopt] = 0;

					forn(ult, bopt+1) {
						if(ult*2+1 <= s)
							mtx[bol][caj][bopt] += mtx[bol-ult][caj-1][ult*2+1];
						if(ult*2 <= s)
							mtx[bol][caj][bopt] += mtx[bol-ult][caj-1][ult*2];
						mtx[bol][caj][bopt] %= MOD;
					}
				}
			}
		}

		forn(i,s+1) {
			forn(j, b) {
				forn(k, s+1) {
					cerr << mtx[i][j][k] << ":";
				}
				cerr << " ";
			}
			cerr << endl;
		}

		tint res = (mtx[s][b-1][0] + mtx[s][b-1][1]) % MOD;
		cout << res << endl;
	}

	return 0;
}