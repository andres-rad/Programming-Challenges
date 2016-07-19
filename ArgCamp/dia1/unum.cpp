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
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;




int main(){
	

	set<tint> s;
	s.insert(1);
	tint i=0;
	vector<tint> ss;

	
	while (ss.size()<1500){
		tint next = *(s.begin());
		s.erase(s.begin());
		s.insert(next*2);
		s.insert(next*3);
		s.insert(next*5);

		ss.pb(next);
	}
	
	
	int j;
	cin>>j;
	
	
	
	while (j!=0){
		cout<<ss[j-1]<<endl;
		cin>>j;
	}
	
	return 0;
}
