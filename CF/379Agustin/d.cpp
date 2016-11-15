#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define forsn(i,s,n) for(ll i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(ll i=n; i-->s;)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define pb push_back

int main() {
    ll n;
    cin >> n;

    ll xk,yk;
    cin >> xk >> yk;

    vector<pair<ll,ll>> dirs = {
        {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}
    };

    vector<pair<ll, char>> best(8, {-1,'-'});

    forn(i,n) {
        char t;
        ll x,y;
        cin >> t >> x >> y;

        ll dx=x-xk, dy=y-yk;

        //cerr << "dx dy " << dx << " " << dy << endl;

        if(dx != 0 and dy!=0 and abs(dx) != abs(dy)) {
            continue;
        }

        forn(j, 8) {
            auto dir = dirs[j];
            if(dir.fst == 0 xor dx == 0)
                continue;
            if(dir.snd == 0 xor dy == 0)
                continue;
            if(dx * dir.fst < 0 or dy * dir.snd < 0)
                continue;
            ll dist = abs(dx) + abs(dy);
            if(best[j].fst == -1 or dist < best[j].fst) {
                //cerr << "    good for " << dir.fst << " " << dir.snd << endl;
                best[j].fst = dist;
                best[j].snd = t;
            }
        }
    }

    //cerr << endl;
    //forn(i,8) {
        //cerr << "best: " << best[i].fst << " " << best[i].snd << endl;
    //}
    //cerr << endl;

    bool res = false;
    forn(i,8) {
        auto b = best[i];
        if(b.fst >= 0) {
            if(b.snd == 'Q') {
                res = true;
                continue;
            } else if(b.snd == 'B' and i%2 == 0) {
                res = true;
                continue;
            } else if(b.snd == 'R' and i%2 == 1) {
                res = true;
                continue;
            }
        }
    }

    cout << (res ? "YES" : "NO") << endl;

    return 0;
}
