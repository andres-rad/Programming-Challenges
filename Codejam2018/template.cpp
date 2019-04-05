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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    tint tests = 0;
    cin >> tests;

    forsn(t, 1, tests + 1) {
        tint res=0;

        cout << "Case #" << t << ": " << res << "\n";
    }

    return 0;
}
