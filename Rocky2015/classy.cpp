#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <functional>

using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair

//UNION FIND
vector<int> _cl;
int cl(int i) { return (_cl[i] == -1 ? i : _cl[i] = cl(_cl[i])); }
void join(int i, int j) { if(cl(i)!=cl(j)) _cl[cl(i)] = cl(j); }
void ini(int n) { _cl.clear(); _cl.insert(_cl.begin(), n, -1); }

bool micomp(pair<vector<int>, char[]> a, pair<vector<int>, char[]> b){
	

}
int main () {

	int n;
	while (cin>>n){
		priority_queue <pair<vector<int>, char[]>, vector<pair<vector<int>, char[]>, micomp > people;
	}
	return 0;
}
