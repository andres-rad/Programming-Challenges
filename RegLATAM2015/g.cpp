//#include <bits/stdc++.h>
#include<vector>
#include<iostream>
#include<iomanip>
#include<queue>

#define forn(i,n) for(int i = 0; i < n; i++)
#define forsn(i,s,n) for(int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define INF 1e10
using namespace std;

struct flineal{
    double A;
    double B;

    double evaluar(double tiempo){
        return A*tiempo + B;
    }
    double evaluar(double tiempo) const{
        return A*tiempo + B;
    }
};

int cnt;

double cMTeo(const vector<vector<pair<flineal, int> > > & g, const double & tiempo){
  //cout<<'r'<<endl;
  vector<double> peso(g.size()+10, INF);
  vector<bool> vis(g.size()+10, false);

  peso[0]=0.0;

  bool sigo=true;
  //cout<<'f'<<endl;

  while (sigo){
    //cerr<<'f'<<endl;
    int prox=-1;

    int i=0;
    int mini=2147483647;
    while (i<g.size()){
      //cout<<'h'<<endl;
      cnt++;
      //cerr<<(vis[i]?"vis":"No Vis")<<endl<<peso[i]<<endl<<"mini: "<<mini<<endl;
      if (!vis[i] && mini>peso[i]){
        mini=peso[i];

        prox=i;
      }
      i++;
    }

    cerr<<prox<<endl;

    if (prox==-1) {
      sigo=false;
      break;
    }
    vis[prox]=true;

    forn (j, g[prox].size()){
      if (peso[g[prox][j].second]>peso[prox]+g[prox][j].first.evaluar(tiempo)){
          peso[g[prox][j].second]=peso[prox]+g[prox][j].first.evaluar(tiempo);
          //cerr<<peso[g[prox][j].second]<<endl;
        }
    }
  }

  return peso[g.size()-1];
}

double costoMinimo(const vector<vector<pair<flineal, int> > > & g, const double & tiempo){
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int > > > Q;
    vector<double> peso(g.size()+10, INF);
    vector<bool> vis(g.size()+10, false);
    peso[0] = 0.0;
    Q.push({peso[0], 0});
    while(!Q.empty() ){
        pair<double,int> actual = Q.top(); Q.pop();
        //if (vis[actual.second]) continue;


        for(auto it = g[actual.second].begin(); !vis[actual.second] && it != g[actual.second].end(); it++){
            cnt++;
            if(peso[actual.second] + (it->first).evaluar(tiempo) < peso[it->second] - 1e-8){
                peso[it->second] = peso[actual.second] + (it->first).evaluar(tiempo);
                Q.push(mp(peso[it->second], it->second));
            }
        }
        vis[actual.second]=true;

        if(actual.second == g.size()-1) break;
    }
    return peso[g.size()-1];
}

int main(){
    cout << fixed;

    //cout<<'d'<<endl;
    cout << setprecision(5);
    cin.tie(NULL);
    ios::sync_with_stdio(false);
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
        double res = 0.0;

        int iterations=0;

        while(v3 - v0 > 1e-12 && iterations < 120){
            double res1;
            cnt=0;
            res = costoMinimo(g, v1);
            //res = cMTeo(g, v1);
            cerr<<cnt<<endl;
            cnt=0;
            //res1 = cMTeo(g, v2);
            res1 = costoMinimo(g, v2);
            cerr<<cnt<<endl;
            //res2 = costoMinimo(g, v2);

            if(res1 > res ){
                v0 = v1;
            } else {
                v3 = v2;
            }
            v1 = (v3-v0)/3.0 + v0;
            v2 = 2*(v3-v0)/3.0 + v0;
            iterations++;
        }
        cout << res << endl;
    }
    return 0;
}
