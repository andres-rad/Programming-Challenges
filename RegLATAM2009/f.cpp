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





/* Suffix tree sacado de aca
    http://codeforces.com/blog/entry/17956
    No es tan rapido como Ukkonen pero es mas sencillo
*/

const int MAXLEN = 112345;
std::string s;
int pos[MAXLEN], len[MAXLEN], par[MAXLEN];
std::map<char,int> to[MAXLEN], link[MAXLEN];
int sz = 2;
int path[MAXLEN];
using namespace std;
void init(){
	sz = 2;
	forn(i, MAXLEN){
		to[i].clear();
		path[i] = pos[i] = len[i] = par[i] = 0;

		link[i].clear();
	}

	len[1] = 1; pos[1] = 0; par[1] = 0;
	len[0] = 0;
	pos[0] = 0;
	for (int c = 0; c <= 255; c++)
			link[0][c] = 1;
}
void attach(int child, int parent, char c, int child_len)
{
        to[parent][c] = child;
        len[child] = child_len;
        par[child] = parent;
}
void extend(int i)
{
        int v, vlen = s.size() - i, old = sz - 1, pstk = 0;
        for (v = old; !link[v].count(s[i]); v = par[v]) {
                vlen -= len[v];
                path[pstk++] = v;
        }
        int w = link[v][s[i]];
        if (to[w].count(s[i + vlen])) {
                int u = to[w][s[i + vlen]];
                for (pos[sz] = pos[u] - len[u]; s[pos[sz]] == s[i + vlen]; pos[sz] += len[v]) {
                        v = path[--pstk];
                        vlen += len[v];
                }
                attach(sz, w, s[pos[u] - len[u]], len[u] - (pos[u] - pos[sz]));
                attach(u, sz, s[pos[sz]], pos[u] - pos[sz]);
                w = link[v][s[i]] = sz++;
        }
        link[old][s[i]] = sz;
        attach(sz, w, s[i + vlen], s.size() - (i + vlen));
        pos[sz++] = s.size();
}

tint res;

int dfs(int cur, int acum){
	int hojas = 0;
	bool todosHojas = true;
	for(auto n : to[cur]){
		int next = dfs(n.snd, acum + len[cur]);//o len[n.snd]
		todosHojas = todosHojas && (next == 1);
		hojas += next;
	}
	if (hojas == 0) hojas++;
	debug(hojas);
	if (hojas > 1 and todosHojas){
		res += (acum*(acum+1))/2;
	}
	return hojas;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//string disk;
	while (cin >> s){
		if (s == "*") break;
		res = 0;
		init();
		for (int i = s.size() - 1; i >= 0; i-- ){
			extend(i);
		}

		/*
		forn(i, 6){
			debug(i);
			debug(to[i].size());
			debug(len[to[i]['a']]);
		}
		*/
		dfs(1, 0);

		cout << res << endl;


	}


	return 0;
}
