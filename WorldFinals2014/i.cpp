#include <bits/stdc++.h>
using namespace std;
typedef long long tint;
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define fst first
#define snd second
#define pb push_back
#define ii pair<tint, tint>

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << (v) << endl;
#else
#define debug(v)
#endif

tint n, D;
vector<ii> v;

tint dist(ii u, ii v) {
    tint dx = v.fst - u.fst;
    tint dy = v.snd - u.snd;
    return dx * dx + dy * dy;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> D;
    v.resize(n);

    forn(i, n) { cin >> v[i].fst >> v[i].snd; }

    set<tint> bestS;

    forn(i, n) {
        forsn(j, i + 1, n) {
            forsn(k, j + 1, n) {
                tint d = max(max(dist(v[i], v[j]), dist(v[i], v[k])),
                             dist(v[j], v[k]));
                if (d > D * D) {
                    continue;
                }

                tint count = 3;
                set<tint> s;
                s.insert(i);
                s.insert(j);
                s.insert(k);

                forn(x, n) {
                    if (x == i or x == j or x == k)
                        continue;

                    if (dist(v[i], v[x]) <= d and dist(v[j], v[x]) <= d and
                        dist(v[k], v[x]) <= d) {
                        s.insert(x);
                        count++;
                    }
                }

                if (s.size() > bestS.size()) {
                    bestS = move(s);
                }
            }
        }
    }

    if (bestS.empty()) {
        forn(i, n) {
            forsn(j, i + 1, n) {
                if (dist(v[i], v[j]) <= D * D) {
                    bestS.insert(i);
                    bestS.insert(j);
                    break;
                }
            }
            if (not bestS.empty())
                break;
        }
    }

    if (bestS.empty()) {
        bestS.insert(0);
    }

    cout << bestS.size() << "\n";
    bool first = true;
    for (const auto& x : bestS) {
        if (!first)
            cout << " ";
        first = false;
        cout << (x+1);
    }
    cout << endl;

    return 0;
}
