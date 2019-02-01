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

const tint maxN = 501;

struct data {
    tint res;
    tint rSob;
    tint bSob;
    tint rNew;
    tint bNew;
    bool fatherB;
};

vector<vector<data>> dp;

bool isInSet(tint r, tint b, tint currR, tint currB) {
    if (currR == 0 and currB == 0)
        return false;
    if (r == 0 and b == 0)
        return false;

    const data d = dp[currR][currB];
    if (d.rNew == r and d.bNew == b)
        return true;

    tint nextR = d.fatherB ? currR : currR - 1;
    tint nextB = d.fatherB ? currB - 1 : currB;
    return isInSet(r, b, nextR, nextB);
}

void mkDP(tint r, tint b) {
    if (r == 0 and b == 0)
        return;

    const data fR = r > 0 ? dp[r - 1][b] : data{};
    const data fB = b > 0 ? dp[r][b - 1] : data{};

    // Father R
    if (r > 0 and fR.res >= fB.res) {
        if (not isInSet(fR.rSob + 1, fR.bSob, r - 1, b)) {
            dp[r][b] = {
                fR.res + 1, 0, 0, fR.rSob + 1, fR.bSob, false,
            };
            return;
        }
    }

    // Father B
    if (b > 0 and fB.res >= fR.res) {
        if (not isInSet(fB.rSob, fB.bSob + 1, r, b - 1)) {
            dp[r][b] = {
                fB.res + 1, 0, 0, fB.rSob, fB.bSob + 1, true,
            };
            return;
        }
    }

    // Default (no new juggler)
    if (r > 0 and fR.res >= fB.res) {
        dp[r][b] = {
            fR.res, fR.rSob + 1, fR.bSob, 0, 0, false,
        };
    } else {
        dp[r][b] = {
            fB.res, fB.rSob, fB.bSob + 1, 0, 0, true,
        };
    }
}

void debugDP(tint r, tint b) {
    const data d = dp[r][b];
    cerr << r << "," << b << ": " << d.res
        << " sob:" << d.rSob << "," << d.bSob
        << " new:" << d.rNew << "," << d.bNew
        << " father:" << (d.fatherB ? "B" : "R")
        << "\n";
}

void debugSet(tint r, tint b) {
    cerr << "Set for " << r << "," << b << ":\n";

    while (r > 0 or b > 0) {
        const data d = dp[r][b];
        if (d.rNew > 0 or d.bNew > 0)
            cerr << "  " << d.rNew << "," << d.bNew << "\n";

        if(b > 0 and d.fatherB)
            b--;
        else
            r--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    tint tests = 0;
    cin >> tests;

    dp = vector<vector<data>>(maxN, vector<data>(maxN));
    dp[0][0] = {0, 0, 0, 0, 0, false};

    forsn(sum, 1, 2 * maxN - 1) {
        forn(r, min(maxN, sum + 1)) {
            if (sum - r >= maxN)
                continue;
            mkDP(r, sum - r);

            const data d = dp[r][sum-r];
        }
    }

    forsn(t, 1, tests + 1) {
        tint r, b, res;
        cin >> r >> b;
        res = dp[r][b].res;
        cout << "Case #" << t << ": " << res << "\n";
    }

    /*/ Print grilla
    forn(b, 30) {
        forn(r, 30) {
            cerr << setw(2) << dp[r][b].res << " ";
        }
        cerr << "\n";
    }/**/

    /*/ Check symmetry
    forn(b, maxN) {
        forn(r, maxN) {
            if(dp[r][b].res != dp[b][r].res) {
                cerr << r << "," << b << "\n";
                assert(dp[r][b].res == dp[b][r].res);
            }
        }
    }
    /**/

    debugDP(26,9);
    debugSet(26,9);
    debugDP(9,26);
    debugSet(9,26);

    return 0;
}
