#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

using namespace std;

int n, a, b, tam, m;

struct node{
	vector<int> adj;

	int deg;

	
};

vector<int> sett;
vector<node> gra;

bool menor( const int & uno, const int& otro){
		return gra[uno].deg<gra[otro].deg;
	}


void dfs(int s){
	if (!sett[s]) return;
	sett[s]=0;
	tam--;

	forn(i,gra[s].adj.size()){
		int hijo=gra[s].adj[i];
		gra[hijo].deg--;
		if (gra[hijo].deg<a){
			//cerr<<"recurro "<<hijo<<endl;
			dfs(hijo);

		}
	}

	return;
}




int main() {


	cin>>n>>m>>a>>b;

	if(a+b>n){
		cout << 0 << endl;
		return 0;
	}
	sett=vector<int> (n,1);
	node temp;
	temp.adj=vector<int> (0);
	temp.deg=0;
	gra=vector<node>(n, temp);
	forn (i,m){
		int s,t;
		cin>>s>>t;
		s--; t--;
		gra[s].adj.pb(t);
		gra[s].deg++;
		gra[t].adj.pb(s);
		gra[t].deg++;

	}

	int i,j;
	i=0; j=n-1;

	vector<int> orden(n,0);
	forn (i,n) orden[i]=i;
	sort(orden.begin(), orden.end(),menor);




	int li=-1; int lj=-1;
	tam=n;
	int ultam=tam+1;

	while (tam!=0 && j>=0 && i<n){
		li=i; lj=j;


		int cur=orden[i];
		while (i<n && (!sett[cur] || gra[cur].deg<a)){
			//cerr<<"llamo "<<cur<<endl;
			
			dfs(cur);
			i++;
			cur=orden[i];
		}

		cur=j;
		while (j>=0 && (!sett[cur] || tam-gra[cur].deg-1<b)){
			//cerr<<"llamo "<<cur<<endl;

			dfs(cur);
			j--;
			cur=orden[j];
		}


		if (lj==j){
			j--;
		}else if(li==i){
			i++;
		}

	}

	cout<<tam<<endl;

	return 0;
}