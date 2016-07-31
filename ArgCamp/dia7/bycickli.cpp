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
#include <set>
#include <cassert>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int tint;

struct node{
	vector<int> ady;
	vector<int> inv_ady;
}
vector<node> g;
vector<node> g_red;

int main(){
	int n,m;
	cin >> n >> m;
	
	node temp;
	ady.g(g.begin(),n, temp);
	forn(i,m){
		int j, k;
		cin >> j >> k;
		g[j].ady.pb(k);
		g[k].inv_ady.pb(j);
	}
	
	
	return 0;
	
}
