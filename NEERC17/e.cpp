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

int main() {
    int n;
    tint hi = 2e6;
    tint lo = 0;
    cin >> n;

    vector<int> asteriscos;
    vector<int> pacmen;
    char temp;

    forn(i,n){
        cin >> temp;
        if(temp == 'P'){
            pacmen.pb(i);
        } else if(temp == '*') {
            asteriscos.pb(i);
        }
    }

    while(hi - lo > 1){
        tint m = (hi + lo) / 2;
        bool can = false;
        int last_a = 0;
        int cur_p = 0;
        while(cur_p != (int)pacmen.size()){
            debug(cur_p); debug(m);
            int k = max(pacmen[cur_p] - asteriscos[last_a], 0);
            if(k > m) break;

            int c = max(m-2*k, (m-k)/2);

            while(asteriscos[last_a] <= pacmen[cur_p] + c) {
                debug(last_a); debug(asteriscos.size()); debug(c);
                if(++last_a >= asteriscos.size()){
                    can = true;
                    break;
                }
            }
            if(can) break;
            cur_p++;
        }
        if(can){
            hi = m;
        } else {
            lo = m;
        }
    }

    cout << hi << endl;
    return 0;
}
