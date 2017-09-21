#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i=(tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i=(tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define pb push_back

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

#define BINS 15

int main() {
    tint k,s,j,d;

    while(cin >> k >> s >> j >> d) {
        if(k == -1) break;
        debug(k);
        debug(s);
        debug(j);
        debug(d);
        // k rondas
        // s sets a ganar para ganar un partido (mejor de 2*s - 1)
        // j minimos games para ganar
        // d dif minima de games

        vector<vector<double> > p (1<<k, vector<double> (1<<k, 0.0));
        // p[i][j] proba de que i le gane a j un game
        // p[i][i] = 0
        // p[i][j] + p[j][i] = 1

        forn(i, 1<<k){
            forn(jj, 1<<k){
                cin>>p[i][jj];
                p[i][jj] = p[i][jj]/100.0;

                debug(p[i][jj]);
            }
        }

        vector<vector<vector<vector<double> > > > dp (1<<k, vector<vector<vector<double> > > (1<<k, vector<vector<double> > (BINS, vector<double> ( 2*j + 3, 0.0))));
        // dp[i][j][x][b] la proba de que el jugador i le gane al j, luego de x games, por b-J-2 games
        // j > i

        forn(i, 1<<k){
            forsn(jj, 0,  1<<k){
                if (jj == i)
                    continue;
                dp[i][jj][0][0 + j + 2] = 1.0;

                forsn (l, 1, BINS){
                    forsn (b, max(-j, -l), min(j, l) + 1){
                        debug(l);

                        debug(b);

                        // l = x + y
                        // x = y + b - 1
                        // y = (l - b + 1)/2
                        if ( (l - b + 1 < 2*(j) || b - 1 > -d)){
                            cerr<<"gane el anterior"<<endl;
                            debug(dp[i][jj][l - 1][b - 1 + j + 2]);
                            // Este es el caso donde yo gane el ultimo
                            // osea que el estado anterior era con b-1 a mi favor
                            dp[i][jj][l][b + j + 2] += p[i][jj]*dp[i][jj][l - 1][b - 1 + j + 2];
                        }
                        // l = x + y
                        // x = y + b + 1
                        // x = (l + b + 1)/2
                        if ( (l + b + 1 < 2*j || b + 1 < d)){
                            // Este es el caso donde yo perdi el ultimo
                            // osea que el estado anterior era con b+1 a mi favor
                            cerr<<"perdi el anterior"<<endl;
                            debug(dp[i][jj][l - 1][b + 1 + j + 2]);
                            dp[i][jj][l][b + j + 2] += p[jj][i]*dp[i][jj][l - 1][b + 1 + j + 2];
                        }
                        debug(i);
                        debug(jj);
                        debug(dp[i][jj][l][b+j + 2])
                        cerr <<"--------¤----------"<<endl;
                    }
                }
            }
        }

        vector<vector<double> > sett (1<<k, vector<double> (1<<k, 0.0));
        vector<vector<double> > settHope (1<<k, vector<double> (1<<k, 0.0));

        // sett[i][j] tiene la proba de que i le gane a j un set

        forn(i, 1<<k){
            forsn(jj, i+1, 1<<k){
                debug(i);
                debug(jj);

                forsn (l, 1, BINS){
                    if (l + d >= 2*(j) ){
                        sett[jj][i] += /*p[jj][i]*/dp[i][jj][l][-d + j + 2];
                        settHope[jj][i] += /*p[jj][i]*/dp[i][jj][l][-d + j + 2]*l;
                    }
                    if (l + d >= 2*j ){
                        sett[i][jj] += /*p[i][jj]*/dp[i][jj][l][d + j + 2];
                        settHope[i][jj] += /*p[i][jj]*/dp[i][jj][l][d + j + 2]*l;
                    }
                    debug(dp[i][jj][l][-d + j + 2]);
                    debug(dp[i][jj][l][d + j + 2]);
                    debug(sett[i][jj]);
                    debug(sett[jj][i]);
                    debug(settHope[i][jj]);
                }

                cerr <<"--------¤----------"<<endl;


            }
        }

        vector<int> perm (1<<k);

        forn(i, 1<<k){
            perm[i] = i;
        }

        int ans = 0;
        while(next_permutation(perm.begin(), perm.end())){
            int temp = 0;

            forn(i, k){
                forsn(j, 0, 1<<(k-i-1)){

                }
            }

            ans = max(ans, temp);
        }


    }

    return 0;
}
