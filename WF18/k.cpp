#include <bits/stdc++.h>
using namespace std;
typedef long long tint;
#define forsn(i,s,n) for(tint i=(tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define dforsn(i,s,n) for(tint i=(tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
typedef pair<tint,tint> ii;

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    tint n, m, a, b;
    tint min_pos = 0;
    cin >> n >> m;
    
    vector<ii> grado(n);
    
    forn(i, n) {
        grado[i].fst=0; 
        grado[i].snd = i;
    }

    forn(i, m) {
        cin >> a >> b;
        grado[a].fst++;
        grado[b].fst++;
        //debug(a); debug(b); debug(grado[a].fst);
    }
    
    sort(grado.begin(), grado.end());
    
    dforn(i, n) {
        grado[i].fst--;
        if(grado[i].fst > 0) {
            min_pos = i;
        }
    }
    
    tint n_grado = n-1;
    
    vector<ii> grado_arbol(n);
    forn(i, n) {
        grado_arbol[i].fst= 1; 
        grado_arbol[i].snd = i;
    }
    
    tint tot = 0;
     
    while(n_grado > 0 && min_pos < n) {
    
      if(grado[min_pos].fst > n_grado) {
        grado_arbol[grado[min_pos].snd].fst += n_grado;
        break;
      }
      
      n_grado -= grado[min_pos].fst;
      grado_arbol[grado[min_pos].snd].fst += grado[min_pos].fst;
      
      min_pos++;
    }
    
    
    cout << n - min_pos << endl;
    cout << n << " " << n-1 << endl;
    
    sort(grado_arbol.begin(), grado_arbol.end());
    
    //forn(i, n){ debug(grado_arbol[i].fst); debug(grado_arbol[i].snd)}
    
    min_pos = n-2;
    dforn(i, n) {
        dforsn(j, min_pos  - grado_arbol[i].fst + 1, min_pos + 1) {
            cout << grado_arbol[j].snd << " " << grado_arbol[i].snd << endl;
            grado_arbol[j].fst--;
        }
        min_pos -= grado_arbol[i].fst;
    }
    return 0;
}
