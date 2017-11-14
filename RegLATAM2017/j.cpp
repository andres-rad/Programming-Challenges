#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define fst first
#define snd second
#define push_back pb
#define make_pair mp
typedef long long tint;

#ifdef DEBUG
#define debug(v) cerr<< #v << " = " << v << endl;
#else 
#define debug(v) 
#endif
  
string s;
int n;
map<int, int> divs;

int checkP(int p, int k) {
	vector<bool> mark;
	
	int firstK = -1;
	
	forsn(kk, 1, k+1) {
		mark = vector<bool>(n, false);
		
		int pp = 1;
		forn(i,kk) pp *= p;
		
		bool good = true;
		forn(i,n) {
			if(s[i] == 'P' or mark[i])
				continue;
			
			int j = i + pp;
			j %= n;
			while(j != i) {
				if(s[j] == 'P') {
					good = false;
					break;
				}
				mark[j] = true;
				
				j += pp;
				j %= n;
			}
			if(not good) break;
		}
		
		if(good) {
			firstK = kk;
		}
	}
	
	if(firstK == -1)
		return 0; // caso k == 0
	else {	
		int fp = 1;
		forn(i,firstK) fp *= p;
		
		return n / fp;
	}
}
  
int main(){
	cin >> s;
	n = s.length();
	
	bool alleq = true;
	forsn(i, 1, n) {
		if(s[i] != s[0]) {
			alleq = false;
			break;
		}
	}
	
	if(alleq) {
		cout << n-1 << endl;
	} else {
		
		// descomp n
		int nn = n;
		for(int i = 2; i <= nn; i += 2) {
			while(nn >= i and nn % i == 0) {
				divs[i]++;
				nn /= i;
			}
			
			// goto 3
			if(i == 2) i--;
		}
		
		// check for p
		int res = 1;
		bool siemprePuedoTodo = true;
		for(auto pp : divs) {
			int p = pp.fst;
			int k = pp.snd;
			int formas = checkP(p, k);
			
			debug(p);
			debug(k);
			debug(formas);
			
			res *= formas;
			
			if(formas != n/p)
				siemprePuedoTodo = false;
		}
		
		// sacar caso salto 1 (no se puede, filtramos al principio)
		res--;
		
		// sacar caso salto n
		if(siemprePuedoTodo)
			res--;
		
		cout << res << endl;
	}
	
	return 0;
}
