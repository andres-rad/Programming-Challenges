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

unordered_map<string, int> coor;
unordered_map<int, int> Ad;

unordered_map<int, int> At;
vector<unordered_set<int>> gAd;
vector<unordered_set<int>> gAt;

//unordered_set<int> PAt;
//unordered_set<int> PAd;
//vector<int> vis;

void dfs(vector<unordered_set<int>>& g, vector<unordered_set<int>>& gAt, unordered_map<int, int>& v, unordered_map<int, int>& vAt, int node){
    debug(node);
    if (v[node] == 2){
        return;
    }
    v[node] = 2;
    for (auto h : g[node]){
        debug(h);
        dfs(gAt, g, vAt, v, h);
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    string t;
    
    string ant;
    bool teniaComa = false;
    gAt.emplace_back();
    gAd.emplace_back();
    vector<string> orac;
    while(cin>>t){
        string sinT;
        debug(t);
        if (t[t.size()-1] == ',' or t[t.size()-1] == '.'){
            sinT = t.substr(0, t.size()-1);
        }else{
            sinT = t;
        }
        debug(sinT);
        debug(coor[sinT]);
        if (coor[sinT] == 0){
            coor[sinT] = coor.size();
            gAt.emplace_back();
            gAd.emplace_back();
            debug(gAt.size());
        }
        bool tieneComa = t[t.size() -1 ] ==',';
        bool tienePunto = t[t.size() -1 ] =='.';
        
//        gAt.resize(max(gAt.size(), coor[sin
        if (ant.size() > 0){
 //           cerr << "hola" << endl;
            debug(gAt.size());
            debug(coor[sinT]);
            debug(coor[ant]);
            gAt[coor[sinT]].insert(coor[ant]);
            gAd[coor[ant]].insert(coor[sinT]);
            debug("grafo");
            debug(sinT);
            debug(ant);
   //         cerr << "cha" << endl;
        }
        
        if (tienePunto) {
            ant = "";
            
        }else {
            ant = sinT;
        }
        
        if (tieneComa) {
            Ad[coor[sinT]] = 1;
        }
        if (teniaComa){
            At[coor[sinT]] = 1;
        }
        teniaComa = tieneComa;
        
        if (tienePunto){
            orac.pb(t);
        }else{
        orac.pb(sinT);
            
        }
    }
    
    //for (auto s : orac){
      //  cerr << s << " ";
    //}
    
    for (auto n : At){
        dfs(gAt, gAd, At, Ad, n.first);
    }
    for (auto n : Ad){
        dfs(gAd, gAt, Ad, At, n.first);
    }
    
    for (auto s: orac){
        if (s[s.size()-1] == '.'){
            cout << s << " ";
        }else{
            if (Ad[coor[s]] == 2){
                cout << s << ", ";
            }else{
                cout << s << " ";
            }
        }
    }
    cout << endl;
        
    
    return 0;
}
