#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
typedef long long tint;
typedef pair<tint, tint> ii;

#ifdef DEBUG
#define debug(v) cerr<< #v << " = " << v << endl;
#else 
#define debug(v) 
#endif

struct p {
	int pos;
	tint bea;
	tint fort;
	tint val;
};
  
int n;
vector<p> ps;
vector<tint> arr;

const tint INF = 1e12;

#define iii pair<ii,int>
tint lis() {
	set<pair<ii,int>> s;
	s.insert({{-1, 0},-1});
	forn(i,n) {
		bool ok = true;
		int u = arr[i];
		
		iii pai = {{ps[u].fort, INF}, u};
		auto lit = upper_bound(s.begin(), s.end(), pai);
		while(lit == s.end() or lit->fst.fst >= ps[u].fort) lit--;
		tint myBest = lit->fst.snd + ps[u].val;
		
		auto it = upper_bound(s.begin(), s.end(), pai);
		if(it != s.end()) it++;
		while(it == s.end() or (it->snd != -1 and (it->fst.fst > ps[u].fort or ps[it->snd].bea >= ps[u].bea))) it--;
		
		bool inserted = false;
		if(it->fst.fst == ps[u].fort) {
			if(it->fst.snd < myBest) {
				s.erase(it);
				s.insert({{ps[u].fort, myBest}, u});
				inserted = true;
			}
		} else {
			s.insert({{ps[u].fort, myBest},u});
			inserted = true;
		}
		
		iii me = {{ps[u].fort, myBest},u};
		if(inserted) {
			while(true){
				auto itMe = s.find(me);
				if(itMe->fst.fst == ps[u].fort) itMe++;
			
				if(itMe == s.end()) break;
				if(itMe->fst.snd > myBest) break;
				
				s.erase(itMe);
			}
		}
	}
		
	auto itLast = s.end();
	itLast--;
	
	return itLast->fst.snd;
}
  
int main(){
	cin >> n;
	
	ps = vector<p>(n);
	arr = vector<tint>(n);
	
	vector<ii> tosort(n);
	forn(i,n) {
		cin >> ps[i].bea >> ps[i].fort >> ps[i].val;
		tosort[i] = {ps[i].bea, i};
	}
	sort(tosort.begin(), tosort.end());
	
	forn(i,n) {
		int pp = tosort[i].snd;
		ps[pp].pos = i;
		arr[i] = pp;
	}
	
	tint res = lis();
	
	cout << res << endl;
	
	return 0;
}
