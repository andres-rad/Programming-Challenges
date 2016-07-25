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

typedef long long int tint;


int main(){
	int casos;
	cin >> casos;
	int caso = 0;
	while(caso < casos){
		caso++;
		int n;
		int res = 0;
		cin >> n;
		vector<int> cant(4,0);
		forn(i,n){
			int s;
			cin >> s;
			cant[s-1]++;
		}
		res += cant[3] + cant[2] + cant[1]/2;
		cant[1] = cant[1] % 2;
		if (cant[1]==1){
			res++;
			cant[0]= max(0, cant[0]-2);
		}
		cant[0]= max(0, cant[0]-cant[2]);
		res+= cant[0]/4 + (cant[0] % 4!=0?1:0);
		
		cout << res << endl;	
	}
	return 0;
}
