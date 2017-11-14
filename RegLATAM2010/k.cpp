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

struct UnionFind{
	unordered_map<int,int> f;//the array contains the parent of each node
	int cnt = 0;
	int comp(int x){
		if(f.find(x) == f.end()) 
			return x;
		else
			f[x] = comp(f[x]);
			return f[x];
	}//O(1)

	bool join(int i, int j) {
		bool con = comp(i)==comp(j);
		if(!con){
			cnt++;
			f[comp(i)] = comp(j);
		}
		return con;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	tint k,w;
	while(cin >> k >> w) {
		if(k == 0) break;
		bool res = true;
		unordered_map<int, int> deg;
		UnionFind uf;

		set<pair<int, int> > seen;
		unordered_set<int> vistos;
		forn(i, w){
			int a, b;
			cin >> a >> b;
			int c = min(a, b);
			b = max(a, b);
			a = c;
			vistos.insert(a);
			vistos.insert(b);
			if (res and seen.find({a, b}) == seen.end()){
				seen.insert({a,b });
				if (deg[a] == 2 or deg[b] == 2){
					res = false;
				}else if ((deg[a] == 1 and deg[b] == 1) and uf.comp(a) == uf.comp(b)) {
					res = res and (vistos.size() == k and uf.cnt == k - 1);
					if (res){
						deg[a]++;
						deg[b]++;
					}
					// falta ver si es la ultima
				}else{
					uf.join(a, b);
					deg[a]++;
					deg[b]++;
				}
			}
		}
		cout << (res ? 'Y' : 'N') << endl;
	}

	return 0;
}