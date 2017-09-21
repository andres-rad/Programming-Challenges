#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)((n)-1); i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define pb push_back
#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

#define ordenado(s, t) make_pair(min(s,t), max(s,t))

int main() {
    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;

    map<pair<string, string>, int> costo;

    string c1, c2, prev1, prev2;
    cin >> prev1 >> prev2;
    costo[ordenado(prev1, prev2)] = a;

    forn(i, n-1){
        cin >> c1 >> c2;
        if(c1 == prev2){
            auto it = costo.find(ordenado(c1,c2));
            if(it != costo.end()){
                it->second += b;
            } else {
                costo[ordenado(c1,c2)] = b;
            }
        } else {
            auto it = costo.find(ordenado(c1,c2));
            if(it != costo.end()){
                it->second += a;
            } else {
                costo[ordenado(c1,c2)] = a;
            }
        }
        prev1 = c1;
        prev2 = c2;
    }
    vector<int> ahorro;
    int total;
    for(auto it : costo){
        ahorro.pb(it.second);
        total += it.second;
    }

    sort(ahorro.rbegin(), ahorro.rend());
    int res = 0;
    forn(i, min(k, (int)ahorro.size() )){
        int actual = ahorro[i];
        debug(ahorro[i]);
        if(actual <= f) break;
        res += actual - f;
    }
    cout << total - res<< endl;
    return 0;
}
