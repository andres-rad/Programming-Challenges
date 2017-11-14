#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define fst first
#define snd second
#define pb push_back
#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

int main() {
    tint n, k;
    cin >> n >> k;
    tint gauss_k;
    vector<tint> seq;
    do{
        gauss_k = floor((1.0+sqrt(1.0+8.0*(double)k))/2.0);
        n -= gauss_k;
        if (n < 0){
            cout << "Impossible" << endl;
            return 0;
        }
        k -= (gauss_k * gauss_k - gauss_k)/2;
        seq.pb(gauss_k);
    } while(n != 0);

    if (k > 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    for(auto k : seq){
        forn(i, k) cout << "(";
        forn(i, k) cout << ")";
    }
    cout << endl;
    return 0;
}
