#include <bits/stdc++.h>
using namespace std;
typedef long long tint;
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define pb push_back

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << (v) << endl;
#else
#define debug(v)
#endif

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	tint n, k; cin >> n >> k;

	vector<tint> greedy(n, -1), interv(n, -1);
	tint now = -1;
	forn(i, k){
		tint a, b; cin >> a >> b;
		a--;
		if (a >= b or a == 0){
			now = max(now, b);
			if (a >= b) b += n;
		}
		debug(a);
		debug(b);
		debug(max(interv[a], b));
		interv[a] = max(interv[a], b);
	}

	vector<tint> deg(n, 0);
	forn(i, n){
		debug(i);
		debug(interv[i]);
		debug(now);
		if (now == i)
			now = -1;
		now = max(now, interv[i]);
		debug(now);
		if (now == -1){
			cout << "impossible" << endl;
			return 0;
		}
		greedy[i] = now % n;
		deg[now % n]++;
	}
	// forn(i, n){
	// 		// debug(*now.begin());
	// 	while(now.find(i) != now.end()){
	// 		// debug(*now.begin());
	// 		now.erase(i);
	// 	}
	// 		debug(get<0>(*it));
	// 	while(get<0>(*it) == i){
	// 		debug(get<0>(*it));
	// 		if (get<1>(*it) <= get<0>(*it))
	// 			now.insert(get<1>(*it) + n);
	// 		else 
	// 			now.insert(get<1>(*it));
	// 		it++;
	// 	}
	// 	if (not now.empty()){
	// 		greedy[i] = (*now.rbegin()) % n;
	// 		deg[(*now.rbegin()) % n]++;
	// 	}else{
	// 		cout << "impossible" << endl;
	// 		return 0; 
	// 	}
	// 	debug(i);
	// 	debug(greedy[i]);
	// }
	tint ans = k*2;
	forn(i, n){
		int p = i;
		if (greedy[p] == -1)
			continue;
		queue<tint> leave;
		tint cnt = 0;
		while(greedy[p] != -1){
			leave.push(p);
			cnt++;
			tint pp = p;
			p = greedy[pp];
			greddy[pp] = -1;
		}
	}

	queue<tint> bfs;
	forn(i, n){
		if (deg[i] == 0)
			bfs.push(i);
	}
	while(not bfs.empty()){
		tint nxt = bfs.front(); bfs.pop();
		if (greedy[nxt] == -1)
			continue;
		deg[greedy[nxt]]--;
		if (deg[greedy[nxt]] == 0)
			bfs.push(greedy[nxt]);
		greedy[nxt] = -1;
	}

	// forn(i, n){
	// 	debug(i);
	// 	debug(greedy[i]);
	// }

	tint ans = k*2;
	forn(i, n){
		if (greedy[i] == -1)
			continue;
		tint prox = i, cnt = 1;
		debug(prox);
		while(greedy[prox] != i){
			cnt++;
			tint proxi = greedy[prox];
			greedy[prox] = -1;
			prox = proxi;
		}
		greedy[prox] = -1;
		ans = min(ans, cnt);
	}

	while(ans == 2*k){}
	cout << ans << endl;




	return 0;
}