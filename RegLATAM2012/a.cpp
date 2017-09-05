#include <bits/stdc++.h>
using namespace std;
#define tint __int128
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define debug(v) //cerr << #v << " = " << (v) << endl;
#define pb push_back
#define mp make_pair

set<pair <tint, int> > heaps;
//vector<int>

int main() {
	int n,k;
	while(cin >> n){
		heaps = set<pair<tint, int> >();
		cin >> k;
		int prev_pos, prev_w;
		cin >> prev_pos >> prev_w;
		vector<set<pair<tint, int> >::iterator> its;
		vector<pair<int, tint> > info;//fst es el siguiente, snd es su peso
		forn(i, n-1){
			int pos, w;
			cin >> pos >> w;
			its.pb(heaps.insert(mp(prev_w*(pos - prev_pos), heaps.size())).fst);
			info.pb(mp(prev_pos, prev_w));
			prev_pos = pos;
			prev_w = w;
		}
		info.pb(mp(prev_pos, prev_w));

		tint ans = 0;
		while (heaps.size()>k-1){
			auto front = *heaps.begin();
			heaps.erase(heaps.begin());
			ans += (tint) front.fst;
			int idx = front.snd;
			//debug(heaps.size());
			//debug(front.fst);
			//debug(idx);
			//debug(info[idx].fst);
			//debug(info[idx].snd);
			debug(front.fst);
			debug(ans);

			//actualizo el anterior
			int previdx = idx-1;
			while(previdx>=0 && info[previdx].fst==-1)
				previdx--;
			int nextidx = idx+1;
			while(nextidx<n-1 && info[nextidx].fst == -1)
				nextidx++;

			//debug(nextidx);
			//debug(info[nextidx].fst);
			//debug(info[nextidx].snd);
			//debug(previdx);
			//debug(info[previdx].fst);
			//debug(info[previdx].snd);

			if(previdx>=0){
				heaps.erase(its[previdx]);
				its[previdx]=heaps.insert(mp(info[previdx].snd * (tint) (info[nextidx].fst - info[previdx].fst), previdx)).fst;
			}

			if (nextidx != n-1){
				int nextnextidx = nextidx + 1;
				while(nextnextidx<n-1 && info[nextnextidx].fst == -1)
					nextnextidx++;

				//debug(nextnextidx);
				//debug(info[nextnextidx].fst);
				//debug(info[nextnextidx].snd);

				heaps.erase(its[nextidx]);
				info[nextidx].snd += info[idx].snd;
				its[nextidx] = heaps.insert(mp( info[nextidx].snd * ((tint) (info[nextnextidx].fst - info[nextidx].fst)), nextidx)).fst;
			}

			info[idx] = mp(-1, -1);



		}

		vector<int> vans;
		while (ans>0){
			vans.pb(ans % 10);
			ans = ans/10;
		}

		dforn(i, vans.size()){
			cout<<vans[i];
		}
		cout<<endl;
		//cout<<ans<<endl;
	}
	return 0;
}
