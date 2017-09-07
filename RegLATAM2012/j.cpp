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

struct node{
	int dir;
	vector<int> inv;
	tint color;
	int nivel;
};

tint ciclos;
tint colores;

vector<node> gr;
vector<int> vis;

vector<int> ciclo; // les entro con el color
vector<int> dist;
vector<int> tam;

void markCicle(int curr, int count, int ciclo);

void findCicle(int s){
	if (vis[gr[s].dir]){
		markCicle(s, 0, ciclos++);
	}else{
		vis[s] = 1;
		findCicle(gr[s].dir);
	}
}


void alturas(int curr, int alt, int col){
	gr[curr].nivel = alt;
	gr[curr].color = col;

	for(auto n:gr[curr].inv){
		if (!gr[n].color) alturas(n, alt+1, col);
	}

}

void markCicle(int curr, int count, int currciclo){
	debug(curr);
	debug(gr[curr].dir);
	debug(gr[curr].color);
	debug(currciclo);
	if (gr[curr].color){
		tam.pb(count );
		return;
	}

	gr[curr].color = colores++;
	ciclo.pb(currciclo);
	dist.pb(count);

	markCicle(gr[curr].dir, count+1, currciclo);
	alturas(curr, 0, gr[curr].color);
}








int main() {
	int n, q;

	while (cin>>n){
		ciclos = 1;
		colores = 1;
		tam = vector<int> (1, 0);
		dist = vector<int> (1, 0);
		ciclo = vector<int> (1, 0);
		gr = vector<node> (n);
		vis = vector<int> (n, 0);

		forn(i,n){
			int f;
			cin>>f;
			f--;

			gr[i].dir = f;
			gr[f].inv.pb(i);
		}

		forn (i,n){
			if (not vis[i])
				findCicle(i);
		}

		//vis = std::vector<int> (n, 0);
		//forn(i,n){
		//	if(gr[i].color)
		//		alturas(i, 0, gr[i].color);
		//}
		int res;

		cin>>q;
		forn(i,q){
			int a, b;
			cin>>a>>b;
			a--; b--;

			debug(a);
			debug(b);
			debug(gr[a].color);
			debug(gr[a].color);
			debug(gr[a].nivel);
			debug(gr[b].nivel);
			debug(ciclo[gr[b].color]);
			debug(ciclo[gr[b].color]);
			debug(dist[gr[a].color]);
			debug(dist[gr[b].color]);
			debug(tam[ciclo[gr[a].color]]);
			if (gr[a].color == gr[b].color){
				res = abs(gr[a].nivel - gr[b].nivel);
			}else if(ciclo[gr[a].color] == ciclo[gr[b].color]){
				res = gr[a].nivel + gr[b].nivel +
				min(abs(dist[gr[a].color] - dist[gr[b].color]), tam[ciclo[gr[a].color]]- abs(dist[gr[a].color] - dist[gr[b].color]));
			}else{
				res = -1;
			}
		cout<<res<<endl;

		}







	}


	return 0;
}
