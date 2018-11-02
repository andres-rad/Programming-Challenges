#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forsn forr
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
#define INF 1e9
typedef long long tint;
typedef pair<tint,tint> ii;

const int MAXN=100100;

/////

int main() {
    vector<vector<tint>> comb(50, vector<tint>(50));

    // init comb
    forn(i, 50) {
        comb[i][0] = comb[i][i] = 1;
        forsn(k,1,i) comb[i][k] = comb[i-1][k] + comb[i-1][k-1];
    }

    int n;

    while(cin>>n){
        int d, c;
        cin >> d >> c;

        int inter = 0;
        set<int> va;
        // A
        forn(i,c) {
            tint x;
            cin >> x;
            va.insert(x);
        }
        // B
        forn(i,c) {
            tint x;
            cin >> x;
            if(va.find(x) != va.end()) inter++;
        }

        int mine = c-inter;


        // init the matrix
        // esperanza de turnos restantes dado que ya se marcaron #A, #B, #I
        // (#A = cantidad de numeros solo del jugador A ya marcados)
        vector<vector<vector<double>>>
            mtx(mine+1, vector<vector<double>>(mine+1, vector<double>(inter+1, 0)));

        dforn(a, mine+1) {
            dforn(b, mine+1) { 
                dforn(i, inter+1) {
                    // condicion final, 0 turnos restantes
                    if(a+i == c || b+i == c) continue;

                    // cantidad de números que no hacen nada
                    int rest = n - a - b - i;

                    double result = 0;

                    // Para cada cantidad de bolitas que salgan de cada tipo
                    forn(ba, min(a, d)) {
                        forn(bb, min(b, d-ba)) {
                            forn(bi, min(i, d-ba-bb)) {
                                if(ba == 0 and bb == 0 and bi == 0) continue;

                                
                            }
                        }
                    }

                    // esta tirada
                    result += 1;

                    // tomar en cuenta cuando vuelvo al mismo caso
                }
            }
        }

        cout << mtx[0][0][0];

    }

    return 0;
}
