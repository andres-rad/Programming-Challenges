#include <bits/stdc++.h>
using namespace std;
typedef long long tint;
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define fst first
#define snd second
#define pb push_back

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << (v) << endl;
#else
#define debug(v)
#endif

tint toInd(char c) { return c - 'a'; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    tint n;
    cin >> n;

    vector<vector<string>> opts(n);

    forn(i, n) {
        tint m;
        cin >> m;
        opts[i].resize(m);
        forn(j, m) { cin >> opts[i][j]; }
    }

    vector<vector<tint>> res(n, vector<tint>(n, -1));

    forn(fin, n) {
        res[fin][fin] = 0;

        bool algoCambio = true;
        tint currDist = 1;
        while (algoCambio) {
            algoCambio = false;
            forn(start, n) {
                if (res[start][fin] != -1) continue;

                bool hayBuenaOpcion = false;

                for (const auto& opt : opts[start]) {
                    tint newDist = -1;
                    bool allMakeMeWin = true;

                    // Checkeo que todos los caminos del set me hagan ganar
                    for (char c : opt) {
                        tint distC = res[toInd(c)][fin];
                        if (distC == -1 or distC >= currDist) {
                            allMakeMeWin = false;
                            break;
                        }
                    }

                    if (allMakeMeWin) {
                        hayBuenaOpcion = true;
                    }
                }

                if(hayBuenaOpcion) {
                    res[start][fin] = currDist;
                    algoCambio = true;
                }
            }
            currDist += 1;
        }
    }

    for (const auto& row : res) {
        bool first = true;
        for (auto x : row) {
            if (not first)
                cout << " ";
            first = false;
            cout << x;
        }
        cout << endl;
    }

    return 0;
}
