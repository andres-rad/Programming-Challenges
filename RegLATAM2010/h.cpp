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

    int n, m;
    cin >> m>> n;

    while (n!= 0){
        map<int, pair<vector<int>, vector<int> > > comp;
        vector<pair<int, int> > sf;
        comp[0] = {vector<int>(), vector<int>()};
        comp[m] = {vector<int>(), vector<int>()};

        forn(i,n){
            int s, f;
            cin >> s>> f;
            comp[s].fst.pb(sf.size());
            comp[f].snd.pb(sf.size());
            sf.pb({s,f});

        }
        int order = 0;
        for (auto it : comp){
            //int order = it.fst;
            for (auto s : it.snd.fst){
                sf[s].fst = order;
                debug(sf[s].fst);
            }
            for (auto f : it.snd.snd){
                sf[f].snd = order;
                debug(sf[f].snd);
            }
            order++;
        }

        vector<vector<int> > dp (order, vector<int> (order, 0));
        dp[0][0] = 1;
        sort(sf.begin(), sf.end());

        for (auto r:sf){
            debug(r.fst);
            debug(r.snd);
            if(r.fst == 0){
                dp[0][r.snd] ++;
            }else{
                forn(i, r.fst){
                    forsn(j, r.fst, r.snd){
                        dp[j][r.snd] += dp[i][j];
                        dp[j][r.snd] %= 100000000;

                    }
                }
            }
            debug(dp[r.fst][r.snd]);
        }

        int res = 0;
        order--;
        forn(i, order){
            res += dp[i][order];
            res %= 100000000;
        }
        cout << res << endl;;
        cin >>m >> n;
    }

    return 0;
}
