#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

using namespace std;

#define MAX_V 1000
#define INF 1e9
#define SRC 0
#define SNK 1

vector<map<int, int>> G;

#define add(a,b,w) G[a][b]=w

int f;
vector<int> p;

void init(int n) {
	G = vector<map<int, int>>(n*2+2);
	f = 0;
}

void augment(int v, int minE) {
	if(v==SRC) f=minE;
	else if(p[v] != -1) {
		augment(p[v], min(minE, G[p[v]][v]));
		G[p[v]][v] -= f;
		G[v][p[v]] += f;
	}
}

int maxflow(int n) {
	int Mf=0;
	do{
		f=0;
		vector<bool> used(n*2+2, false); 
		queue<int> q;
		p = vector<int>(n*2+2,-1);

		q.push(SRC);
		used[SRC] = true;

		while(q.size()) {
			int u = q.front();
			q.pop();
			if(u==SNK) break;
			for(auto pp : G[u]) {
				if(pp.snd > 0 && !used[pp.fst]) {
					used[pp.fst] = true;
					q.push(pp.fst);
					p[pp.fst] = u;
				}
			}
		}
		augment(SNK,INF);
		Mf += f;
	} while(f);
	return Mf;
}

int main() {

	int n;
	cin >> n;

	vector<pair<int,int>> chos(n);

	forn(i,n){
		int ca,cb;
		cin >> ca >> cb;
		ca--; cb--;
		chos[i] = {ca,cb};
	}

	int res = 0;

	forn(i,n) {
		init(n);

		int k = 0;
		int target = 0;

		forn(j,n) {
			auto cc = chos[j];
			if(cc.fst == i || cc.snd == i) k++;
			else if(j != i) target++;
		}

		if(k <= 1) {
			//cerr << "i got " << k << " votes" << endl;
			res ++;
			continue;
		}

		forn(j,n) {
			auto cc = chos[j];

			if(j != i) {
			
				if(cc.fst != i && cc.snd != i) {
					add(0,j+2,1);
					add(j+2, cc.fst+2+n, 1);
					add(j+2, cc.snd+2+n, 1);
				}

				if(j != chos[i].fst && j != chos[i].snd) {
					add(j+2+n, 1, k-1);	
				} else {
					add(j+2+n, 1, k-2);
				}
			}
		}

		int mf = maxflow(n);

		//cerr << "maxflow " << mf << " target " << target << endl;

		if(mf < target) res++;
	}

	cout << res << endl;

	return 0;
}