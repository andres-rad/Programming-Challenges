#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define dforsn(i, s, n) for (tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i, n) dforsn(i, 0, n)
#define fst first
#define snd second
#define debug(v) cerr << #v << " = " << (v) << endl;
#define pb push_back

struct node {
    int dir;
    vector<int> inv;
    tint color = -1;
    int nivel;
};

struct color {
    int ciclo = -1;
    int dist;
    int tamArbol;
    int head;
};

struct ciclo {
    int tam;
};

vector<node> gr;
vector<int> vis;

vector<color> colores;
vector<ciclo> ciclos;

// --------- LCA ------------------------------

vector<vector<int>> f;
#define lg(x) (31-__builtin_clz(x))

void buildLCA() {
    int logn = lg(gr.size()) + 2;
    f = vector<vector<int>>(gr.size(), vector<int>(logn, -1));

    forn(v, gr.size()) {
        int fa = gr[v].dir;
        f[v][0] = gr[v].color == gr[fa].color ? fa : -1;
    }

    forn(k, logn-1)
        forn(i, gr.size())
            if(f[i][k] != -1)
                f[i][k+1] = f[f[i][k]][k];
}

int climb(int a, int d) {
    if(!d) return a;
    dforn(i, lg(gr[a].nivel)+1) {
        if(1 << i <= d) {
            a = f[a][i];
            d -= 1 << i;
        }
    }
    return a;
}

int lca(int a, int b) {
    if(gr[a].nivel < gr[b].nivel) {
        swap(a,b);
    }
    a = climb(a, gr[a].nivel - gr[b].nivel);

    if(a == b)
        return b;

    dforn(i, lg(gr[a].nivel) + 1) {
        if(f[a][i] != f[b][i])
            a = f[a][i], b=f[b][i];
    }

    return f[a][0];
}

// --------------------------------------------

void markCicle(int curr, int ciclo);

void findCicle(int s) {
    if (vis[gr[s].dir]) {
        ciclos.pb({0});
        markCicle(s, ciclos.size()-1);
    } else {
        vis[s] = 1;
        findCicle(gr[s].dir);
    }
}

void alturas(int curr, int alt, int col) {
    gr[curr].nivel = alt;
    gr[curr].color = col;
    colores[col].tamArbol++;
    vis[curr] = 1;

    for (auto n : gr[curr].inv) {
        if (gr[n].color == -1)
            alturas(n, alt + 1, col);
    }
}

void markCicle(int curr, int currciclo) {
    if (gr[curr].color != -1) {
        return;
    }

    colores.pb({});
    color& c = colores[colores.size()-1];
    c.ciclo = currciclo;
    c.dist = ciclos[currciclo].tam;
    c.tamArbol = 0;
    c.head = curr;

    ciclos[currciclo].tam++;

    gr[curr].color = colores.size() - 1;

    markCicle(gr[curr].dir, currciclo);
    alturas(curr, 0, gr[curr].color);
}

int main() {
    int n, q;

    while (cin >> n) {
        ciclos.clear();
        colores.clear();

        gr = vector<node>(n);
        vis = vector<int>(n, 0);

        forn(i, n) {
            int f;
            cin >> f;
            f--;

            gr[i].dir = f;
            gr[f].inv.pb(i);
        }

        forn(i, n) {
            if (not vis[i])
                findCicle(i);
        }

        buildLCA();

        int res;

        cin >> q;
        forn(i, q) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            /*
            debug(a);
            debug(b);
            debug(gr[a].color);
            debug(gr[a].color);
            debug(gr[a].nivel);
            debug(gr[b].nivel);
            */

            if (gr[a].color == gr[b].color) {
                int ca = lca(a,b);
                res = gr[a].nivel + gr[b].nivel - gr[ca].nivel * 2;

            } else if (colores[gr[a].color].ciclo == colores[gr[b].color].ciclo) {
                int fwd = abs(colores[gr[a].color].dist - colores[gr[b].color].dist);
                int bwd = ciclos[colores[gr[a].color].ciclo].tam -
                              abs(colores[gr[a].color].dist - colores[gr[b].color].dist);

                res = gr[a].nivel + gr[b].nivel + min(fwd, bwd);
            } else {
                res = -1;
            }
            cout << res << endl;
        }
    }

    return 0;
}
