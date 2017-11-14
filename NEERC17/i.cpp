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
#define ii pair<tint, tint>

int n, m, q, p;
vector<vector<tint>> mtx;
vector<vector<tint>> sums;
vector<vector<tint>> vis;

bool isvalid(tint i, tint j) {
    return i >= 0 and i < n and j >= 0 and j < m and mtx[i][j] != -1;
}

tint bfsCount = 0;
void bfs(tint y, tint x) {
    bfsCount++;

    queue<pair<ii, tint>> q;
    q.push({{y,x}, mtx[y][x]});
    vis[y][x] = bfsCount;
    while(q.size()) {
        auto t = q.front();
        q.pop();
        ii pos = t.fst;
        tint pow = t.snd;
        tint i = pos.fst;
        tint j = pos.snd;

        sums[i][j] += pow;
        if(pow <= 1)
            continue;

        if(isvalid(i-1,j) and vis[i-1][j] < bfsCount) {
            q.push({{i-1,j}, pow/2});
            vis[i-1][j] = bfsCount;
        }
        if(isvalid(i+1,j) and vis[i+1][j] < bfsCount) {
            q.push({{i+1,j}, pow/2});
            vis[i+1][j] = bfsCount;
        }
        if(isvalid(i,j-1) and vis[i][j-1] < bfsCount) {
            q.push({{i,j-1}, pow/2});
            vis[i][j-1] = bfsCount;
        }
        if(isvalid(i,j+1) and vis[i][j+1] < bfsCount) {
            q.push({{i,j+1}, pow/2});
            vis[i][j+1] = bfsCount;
        }
    }
}

int main() {
    cin >> n >> m >> q >> p;

    mtx = vector<vector<tint>>(n,vector<tint>(m));
    sums = vector<vector<tint>>(n,vector<tint>(m));
    vis = vector<vector<tint>>(n,vector<tint>(m));

    forn(j,n) {
        string s;
        cin >> s;
        forn(i,m) {
            if(s[i] == '*') {
                mtx[j][i] = -1;
            } else if(s[i] == '.') {
                mtx[j][i] = 0;
            } else {
                mtx[j][i] = (tint)((s[i] - 'A')+1) * q;
            }
        }
    }

    forn(j,n) {
        forn(i,m) {
            if(mtx[j][i] > 0)
                bfs(j,i);
        }
    }

    tint res = 0;
    forn(j,n) forn(i,m) {
        if(sums[j][i] > p) res++;
    }

    cout << res << endl;

    return 0;
}
