#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define first fst
#define second snd
#define pb push_back
#define make_pair mp
typedef long long tint;
typedef long long ll;
typedef pair<tint, tint> ii;
#define INF 1000000000

#ifdef DEBUG
#define debug(v) cerr<< #v << " = " << v << endl;
#else
#define debug(v)
#endif

const double EPS=1e-5;
struct pto{
	double x, y;
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(double a){return pto(x+a, y+a);}
	pto operator*(double a){return pto(x*a, y*a);}
	pto operator/(double a){return pto(x/a, y/a);}
	//dot product, producto interno:
	double operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	double operator^(pto a){return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
    bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	double norm(){return sqrt(x*x+y*y);}
	double norm_sq(){return x*x+y*y;}
};
double dist(pto a, pto b){return (b-a).norm();}
typedef pto vec;

//positivo si aob están en sentido antihorario con un ángulo <180º
double angle(pto a, pto o, pto b){ //devuelve radianes! (-pi,pi)
	pto oa=a-o, ob=b-o;
	return atan2(oa^ob, oa*ob);}

//rotate p by theta rads CCW w.r.t. origin (0,0)
pto rotate(pto p, double theta){
	return pto(p.x*cos(theta)-p.y*sin(theta),
     p.x*sin(theta)+p.y*cos(theta));
}

int sgn(ll x){return x<0? -1 : !!x;}
struct line{
	line() {}
	double a,b,c;//Ax+By=C
//pto MUST store float coordinates!
	line(double a, double b, double c):a(a),b(b),c(c){}
	line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
	int side(pto p){return sgn(ll(a) * p.x + ll(b) * p.y - c);}
};
bool parallels(line l1, line l2){return abs(l1.a*l2.b-l2.a*l1.b)<EPS;}
pto inter(line l1, line l2){//intersection
	double det=l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF, INF);//parallels
	return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
}


int main(){
	int n;
	cin >> n;
	vector<vector<pto>> lados (n);
	vector<int> der (n);
	vector<double> ancho (n);
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
		ancho[i] = maxder - minizq;
	}

	vector<vector<double >> C (n, vector<double> (n));

	forn(i, n){
		forn(j, n){
			// calculo ganancia entre estos
			// i a la izq j a la der

			double res = INF;

			int le = 1, ri = 0;

			pto movi;
			movi.x = -maxider[i];
			movi.y = 0;
			pto movj;
			movj.x = -miniizq[j];
			movj.y = 0;
			pto unit;
			unit.x = 1;
			unit.y = 0;
			debug(i);
			debug(j);
			debug(movi.x);
			debug(movj.x);

			while (le < der[i] + 1 or ri > der[j] or ri == 0){
				debug(le);
				debug(ri);
				if (le <= der[i] and (ri == 0 or ri > der[j]) and abs(lados[i][le].y - lados[j][ri].y) <= EPS){
					double cand = ((lados[j][ri] + movj) - (lados[i][le] + movi)).norm();
					if (res > cand) res= cand;
					le = (le + 1) % lados[i].size();
				}else if (le <= der[i] and lados[i][le].y <= EPS + lados[j][ri].y){
					line hor(lados[i][le] + movi, lados[i][le] + unit);
					line vert(lados[j][(ri + 1)%lados[j].size()] + movj, lados[j][ri] + movj);

					pto inters = inter(hor, vert);

					double cand = (inters - (lados[i][le] + movi)).norm();
					if (res > cand) res= cand;
					le = (le + 1) % lados[i].size();

				}else{
					line hor(lados[j][ri] + movj,  lados[j][ri] + unit);
					line vert(lados[i][(le - 1 + lados[i].size())%lados[i].size()] + movi, lados[i][le] + movi);
					pto inters = inter(hor, vert);

					double cand = (inters - (lados[j][ri] + movj)).norm();
					if (res > cand) res= cand;
					ri = (ri - 1 + lados[j].size()) % lados[j].size() ;

				}

			}
			C[i][j] = res;
			debug(res);
		}
	}



	vector<vector<double> > dp (1 << (n+1), vector<double> (n, INF));
	forn(i, n){
		dp[0][i] = 0;
		debug(ancho[i]);
		dp[(1 << i)][i] = ancho[i];
	}

	forsn(m, 0, (1 << (n))){
		debug(m);
		for (int i = 0; i < n; i++){
			debug(i);
			debug((m & (1 << i)));
			if ((m & (1 << i)) == 0) continue;
			int mm = m ^ (1 << i);
			debug(mm);
			for (int j = 0; j < n; j++){
				debug(j);
				debug((mm & (1 << j)));
				if ((mm & (1 << j)) == 0) continue;
				debug((mm^(1 << j)));
				//debug(i);
				//debug(m);

				dp[m][i] = min(dp[m][i], dp[mm][j] + ancho[i] -  C[j][i]);
				debug(dp[m][i]);
			}
		}
	}

	double mejor = INF;
	int m = (1 << (n)) -1;
	forn(i, n){
		if (mejor > dp[m][i]) mejor = dp[m][i];
	}

	cout << setprecision(3) << fixed << mejor << endl;

	return 0;
}
