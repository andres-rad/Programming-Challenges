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
#define ii pair<tint,tint>

int main() {
    int n, k, m, a;
    cin >> n >> k >> m >> a;

    // <<votos, last>, cand>
    set<pair<ii,tint>, greater<pair<ii,tint>>> s;
    vector<set<pair<ii,tint>, greater<pair<ii,tint>>>::iterator> sIts(n, s.end());

    forn(i,a) {
        tint vot;
        cin >> vot;
        vot--;

        tint count = 0;
        if(sIts[vot] != s.end()) {
            count = sIts[vot]->fst.fst;
            s.erase(sIts[vot]);
        }
        sIts[vot] = s.insert({{count+1, -i}, vot}).fst;
    }

    forn(i,n) {
        if(sIts[i] != s.end()) continue;
        sIts[i] = s.insert({{0,-a},i}).fst;
    }

    vector<bool> gana(n, false);
    vector<bool> pierde(n, false);

    tint faltan = m-a;

    debug(faltan);

    tint minWinVotes = 0;
    tint i = 0;
    for(auto it = s.begin(); it != s.end(); it++, i++) {
        tint cand = it->snd;
        tint votos = it->fst.fst;
        debug(i);
        debug(cand);
        debug(votos);

        if(i < k and votos > 0) {
            gana[cand] = true;
            if(i == k-1) {
                minWinVotes = votos+1;
                debug(minWinVotes);
            }

            auto itt = it;
            tint tieneBajar = k-i;
            tint faltanTmp = faltan;
            itt++;
            while(itt != s.end()) {
                tint esteNecesita = votos+1 - itt->fst.fst;
                if(esteNecesita > faltanTmp){
                    break;
                }
                faltanTmp -= esteNecesita;
                tieneBajar--;
                if(tieneBajar == 0) {
                    pierde[cand] = true;
                    break;
                }
                itt++;
            }

        } else {
            pierde[cand] = true;
            debug(votos + faltan);
            if(votos + faltan >= minWinVotes and faltan > 0)
                gana[cand] = true;
        }
        debug(gana[cand]);
        debug(pierde[cand]);
    }

    forn(i,n) {
        if(gana[i] and pierde[i])
            cout << 2;
        else if(gana[i])
            cout << 1;
        else
            cout << 3;

        if(i+1<n)
            cout << " ";
    }
    cout << endl;

    return 0;
}
