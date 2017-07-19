#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long int tint;

vector<int> adj[5100][2];
//vector<int> revadj[5100];
int dp[5100][2];
bool vis[5100];
int reach;

void dfs(int v, int dir)
{
	//if(vis[v]) return;
	vis[v] = true;
	reach++;
	forn(i,adj[v][dir].size())
	{
		int w = adj[v][dir][i];
		
		if(!vis[w]) dfs(w,dir);
	}
}

int main()
{
	int a,b,m,n;
	cin >> a >> b >> n >> m;
	int u,v;
	forn(i,m)
	{
		cin >> u >> v;
		adj[u][0].pb(v);
		adj[v][1].pb(u);
	}
	forn(v,n)
	{
		memset(vis,false,sizeof(vis));
		reach = 0;
		dfs(v,0);
		dp[v][0] = reach;
		memset(vis,false,sizeof(vis));
		reach = 0;
		dfs(v,1);
		dp[v][1] = reach;
	}
	int a1 = 0; int a2 = 0; int a3 = 0;

	forn(v,n)
	{
		if((n - dp[v][0]) < a) a1++;
		if((n - dp[v][0]) < b) a2++;
		if(dp[v][1] > b) a3++;
	}

	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;

	return 0;
}
