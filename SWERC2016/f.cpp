#include <bits/stdc++.h>
#define dprint(v) cout << #v"=" << v << endl //;)
#define forsn(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1e9


using namespace std;
typedef long long int tint;
typedef pair<int,int> par;

vector<int> adj[100100];
par ranks[100100];
tint ti[100100];
bool vis[100100];
int path[200200];
int open[100100];
int close[100100];
tint st[800100];
tint ans[100100];
int ind;

void update(int node, int l, int r, int pos, tint val)
{
	if(r <= l) return;
	if(r <= pos) return;
	if(pos < l) return;
	if((r - l) == 1)
	{
		st[node] = val;
		return;
	}

	int m = (l + r) / 2;
	update(2*node, l, m, pos, val);
	update(2*node+1, m , r, pos, val);

	st[node] = st[2*node] + st[2*node+1];
}

tint query(int node, int l, int r, int a, int b)
{
	if(r <= a or b <= l) return 0;
	if(a <= l and r <= b) return st[node];

	int m = (l + r) / 2;
	tint s1 = query(2*node, l, m, a, b);
	tint s2 = query(2*node+1, m, r, a, b);

	return (s1 + s2);
}

void dfs(int v)
{
	vis[v] = true;
	path[ind] = v;
	open[v] = ind;
	ind++;
	forn(i, adj[v].size())
	{
		int w = adj[v][i];
		if(!vis[w]) dfs(w);
	}
	path[ind] = v;
	close[v] = ind;
	ind++;
}

int main()
{
	int e;
	int r,m,t;
	int root;
	//freopen("test.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin >> e)
	{
		forn(i,e+1) adj[i].clear();
		ind = 0; //memset(st, 0, sizeof(st));
		zero(st);
		forsn(i,1,e+1)
		{
			vis[i] = false;
			cin >> m >> r >> t;
			if(m != -1) adj[m].pb(i), adj[i].pb(m);
			else root = i;
			ranks[i-1] = mp(r,i);
			ti[i] = t;
		}
		dfs(root);
		sort(ranks, ranks+e);
		int a = 0;
		while(a < e)
		{
			par p = ranks[a];
			a++;
			vector<par> upd; upd.pb(p);
			while(a < e and ranks[a].f == p.f)
			{
				upd.pb(ranks[a]);
				a++;
			}

			forn(i,upd.size())
			{
				int v = upd[i].s;
				//cout << v << " " << open[v] << " " << close[v] << endl;
				ans[v] = query(1,0,2*e,open[v],close[v]+1);
			}

			forn(i,upd.size())
				update(1,0,2*e,open[upd[i].s],ti[upd[i].s]);
		}

		forsn(i,1,e+1) cout << ans[i] << endl;
	}

	return 0;
}