#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define first fst
#define second snd
#define pb push_back 
#define make_pair mp
typedef long long tint;
typedef pair<tint, tint> ii;
#define INF 1000000000

#ifdef DEBUG
#define debug(v) cerr<< #v << " = " << v << endl;
#else 
#define debug(v) 
#endif

struct pto{
	tint x, y;
	pto operator-(const pto& o){
		pto res;
		res.x = x - o.x;
		res.y = y - o.y;
		return res;
	}
	pto operator+(const pto& o){
		pto res;
		res.x = x + o.x;
		res.y = y + o.y;
		return res;
	}
	tint operator* ( const pto& o){
		return x*o.x + y*o.y;
	}
	tint operator^(const pto & o){
		return x*o.y - y *o.x;
	}
};

pto operator*(tint a, pto p){
	pto res;
	res.x = p.x*a;
	res.y = p.y*a;
	return res;
}

double norma(pto p){
	return sqrt(p.x*p.x + p.y*p.y);
}

struct line{
	doubel a, b, c;
	line(pto p, pto q){
		a = q.y - p.y;
		b = p.x - q.x;
		c = a*p.x + b * p.y;
	}
};

line Line(pto a, pto b){
	line res;
	res.s = a;
	res.d = b-a;
	return res;
}

pto inter(line l1, line l2){
	double det = l1.a*l2.
pto interLL(line l1, line l2){
	debug((l1.d^l2.d));
	debug((l1.d^l2.d));
	return l1.s + (((l2.s - l1.s)^l2.d) / (l1.d^l2.d)) * l1.d;
}

  
int main(){
	int n;
	cin >> n;
	vector<vector<pto>> lados (n);
	vector<int> der (n);
	vector<tint> ancho (n);
	vector<tint> maxider(n, -1), miniizq (n, 1);
	
	forn(i, n){
		int k;
		cin >> k ;
		tint maxi = 0;
		tint maxder = -1, minizq = 1;
		forn(j, k){
			tint x, y;
			cin >> x >> y;
			if (x > maxder) maxder = x;
			if ( x < minizq) minizq = x;
			
			lados[i].pb({x, y});
			if (y > lados[i][maxi].y){
				maxi = j;
			}
		}
		der[i] = maxi;
		debug(maxder);
		debug(minizq);
		maxider[i] = maxder;
		miniizq[i] = minizq;
	}
	
	vector<vector<tint >> C (n, vector<tint> (n));
	forn(i, n){
		forn(j, n){
			// calculo ganancia entre estos
			// i a la izq j a la der
			
			double res = INF;
			
			int le = 1, ri = der[j] + 1;
			
			while (le < der[i] and ri < lados[j].size()){
				pto movi;
				movi.x = -maxider[i];
				movi.y = 0;
				pto movj;
				movj.x = -miniizq[j];
				movj.y = 0;
				pto unit;
				unit.x = 1;
				unit.y = 0;
				if (lados[i][le].y < lados[j][ri].y){
					line hor = Line(lados[i][le] + movi, lados[i][le] + unit);
					line vert =  Line(lados[j][ri - 1] + movj, lados[j][ri] + movj);
					debug(hor.s.x);
					debug(hor.d.x);
					debug(vert.s.x);
					debug(vert.d.x);
					debug(hor.s.y);
					debug(hor.d.y);
					debug(vert.s.y);
					debug(vert.d.y);
					pto inters = interLL(hor, vert);
					
					double cand = norma(inters - (lados[i][le] + movi));
					if (res > cand) res= cand;
					le++;
					
					
				}else{
					line hor = Line(lados[j][ri] + movj,  lados[j][ri] + unit);
					line vert =  Line(lados[i][le - 1] + movi, lados[i][le] + movi);
					pto inters = interLL(hor, vert);
					
					double cand = norma(inters - (lados[j][ri] + movj));
					if (res > cand) res= cand;
					ri++;
					
				}
				
			C[i][j] = res;
		}
	}
	}
	
	
	
	vector<vector<tint> > dp (1 << (n+1), vector<tint> (n, INF));
	forsn(m, 0, (1 << (n+1)) -1){
		for (int i = 0; i < n; i++){
			if ((m & i) == 0) continue;
			int n = m ^ i;
			for (int j = 0; j < n; j++){
				if ((n & j) == 0) continue;
				dp[m][i] = min(dp[m][i], dp[n ^ j][j] + C[j][i]);
			}
		}
	}
	
	tint mejor = INF;
	int m = (1 << (n+1)) -1;
	forn(i, n){
		if (mejor > dp[m][i]) mejor = dp[m][i];
	}
	
	cout << mejor << endl;
	
	return 0;
}
