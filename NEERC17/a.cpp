#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define fst first
#define snd second
#define pb push_back
#define debug(v) cerr << #v << " = " << (v) << endl;



int main() {
    tint n;
    cin >> n;

    vector<pair<tint,tint>> vec(n);

    forn(i,n) {
        tint a,b;
        cin >> a >> b;
        a--;
        b--;
        vec[i].fst = a;
        vec[i].snd = b;
    }

    tint u;
    forn(i,n) {
        if(vec[i].fst == -1) {
            u = i;
            break;
        }
    }

    tint v = u;
    tint q = 0;
    while(true) {
        while(vec[v].snd != -1)
            v = vec[v].snd;

        while(q < n) {
            if(q != u and vec[q].fst == -1)
                break;
            q++;
        }

        if(q == n)
            break;

        vec[v].snd = q;
        vec[q].fst = v;
    }

    forn(i,n) {
        cout << vec[i].fst+1 << " " << vec[i].snd+1 << endl;
    }

    return 0;
}
