#include <bits/stdc++.h>
using namespace std;
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n); i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long tint;

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << v << endl;
#else
#define debug(v)
#endif


#define MAX_V 1800
#define INF 1e9
#define SRC 0
#define SNK 1

vector<map<int, int>> G;//limpiar esto

//To add an edge use
void add(int v, int u, int w) {
    G[v][u] = w;
}

int f;
vector<int> p;
void augment(int v, int minE){
    if(v==SRC) f=minE;
    else if(p[v]!=-1){
        augment(p[v], min(minE, G[p[v]][v]));
        G[p[v]][v]-=f, G[v][p[v]]+=f;
    }
}

tint maxflow(){//O(VE^2)
    tint Mf=0;
    do{
        f=0;
        vector<char> used(MAX_V);
        queue<int> q;
        q.push(SRC);
        p = vector<int>(MAX_V, -1);
        while(q.size()){
            int u=q.front();
            q.pop();
            if(u==SNK) break;
            for(auto el : G[u])
                if(el.snd>0 && !used[el.fst]) {
                    used[el.fst]=true;
                    q.push(el.fst);
                    p[el.fst]=u;
                }
        }
        augment(SNK, INF);
        Mf+=f;
    } while(f);
    return Mf;
}

int n, match, games;

int vE(tint equipo) {
    return equipo-1 + 2;
}

int vM(tint equipo1, tint equipo2) {
    if(equipo1 > equipo2)
        swap(equipo1, equipo2);
    return 2 + (n-1) + (equipo1-1) * (n-1) + (equipo2-1);
}

int main() {
   //ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> n >> match >> games){
        if(n == 0) break;

        vector<vector<int>> played(n, vector<int>(n));
        vector<int> points(n);

        tint nodes = 2 + (n-1) + n * (n-1) + (n-1);

        G = vector<map<int,int>>(nodes);

        tint mypoints = 2 * match * (n-1);

        forn(g,games) {
            int i,j;
            char c;
            cin >> i >> c >> j;

            if(i == 0 or j == 0) {
                if(i == 0) {
                    if(c == '<') {
                        points[j] += 2;
                        mypoints -= 2;
                    } else if (c == '>') {
                        //
                    } else {
                        points[j] += 1;
                        mypoints -= 1;
                    }
                } else {
                    if(c == '<') {
                        //
                    } else if (c == '>') {
                        points[i] += 2;
                        mypoints -= 2;
                    } else {
                        points[i] += 1;
                        mypoints -= 1;
                    }
                }
            } else {
                played[min(i,j)][max(i,j)]++;

                if(c == '<')
                    points[j] += 2;
                else if (c == '>')
                    points[i] += 2;
                else {
                    points[j] += 1;
                    points[i] += 1;
                }
            }
        }

        // crear grafo

        // partidos
        tint target = 0;
        forsn(i,1,n) {
            forsn(j,i+1,n) {
                int play = played[i][j];
                if(play == match) continue;
                int w = (match - play) * 2;

                add(SRC, vM(i,j), w);
                target += w;

                add(vM(i,j), vE(i), w);
                add(vM(i,j), vE(j), w);
            }
        }

        // equipos
        bool fail = false;
        forsn(i, 1, n) {
            int quedan = mypoints - 1 - points[i];

            if(quedan < 0) {
                fail = true;
                break;
            }

            add(vE(i), SNK, quedan);
        }

        if(fail) {
            cout << "N" << endl;
            continue;
        }

        // correr
        tint res = maxflow();

        debug(res);
        debug(target);

        cout << (res == target ? "Y" : "N") << endl;
    }

    return 0;
}
