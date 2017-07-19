#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define addor(a, b) (G[neg(a)].pb(b), G[neg(b)].pb(a))

using namespace std;
typedef long long int tint;
typedef pair<int,int> par;

vector<int> G[4*30];
//idx[i]=index assigned in the dfs
//lw[i]=lowest index(closer from the root) reachable from i
int lw[4*30], idx[4*30], qidx;
stack<int> q;
int qcmp, cmp[4*30];
//verdad[cmp[i]]=valor de la variable i
bool verdad[4*30];
int n = 52;

int neg(int x)
{
	return x>=n? x-n : x+n;
}
void tjn(int v)
{
	lw[v]=idx[v]=++qidx;
	q.push(v), cmp[v]=-2;
	
	for(vector<int>::iterator it = G[v].begin(); it != G[v].end(); it++)
	{
		if(!idx[*it] || cmp[*it]==-2)
		{
			if(!idx[*it]) tjn(*it);
			lw[v]=min(lw[v], lw[*it]);
		}
	}
	if(lw[v]==idx[v])
	{
		int x;
		do
		{
			x=q.top(); q.pop(); cmp[x]=qcmp;
		} while(x!=v);
		verdad[qcmp]=(cmp[neg(v)]<0);
		qcmp++;
	}
}

bool satisf()
{
	memset(idx, 0, sizeof(idx)), qidx=0;
	memset(cmp, -1, sizeof(cmp)), qcmp=0;
	forn(i, n)
	{
		if(!idx[i]) tjn(i);
		if(!idx[neg(i)]) tjn(neg(i));
	}
	forn(i, n) if(cmp[i]==cmp[neg(i)]) return false;
	return true;
}


int main()
{
	int N;
	cin >> N;
	vector<par> inv(55);
	vector<int> pl(55);
	vector<int> ans(55);
	string s; int j,r;
	
	forn(i,N)
	{
		cin >> s >> j >> r;
		int a1 = (int)(s[0] - 'A');
		int a2 = (int)(s[1] - 'A');
		inv[i] = (mp(a1,a2));
		pl[i] = j;
		ans[i] = r;
	}

	int res = 0;

	forn(a,26)
	{
		forsn(b,a+1,26)
		{
			forsn(c,b+1,26)
			{
				forn(u,4*30) G[u].clear();

				forn(i,N)
				{
					if(pl[i] == 1)
					{
						if(ans[i] == 0)
						{
							addor(neg(inv[i].f),neg(inv[i].s));
							addor(neg(inv[i].f),inv[i].s);
							addor(inv[i].f,neg(inv[i].s));
						}
						if(ans[i] == 1)
						{
							addor(inv[i].f,inv[i].s);
							addor(neg(inv[i].f),neg(inv[i].s));
						}
						if(ans[i] == 2)
						{
							addor(inv[i].f,inv[i].s);
							addor(inv[i].f,neg(inv[i].s));
							addor(neg(inv[i].f),inv[i].s);
						}
					}
					else
					{
						if(ans[i] == 0)
						{
							addor(neg(inv[i].f + 26),neg(inv[i].s + 26));
							addor(neg(inv[i].f + 26),inv[i].s + 26);
							addor(inv[i].f + 26,neg(inv[i].s + 26));
						}
						if(ans[i] == 1)
						{
							addor(inv[i].f + 26,inv[i].s + 26);
							addor(neg(inv[i].f + 26),neg(inv[i].s + 26));
						}
						if(ans[i] == 2)
						{
							addor(inv[i].f + 26,inv[i].s + 26);
							addor(inv[i].f + 26,neg(inv[i].s) + 26);
							addor(neg(inv[i].f + 26),inv[i].s + 26);
						}
					}
				}
				forn(i,26)
					addor(neg(i),neg(i+26));
				forn(i,26)
				{
					if(i == a or i == b or i == c) continue;
					addor(i,i+26);
				}
				addor(neg(a),neg(a)); addor(neg(b),neg(b)); addor(neg(c),neg(c));
				addor(neg(a+26),neg(a+26)); addor(neg(b+26),neg(b+26)); addor(neg(c+26),neg(c+26));
			
				if(satisf()) res++;
				/*else
				{
					cout << (char)('A' + a) << " " << (char)('A' + b) << " " << (char)('A' + c) << endl;
				}*/
			}
		}
	}
	
	cout << res << endl;

	return 0;
}
