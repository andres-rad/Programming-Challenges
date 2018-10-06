#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define first fst
#define second snd
#define push_back pb
#define make_pair mp
typedef long long tint;

#ifdef DEBUG
#define debug(v) cerr<< #v << " = " << v << endl;
#else 
#define debug(v) 
#endif

#define MAX_N 800010
#define rBOUND(x) ((x) < n ? r[(x)] : 0)
//sa will hold the suffixes in order.
int sa[MAX_N], r[MAX_N], n;// OJO n = s.size()!
vector<int> s; //input string, n=s.size()

int f[MAX_N], tmpsa[MAX_N];
void countingSort(int k){
	zero(f);
	forn(i, n) f[rBOUND(i+k)]++;
	int sum=0;
	forn(i, max(255, n)){
		int t=f[i]; f[i]=sum; sum+=t;
	}
	forn(i,n)
	tmpsa[f[rBOUND(sa[i]+k)]++]=sa[i];
	forn(i,n) sa[i] = tmpsa[i];
}

void constructsa(){//O(n log n)
	n = s.size();

	forn(i,n) sa[i]=i, r[i]=s[i];

	for(int k=1; k<n; k<<=1){
		countingSort(k), countingSort(0);
		int rank, tmpr[MAX_N];
		tmpr[sa[0]]=rank=0;
		forr(i, 1, n)
		tmpr[sa[i]] = (r[sa[i]]==r[sa[i-1]] && r[sa[i]+k]==r[sa[i-1]+k]) ? rank : ++rank;
		forn(i,n) r[i]=tmpr[i];
		if(r[sa[n-1]]==n-1) break;
	}
}

  
int main(){
	
	int m; 
	cin >> m;

	int days = 0;

	vector<vector<int>> st(n, vector<int> ());
	//int cur = 0;

	map<int, int> pos(); // pos[i] las posiciones [pos[i], pos[i+1]) pertenecen a la palabra i
		// contando el #

	forn(i, m){
		pos[i] = s.size();
		int k; 
		cin >> k;
		st[i] = vector<int> (k);
		days += k;
		forn (j, k){
			int v;
			cin >> v;
			s.pb(v);
			//cur++;
		}
		s.pb(400);
		//cur++;

	}

	constructsa();

	forn (i, s.size()){
		// cada t tiene el sufijo mas chico
		int t = s[i];
		auto it = --pos.upper_bound(t);
		//ahora it apunta al par que tiene, cual es mi primer indice en s, cual es mi palabra
		int sLocal = t - it->fst; // me dice en que nivel de la cola estoy
		int pila = it->snd;
		if (sLocal < st[pila].size()){
			st[pila][sLocal] = i;
		}
	}

	// Ahora mantengo un set que tiene pares (a, b) donde a es la posicion del sufijo actual de la palabra b
	set <pair<int, int>> curr();

	forn (i, st.size()){

		curr.insert(mp(st[i][0], i));
	}

	tint res = 0;
	tint mod = 1000000007;

	vector<int> actual(n, 0);


	while (not curr.empty()){
		pair<int, int> prox = *curr.begin(); // prox tiene (a, b) diciendo ahora uso
		// el sufijo a de la palabra b
		curr.erase(curr.e)

		res += st[prox]


		days--;

	}
	//map<int, int> last();  // ultimo sufijo encontrado para 



	return 0;
}
