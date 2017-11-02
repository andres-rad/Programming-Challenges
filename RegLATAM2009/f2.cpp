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
	http://codeforces.com/blog/entry/16780
    No es tan rapido como Ukkonen pero es mas sencillo
*/
#include <bits/stdc++.h>

using namespace std;


#define fpos adla
const int inf = 1e9;
const int maxn = 202345;
char s[maxn]; // El string
map<int, int> to[maxn];
int len[maxn], fpos[maxn], link[maxn];
int node, pos;
int sz = 1, n = 0;


void init(){

    forn(i, maxn){
        to[i].clear();
        //len[i] = fpos[i] = link[i] = 0;

    }
    node = pos = 0;
    sz = 1;
    n = 0;
    len[0] = inf;
}

int make_node(int _pos, int _len)
{
    fpos[sz] = _pos;
    len [sz] = _len;
    return sz++;
}

void go_edge()
{
    while(pos > len[to[node][s[n - pos]]])
    {
        node = to[node][s[n - pos]];
        pos -= len[node];
    }
}

void add_letter(int c)
{
    debug(c);
    s[n++] = c;
    pos++;
    int last = 0;
    while(pos > 0)
    {
        go_edge();
        int edge = s[n - pos];
        int &v = to[node][edge];
        int t = s[fpos[v] + pos - 1];
        if(v == 0)
        {
            v = make_node(n - pos, inf);
            link[last] = node;
            last = 0;
        }
        else if(t == c)
        {
            link[last] = node;
            return;
        }
        else
        {
            int u = make_node(fpos[v], pos - 1);
            to[u][c] = make_node(n - 1, inf);
            to[u][t] = v;
            fpos[v] += pos - 1;
            len [v] -= pos - 1;
            v = u;
            link[last] = u;
            last = u;
        }
        if(node == 0)
            pos--;
        else
            node = link[node];
    }
}

int search(string k){
	int cur = 0;
	bool encontrado = true;
	int visto = 0;
	while (encontrado and visto < k.size()){
		if (encontrado = encontrado and to[cur].find(k[visto]) != to[cur].end()){
			cur = to[cur][k[visto]];
			forsn(i, fpos[cur], len[cur] + fpos[cur]){
				if (visto == k.size()) return cur;
				if (k[visto++] != s[i]) return -1;
			}
			/*
			if (k.compare(visto, len[cur], s, fpos[cur], len[cur]) != 0){
				return false;
			}
			visto += len[cur];
			*/
		}
	}
	return cur;
}
/*
int main()
{
    len[0] = inf;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
        add_letter(s[i]);
    for(int i = 1; i < sz; i++)
        ans += min((int)s.size() - fpos[i], len[i]);
    cout << ans << "\n";

	debug(search("aaa"));
	forn(i, 13){
		debug(i);
		debug(to[i]['a']);
		debug(len[i]);
		debug(fpos[i]);

	}
}
*/

tint res;
string ss;


pair<int, int> dfs(int cur = 0, int acum = 0){
    //debug(cur);
    //debug(len[cur]);
    if (len[cur] > maxn and cur != 0){
        pair<int, int> res {1, 0};
        return res;
    }

	int hojas = 0;
    int contados = 0;
	bool todosHojas = true;
	for(const auto&  n : to[cur]){
        //debug((char)n.fst);
		pair<int, int> next = dfs(n.snd, (len[n.snd] > maxn ? ss.size() - 1 : acum + len[n.snd]));//o len[n.snd]

		todosHojas = todosHojas && (next.fst == 1);
		hojas += next.fst;
        contados += next.snd;
	}
	//if (hojas == 0) hojas++;
    /*
    debug(cur);
    debug(hojas);
    debug(todosHojas);
    debug(acum);
    */
	if (hojas > 1 and todosHojas){
		res += acum;
        contados++;
	}else if (contados > 1){
        res -= (contados - 1)*acum;
        contados = 1;
    }
	return make_pair(hojas, contados);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//string disk;
    //string ss;
	while (cin >> ss){
		if (ss == "*") break;
        ss += '#';
		res = 0;
		init();
        for(int i = 0; i < ss.size(); i++){
            //debug(ss[i]);
            add_letter(ss[i]);
        }


		/*
		forn(i, 6){
			debug(i);
			debug(to[i].size());
			debug(len[to[i]['a']]);
		}*/

		dfs();
        /*
        forn(i, 25){
    		debug(i);
            debug(to[i]['m']);
            debug(to[i]['i']);
            debug(to[i]['s']);
            debug(to[i]['p']);
    		debug(to[i]['#']);
    		debug(len[i]);
    		debug(fpos[i]);

    	}
        */

		cout << res << endl;


	}


	return 0;
}
