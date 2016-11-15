#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n; i-->s;)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define pb push_back

int main() {
    ll n, m, k;

    cin >> n >> m >> k;

    ll x,s;
    cin >> x >> s;

    // Mana, time
    vector<pair<ll,ll>> times(m+1);
    times[0] = {0,x};

    // Mana, potions
    vector<pair<ll,ll>> potions(k+1);
    potions[0] = {0,0};

    forn(i,m) {
        cin >> times[i+1].snd;
    }
    forn(i,m) {
        cin >> times[i+1].fst;
    }
    forn(i,k) {
        cin >> potions[i+1].snd;
    }
    forn(i,k) {
        cin >> potions[i+1].fst;
    }

    sort(times.begin(), times.end());

    auto itT = times.begin();
    auto itP = potions.rbegin();

    ll best = x*n;

    //cerr << endl;

    while(itT != times.end()) {
        // Too costly
        while(itP != potions.rend() and itT->fst + itP->fst > s) {
            itP++;
        }
        if(itP == potions.rend())
            break;

        //cerr << "potas: " << itP->fst << " " << itP->snd << endl;
        //cerr << "time: " << itT->fst << " " << itT->snd << endl;
        //cerr << endl;

        ll newB = max(n - itP->snd, 0ll) * itT->snd;
        //if(newB) cerr << "    best! " << newB << endl;
        best = min(best, newB);

        itT++;
    }

    cout << best << endl;

    return 0;
}
