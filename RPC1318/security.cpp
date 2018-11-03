#include <bits/stdc++.h>
using namespace std;
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define dforsn(i, s, n) for (tint i = (tint)(n); i >= (tint)(s); i--)
#define dforn(i, n) dforsn(i, 0, n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ii pair<tint, tint>
typedef long long tint;

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << v << endl;
#else
#define debug(v)
#endif

void push(vector<vector<int>>& m, queue<ii>& q, tint cur, tint x, tint y) {
    if (x >= 0 and y >= 0 and x <= 5000 and y <= 5000 and m[y][x] == -1) {
        m[y][x] = cur + 1;
        q.push({x, y});
    }
}

void bfs(vector<vector<int>>& m, const vector<ii>& guards) {
    queue<ii> q;
    for (const auto& g : guards) {
        q.push(g);
    }

    while (not q.empty()) {
        tint x, y;
        tie(x, y) = q.front();
        q.pop();
        tint cur = m[y][x];

        push(m, q, cur, x - 1, y - 1);
        push(m, q, cur, x, y - 1);
        push(m, q, cur, x + 1, y - 1);
        push(m, q, cur, x - 1, y);
        push(m, q, cur, x + 1, y);
        push(m, q, cur, x - 1, y + 1);
        push(m, q, cur, x, y + 1);
        push(m, q, cur, x + 1, y + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    tint n, q;
    vector<vector<int>> m(5001, vector<int>(5001, -1));

    vector<ii> guards;

    cin >> n >> q;

    forn(i, n) {
        tint x, y;
        cin >> x >> y;
        m[y][x] = 0;
        guards.pb({x, y});
    }

    bfs(m, guards);

    forn(i, q) {
        tint x, y;
        cin >> x >> y;
        cout << m[y][x] << endl;
    }

    return 0;
}
