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

struct res{
	set<int> nums;
	vector<int> numseq;
	int ans;
}

res fun(const res& a, const res& b){
	res ans;
	set_union(a.nums.begin(), a.nums.end(),
                   b.nums.begin(), b.nums.end(),                  
                   back_inserter(ans.nums));
    merge(a.numseq.begin(), a.numseq.end(),
                   b.numseq.begin(), b.numseq.end(),                  
                   back_inserter(ans.numseq));
                   
    
    
}

struct RMQ{
	#define LVL 10 // LVL ≥ ceil(logn)
	res vec[LVL][1<<(LVL+1)];
	
	res &operator[](int p){return vec[0][p];}
	
	res get(int i, int j) {//intervalo [i,j)
		int p = 31-__builtin_clz(j-i);
		return min(vec[p][i],vec[p][j-(1<<p)]);
	}
	
	void build(int n) {//O(nlogn)
		int mp = 31-__builtin_clz(n);
		forn(p, mp) forn(x, n-(1<<p))
		vec[p+1][x] = min(vec[p][x], vec[p][x+(1<<p)]);
	}
};

int main(){

	int n,m, c;
	cin>>n>>m>>c;

	cout<<(n^m^c)<<endl;
	cout<<((~(n^m^c))^0)<<endl;

	return 0;
}
