#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define fst first 
#define snd second 
#define pb push_back
#define mp make_pair 
typedef long long tint;
typedef pair<int, int> ii;

#ifdef DEBUG
#define debug(v) cerr<< #v << " = " << v << endl;
#else 
#define debug(v) 
#endif
  
int main(){
	int l, c, n;
	cin >> l >> c >> n;
	vector<ii> inte;
	
	vector<int> colores;
	
	inte.pb(mp(0, l));
	colores.pb(0);
	
	unordered_map<int, int> h;
	
	forn(i, n){
		int p, x, a, b;
		cin >> p >> x >> a >> b;
		p--;
		x--;
		
		int s = h[p];
		int m1a = (a + s*s) % l;
		int m2a = (a + (s + b)*(s+b)) % l;
		
		int m1 = min(m1a, m2a);
		int m2 = max(m1a, m2a);
		
		int lo = 0, hi = inte.size();
		
		int left, right, med;
		
		while (hi - lo > 1){
			int med = (hi + lo) /2;
			ii cand = inte[med];
			if (m1 < cand.second and m1 >= cand.first){
				left = med;
				break;
			}
			if (cand.second <= m1){
				lo = med + 1;
			}else{
				hi = med;
			}
		}
		left = lo;
		
		lo = 0, hi = inte.size();
		
		
		
		while (hi - lo > 1){
			int med = (hi + lo) /2;
			ii cand = inte[med];
			if (m2 < cand.second and m2 >= cand.first){
				right = med;
				break;
			}
			if (cand.second <= m2){
				lo = med + 1;
			}else{
				hi = med;
			}
		}
		right = lo;
			
		
		
		int agregar = 0;
		if (left == right){
			
			
		if (m1 < inte[left].second and m1 > inte[left].first){
			agregar += inte[left].second - m1;
			h[colores[left]] -= inte[left].second - m1;
			inte[left].second = m1;
			left++;
		}
		
		if (m2 < inte[right].second and m2 > inte[right].first){
			agregar += inte[right].second - m2;
			h[colores[right]] -= inte[right].second - m1;
			inte[right].second = m1;
			right--;
		}
		
		debug(right);
		debug(left);
		debug(inte.size());
		while (left < right){
			agregar += inte[left].second - inte[left].first;
			h[colores[left]] -= inte[left].second - inte[left].first;
			colores.erase(colores.begin() + left);
			inte.erase(inte.begin() + left);
			
			right--;
		}
		
		inte.insert(inte.begin() + left, mp(m1, m2));
		colores.insert(colores.begin() + left, x);
		h[x] += m2 - m1;
			 
	}
	return 0;
}
