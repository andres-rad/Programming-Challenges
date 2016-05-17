#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back

char mus[1010][1010];
int vis[1010][1010];
int n,m,k,curr;
vector <int> ind;



// WNES
int dx[4] = { 0,-1,0,1};
int dy[4] = {-1, 0,1,0};

bool valid(int a, int b)
{
	bool ans = (mus[a][b] == '.');
	// and (0 <= a and a < n) and (0 <= b and b < m);
	return (ans);
}


void dfs(int a, int b)
{
	vis [a][b]=curr;
	forn (i,4){
		
		if (!valid(a+dx[i],b+dy[i])){
			ind [curr] ++;

		}
		else if (!vis[a+dx[i]][b+dy[i]]) dfs (a+dx[i],b+dy[i]);
		
	}
	
}

int main()
{
	char bas;
	ind.pb(0);
	curr=1;
	scanf("%d %d %d \n", &n, &m, &k);
	forn(i,n)
	{
		forn(j,m)
		{
			scanf("%c",&mus[i][j]);
			//cout << mus[i][j] << endl;
			//cin >> mus[i][j];
		}
		scanf("%c",&bas);
	}
	
	forn(i,n)
	{
		forn(j,m)
		{
			if((!vis[i][j])&&(valid(i,j)))
			{
				ind.pb(0);
				dfs(i,j);
				curr++;
				
			}
		}
	}


	forn (i,k){
		int x,y;
		//cin >>x>>y;
		scanf("%d %d", &x, &y);
		//cout<< x<<" "<< y<<endl;
		//cout<<ind[vis[x-1][y-1]]<<endl;
		printf("%d \n", ind[vis[x-1][y-1]]);
	}


	return 0;
}
