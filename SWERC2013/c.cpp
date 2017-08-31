#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
#define INF 1e9
#define MAX_V  220
#define debug(a) cerr<< #a << ": " << a <<endl;
#define add(a, b, w) G[a].pb(make_pair(w, b))
#define sq(x) (x)*(x)
typedef long long ll;
typedef pair<int,int> ii;
typedef double tipo;
/////
vector<pair<double, int> > G[MAX_V];

void dijkstra(int s, int t){
	priority_queue< pair<double, int> , vector<pair<double,int> >, greater<pair<double, int > > > Q;
	
	vector<double> dist(220, INF); 
	vector<int> dad(220, -1);
	
	Q.push(make_pair(0,s));
	dist[s] = 0;
	while(sz(Q)){
		pair<double, int> p = Q.top(); Q.pop();
		if(p.snd == t) break;
		forall(it, G[p.snd]){
			if(dist[p.snd]+it->first < dist[it -> snd]){
				dist[it->snd] = dist[p.snd] + it->fst;
				dad[it->snd] = p.snd;
				Q.push(make_pair(dist[it->snd], it->snd));
			}
		}
	}

	if(dist[t]<INF){
		vector<int> path(220);
		int counter = 210;
		for(int i = t; i!=-1; i = dad[i]){
			path[counter] = i;
			counter--;
		}

		for(int i = counter+1; i < 210; i++){
			cout << path[i] << " ";
		}
		cout << path[210] << endl;
	}
}


int main() {
	
	double floors[220];
	double xs[220];
	double ys[220];
	int n, m;
  	cin >> n >> m;
  	forn(i, n){
  		cin >> floors[i] >> xs[i] >> ys[i];	
  	}

  	forn(i, m){
  		int src, dest;
  		string type;
  		cin >> src >> dest >> type;
  		
  		if(type == "stairs" || type == "walking"){
  			double dist = sq(5 * abs(floors[src] - floors[dest])) + 
  						 sq(xs[src]-xs[dest]) + sq(ys[src] - ys[dest]);
  			dist = sqrt(dist);			 
  			add(src, dest, dist);
  			add(dest, src, dist);
  		} else if (type == "escalator") {
  			add(src, dest, 1.0);
  			
  			double dist = sq(5 * abs(floors[src] - floors[dest])) + 
  						 sq(xs[src]-xs[dest]) + sq(ys[src] - ys[dest]);
  			dist = 3*sqrt(dist);

  			add(dest, src, dist);
  		} else {
  			add(src, dest, 1.0);
  			add(dest, src, 1.0); 
  		}

  	}
  	int q;
  	cin >> q;
  	forn(i, q){
  		int s, t;
  		cin >> s >> t;
  		dijkstra(s, t);
  	}

	return 0;
}
