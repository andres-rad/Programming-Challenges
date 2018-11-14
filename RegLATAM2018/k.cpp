#include <bits/stdc++.h>
using namespace std;
typedef long long tint;
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << (v) << endl;
#else
#define debug(v)
#endif

void reduceV(vector<tint>& v, tint d, bool up, bool down) {
    if (v.size() <= 1)
        return;

    vector<bool> used(v.size() / 2, false);
    tint pt = 0;

    tint i = 0;
    tint j = 1;

    while (i < v.size()) {
        used[i] = true;
        used[j] = true;

        // Pair matched

        if (up) {
            v[pt] = v[i];
            pt++;
        } else {
            v[pt] = v[j];
            pt++;
        }

        // avanzar
        while (i < v.size() and used[i]) {
            i++;
        }
        if (i >= v.size())
            break;
        while (j < v.size() and (i >= j or v[j] < v[i] + d or used[j])) {
            j++;
        }
        if (j >= v.size())
            break;
    }

    v.resize(v.size() / 2);

    if (up and down and d > 0) {
        reduceV(v, d, false, true);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    tint nn;
    cin >> nn;
    tint n = 1 << nn;
    vector<tint> v(n);
    forn(i, n) { cin >> v[i]; }
    sort(v.begin(), v.end());

    multiset<tint> res;
    while (v.size() > 1) {
        vector<bool> used(v.size(), false);

        tint d = v[1] - v[0];

        tint i = 0;
        tint j = 1;

        bool up = false;
        bool down = false;

        while (i < v.size()) {
            used[i] = true;
            used[j] = true;

            // Pair matched

            if (v[i] == 0) {
                up = true;
            }
            if (v[j] == 0) {
                up = true;
            }

            // Pair matched
            if (v[i] > 0 and v[j] > 0)
                break;

            // avanzar
            while (i < v.size() and used[i]) {
                i++;
            }
            if (i >= v.size())
                break;
            while (j < v.size() and (i >= j or v[j] < v[i] + d or used[j])) {
                j++;
            }
            if (j >= v.size())
                break;
        }

        if (up)
            res.insert(d);
        if (down and d != 0)
            res.insert(-d);

        reduceV(v, d, up, down);
    }

    tint resCnt = res.size();
    tint num = 0;
    for(auto x : res) {
        num++;
        cout << x;
        if(num < resCnt)
            cout << " ";
    }
    cout << endl;

    return 0;
}
