#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define debug(v) cerr << #v << " = " << (v) << endl;
#define pb push_back
#define mp make_pair

set<pair <int, pair<int, int> > > heaps;
vector<int> 

int main() {
	int n,k;
	while(cin >> n){
		heaps = set<pair<int, pair<int, int> > >heaps;
		cin >> k;
		int prev_pos, prev_w;
		cin >> prev_pos >> prev_w;
		forn(i, n){
			int pos, w;
			cin >> pos >> w;
			heaps.insert(mp(prev_w*(pos - prev_pos, mp), mp(prev_w, prev_pos)));
			prev_pos = pos;
			prev_w = w;
		}
	}
	return 0;
}