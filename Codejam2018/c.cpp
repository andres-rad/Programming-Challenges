#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define sq(x) ((x) * (x))
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define EPS 1e-10

using namespace std;
typedef pair<int,int> par;
typedef long long int tint;

int a[110][110];
int out_match[220]; int in_match[220];
vector<int> grafo[220];

int find_match(int source)
{
	int from[300], u, match;
	memset(from, -1, sizeof(from));

	//cout << "FUENTE " << source << endl;

	from[source] = source;
	queue<int> q;
	q.push(source);
	bool found_path = false;
	while (!found_path and !q.empty())
	{
		u = q.front(); q.pop();
		forn(i, grafo[u].size())
		{
			match = grafo[u][i];
			int next = in_match[match];
			if (u != next)
			{
				if (next == -1)
				{
					found_path = true;
					break;
				} 
				if (from[next] == -1) {
					q.push(next);
					from[next] = u;
				}
			}
		}
	}

	if (!found_path) return 0;

	while (from[u] != u) {
		int aux = out_match[u];
		out_match[u] = match;
		in_match[match] = u;
		u = from[u];
		match = aux;
	}

	out_match[u] = match;
	in_match[match] = u;

	return 1;
}

int get_match(int n)
{
	int m = 0;
	forn(i,n) m += find_match(i);

	return m;
}

int main()
{
	int t, n;

	cin >> t;

	forsn(caso,1,t+1)
	{
		int ans = 0;
		cin >> n;
		forn(i,n)
		{
			forn(j,n)
			{
				cin >> a[i][j];
			}
		}

		forsn(c,-n,n+1)
		{
			int tot = 0;
			forn(i,n)
			{
				forn(j,n)
				{
					if(a[i][j] == c)
					{
						tot++;
						grafo[i].pb(n+j);
						grafo[n+j].pb(i);
					}
				}
			}

			if(tot)
			{
				memset(out_match, -1, sizeof(out_match));
				memset(in_match, -1, sizeof(in_match));
				int m = get_match(n);
				forn(k,2*n+1) grafo[k].clear();
				ans += (tot - m);
				//cout << c << " " << m << " " << tot << endl;
			}
		}

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}