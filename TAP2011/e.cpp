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

int main() {
    int n;

    while(cin >> n) {
        if(n == -1) break;
        tint suma = 0;
        vector<tint> v (n-1);
        set<tint> setty;
        forn(i,n-1){

            cin>>v[i];
            suma += v[i];
            setty.insert(v[i]);
        }
        sort(v.begin(), v.end());

        double prom = ((double) suma)/(double)(n-1);
        int res = 0;

        debug(prom);
        if (abs(prom - round(prom)) <= 1e-4  && v[((int)v.size())/2 - 1] < round(prom) && round(prom) < v[v.size()/2] ){
            res++;
        }

        prom = ((double)suma - v[v.size()/2]);

        double poss = v[v.size()/2]*(n-1) - prom;

        debug(poss)
        if (abs(poss - round(poss)) <= 1e-4  && setty.find(round(poss)) == setty.end() && round(poss) > v[v.size()/2] ){
            res++;
        }

        prom = ((double)suma - v[v.size()/2 - 1]);

         poss = v[v.size()/2 - 1]*(n-1) - prom;

         debug(poss);
        if (abs(poss - round(poss)) <= 1e-4  && setty.find(round(poss)) == setty.end() && round(poss) < v[v.size()/2 - 1] ){
            res++;
        }

        cout<<res<<endl;
    }

    return 0;
}
