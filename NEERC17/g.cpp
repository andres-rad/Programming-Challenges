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

    int n;
    cin>>n;
    vector<vector<int> > v (n, vector<int> (7));

    forn(i, n){
        forn(j, 7){
            char t;
            cin>>t;
            v[i][j] = t - '0';
        }
    }

    int res = 0;

    forn(j, 7){
        int inter = 0;
        forn(i, n){
            inter += v[i][j];
        }
        res = max(res, inter);
    }

    cout<<res<<endl;
    return 0;
}
