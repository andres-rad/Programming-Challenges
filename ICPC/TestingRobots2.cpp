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

int main () {

	return 0;
}
