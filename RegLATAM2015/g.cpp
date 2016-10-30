#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; i++)
#define forsn(i,s,n) for(int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define INF 1e10
using namespace std;
double t = 0;

struct flineal{
    double A;
    double B;

    double evaluar(double tiempo){
        return A*tiempo + B;
    }

    bool operator<(flineal &f){
        return evaluar(t) < f.evaluar(t);
    }
    bool operator>(flineal &f){
        return evaluar(t) > f.evaluar(t);
    }
};



double costoMinimo(vector<vector<pair<flineal, int> > > g, double tiempo){
    priority_queue<pair<double, int>, vector<pair<double, int> > > Q;
    vector<double> peso(g.size()+100, INF);
    peso[0] = 0.0;
    Q.push({peso[0], 0});
    while(!Q.empty()){
        pair<double,int> actual = Q.top(); Q.pop();
        if(actual.second == g.size()) break;
        for(auto it = g[actual.second].begin(); it != g[actual.second].end(); it++){
            if(peso[actual.second] + (it->first).evaluar(t) < peso[it->second]){
                peso[it->second] = peso[actual.second] + (it->first).evaluar(t);
                Q.push(mp(peso[it->second], it->second));
            }
        }
    }
    return peso[g.size()-1];
}

int main(){
    cout << fixed;
    cout << setprecision(5);
    int n,m;
    double TMAX = 1440.0;
    while(cin >> n){
        cin >> m;
        vector<vector<pair<flineal, int> > > g(n);
        forn(k, m){
            int i,j;
            double a,b;
            cin >> i >> j >> a >> b;
            flineal aux = {a, b};
            g[i-1].pb({aux, j-1});
            g[j-1].pb({aux, i-1});
        }

        double v0 = 0;
        double v1 = TMAX/3.0;
        double v2 = (TMAX/3.0)*2;
        double v3 = TMAX;
        double res = 0;
        while(v3 - v0 > 1e-6){
            double res1, res2;

            t = v0;
            res = costoMinimo(g, v0);
            t = v1;
            res1 = costoMinimo(g, v1);
            t = v2;
            res2 = costoMinimo(g, v2);

            if(res1 > res && res2 > res1){
                v0 = v1;
            } else {
                v3 = v2;
            }
            v1 = (v3-v0)/3.0 + v0;
            v2 = 2*(v3-v0)/3.0 + v0;
        }
        cout << res << '\n';
    }
    return 0;
}
