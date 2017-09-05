#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <stack>
#include <set>
#include <map>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define EPS 1e-9

using namespace std;

typedef pair<int,int> par;

bool vis[610][610];
bool can[610][610][4];
int n;

int dx[4] = { 0,-1,0,1};
int dy[4] = {-1, 0,1,0};

bool valid(int a, int b)
{
	return (a >= 1 and b >= 1 and a <= 2*n and b <= (2*n+1));
}

void bfs(par v)
{
	vis[v.x][v.y] = true;
	queue<par> Q;
	Q.push(v);
	par cur, next;

	while(!Q.empty())
	{
		cur = Q.front(); Q.pop();
		forn(k,4)
		{
			next = mp(cur.x + dx[k], cur.y + dy[k]);
			if(valid(next.x, next.y) and !vis[next.x][next.y] and can[cur.x][cur.y][k])
			{
				vis[next.x][next.y] = true;
				Q.push(next);
			}
		}
	}
}

int main()
{
	char c;
	while(cin >> n)
	{
		forsn(i,1,2*n+1)
		{
			forsn(j,1,2*n+2)
			{
				vis[i][j] = false;

				forn(k,4)
				{
					int ii = i + dx[k];
					int jj = j + dy[k];

					if(valid(ii,jj)) can[i][j][k] = true;
				}
			}
		}

		forsn(i,1,2*n)
		{
			forsn(j,1,n+1)
			{
				cin >> c;

				if(c == 'V')
				{
					if(i & 1)
					{
						can[i][2*j-1][2] = false;
						can[i][2*j][0] = false;
						can[i+1][2*j-1][2] = false;
						can[i+1][2*j][0] = false;
					}
					else
					{
						can[i][2*j][2] = false;
						can[i][2*j+1][0] = false;
						can[i+1][2*j][2] = false;
						can[i+1][2*j+1][0] = false;
					}
				}
				else
				{
					// 'H'
					if(i & 1)
					{
						can[i][2*j-1][3] = false;
						can[i][2*j][3] = false;
						can[i+1][2*j-1][1] = false;
						can[i+1][2*j][1] = false;
					}
					else
					{
						can[i][2*j][3] = false;
						can[i][2*j+1][3] = false;
						can[i+1][2*j][1] = false;
						can[i+1][2*j+1][1] = false;
					}
				}
			}
		}

		int comp = 0;

		forsn(i,1,2*n+1)
		{
			forsn(j,1,2*n+2)
			{
				if(!vis[i][j])
				{
					comp++;
					//cout << "componente # " << comp << " : " << endl;
					bfs(mp(i,j));
				}
			}
		}

		cout << comp - 1 << endl;
	}

	return 0;
}