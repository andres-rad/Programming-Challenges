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

vector<pair<double, double> > vd;
int n, e, s;
vector<vector<vector<double> > > dp;
// dp[i][j][f] los ultimos que visite fueron el i de la izq y el j de la derecha, si i == 1 el ultimo es el de la derecha

double dist(int i, int d){
    return sqrt((vd[i].fst - vd[d].fst)*(vd[i].fst - vd[d].fst) +
        (vd[i].snd - vd[d].snd)*(vd[i].snd - vd[d].snd));
}

double dfs(int i, int d, int f){
    i = (i+n) %n;
    d = (d+n) %n;
    if (dp[i][d][f] != -1){
        return dp[i][d][f];
    }
    if (i==e){
        return dp[i][d][f] = dfs(i, d-1, 1) + dist(d, (d-1+n)%n);
    }
    if (d == e){
        return dp[i][d][f] = dfs(i+1, d, 0) + dist(i, (i+1+n)%n);
    }
    double ans = 1e8;
    if (f){
        ans = min(dfs(i, d-1, f) + dist(d, (d-1+n)%n), dfs(i, d-1, 0) + dist(d, i));
    }else{
        ans = min(dfs(i+1, d, f) + dist(i, (i+1+n)%n), dfs(i+1, d, 1) + dist(d, i));
    }
    return dp[i][d][f] = ans;
}
int main() {
    //int n;
    ios::sync_with_stdio(0); cin.tie(0);

    while(cin >> n) {
        //if(n == -1) break;
        dp = vector<vector<vector<double> > >(n, vector<vector<double> >(n,vector<double> (2, -1.0)));
        //int e,s;
        cin>>e>>s;
        e--; s--;

        vd.clear();
        //vi.clear();

        forn(i, n){
                double t, tt;
                cin>>t>>tt;
                vd.pb({t, tt});
        }

        dp[e][e][0] = dp[e][e][1] = 0.0;


        if (e>s){
            int t = e;
            e = s;
            s = t;
        }

        for (int h = 0; h < (n-(s-e)+1); h++){
            int i = (e-h+n)%n;
            debug(i);
            for (int k = 0; k < s - e + 1;k++){
                int j = (e+k)%n;
                if (i == j) continue;
                debug(j);
                forn (f, 2){
                    debug(f);
                    int ii = (i+n) %n;
                    int dd = (j+n) %n;
                    if (dp[ii][dd][f] != -1){
                        continue;
                    }
                    if (ii == e){
                        dp[ii][dd][f] = dp[ii][(dd-1+n)%n][1] + dist(dd, (dd-1+n)%n);
                    }
                    if (dd == e){
                        dp[ii][dd][f] = dp[(i+1)%n][dd][0] + dist(ii, (ii+1+n)%n);
                    }
                    double ans = 1e8;
                    if (f){
                        ans = min(dp[ii][(dd-1+n)%n][f] + dist(dd, (dd-1+n)%n), dp[ii][(dd-1+n)%n][0] + dist(dd, ii));
                    }else{
                        ans = min(dp[(ii+1)%n][dd][f] + dist(ii, (ii+1+n)%n), dp[(ii+1)%n][dd][1] + dist(dd, ii));
                    }
                    dp[ii][dd][f] = ans;
                    debug(ans);
                }
            }
        }
        debug(dfs(s, (s-1+n)%n, 0));
        debug(dp[s][(s-1+n)%n][0]);
        debug(dfs(s, (s-1+n)%n, 1));
        debug(dp[s][(s-1+n)%n][1]);
        debug(dfs((s+1+n)%n, s, 0));
        debug(dp[(s+1+n)%n][s][0]);
        debug(dfs((s+1+n)%n, s, 1));
        debug(dp[(s+1+n)%n][s][1]);

        double ans = min(dfs(s, (s-1+n)%n, 0), dfs(s, (s-1+n)%n, 1));
        ans = min(ans, dfs((s+1+n)%n, s, 0));
        ans = min(ans, dfs((s+1+n)%n, s, 1));

        cout << setprecision(6) << fixed << ans<< '\n';

    }

    return 0;
}
