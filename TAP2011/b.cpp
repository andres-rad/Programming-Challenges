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
    string n, p;

    while(cin >> n) {
        if(n == "*") break;
        cin >> p;
        int i = 0;
        int res = 0;
        while(i < n.size()){
            if(n[i] != p[i]){
                res++;
                while(n[i] != p[i]) i++;
            }
            i++;
        }
        cout << res << endl;

    }

    return 0;
}
