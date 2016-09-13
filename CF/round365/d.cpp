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
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

struct RMQ{
	#define LVL 23
	tint vec[LVL][1<<(LVL+1)];
	tint &operator[](int p){return vec[0][p];}
	tint get(int i, int j) {//intervalo [i,j)
		int p = 31-__builtin_clz(j-i);
		//return min(vec[p][i],vec[p][j-(1<<p)]);
		return (vec[p][i] ^ vec[p][j-(1<<p)]);
	}
	void build(int n) {//O(nlogn)
		int mp = 31-__builtin_clz(n);
		forn(p, mp) forn(x, n-(1<<p))
			//vec[p+1][x] = min(vec[p][x], vec[p][x+(1<<p)]);
			vec[p+1][x]= vec[p][x]^ vec[p][x+(1<<p)];
	}
};

int main(){

	int n,m, c;
	cin>>n>>m>>c;

	cout<<(n^m^c)<<endl;
	cout<<((~(n^m^c))^0)<<endl;

	return 0;
}
