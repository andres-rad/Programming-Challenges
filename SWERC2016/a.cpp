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
typedef long long ll;
typedef pair<int,int> ii;
typedef double tipo;

const int MAXN=100100;

///punto

const double EPS=1e-9;
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

double angle(pto a, pto o, pto b){
	pto oa=a-o, ob=b-o;
	return atan2(oa^ob, oa*ob);}

//rotate p by theta rads CCW w.r.t. origin (0,0)
pto rotate(pto p, double theta){
	return pto(p.x*cos(theta)-p.y*sin(theta),
     p.x*sin(theta)+p.y*cos(theta));
}

///linea

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
//// circulo

vec perp(vec v){return vec(-v.y, v.x);}

struct Circle{
	pto o;
	double r;

	pair<pto, pto> ptosTang(pto p){
		pto m=(p+o)/2;
		tipo d=dist(o, m);
		tipo a=r*r/(2*d);
		tipo h=sqrt(r*r-a*a);
		pto m2=o+(m-o)*a/d;
		vec per=perp(m-o)/d;
		return make_pair(m2-per*h, m2+per*h);
	}
};
//finds the center of the circle containing p1 and p2 with radius r
//as there may be two solutions swap p1, p2 to get the other
bool circle2PtsRad(pto p1, pto p2, double r, pto &c){
        double d2=(p1-p2).norm_sq(), det=r*r/d2-0.25;
        if(det<0) return false;
        c=(p1+p2)/2+perp(p2-p1)*sqrt(det);
        return true;
}
#define sqr(a) ((a)*(a))
#define feq(a,b) (fabs((a)-(b))<EPS)
pair<tipo, tipo> ecCuad(tipo a, tipo b, tipo c){//a*x*x+b*x+c=0
	tipo dx = sqrt(b*b-4.0*a*c);
	return make_pair((-b + dx)/(2.0*a),(-b - dx)/(2.0*a));
}
pair<pto, pto> interCL(Circle c, line l){
	bool sw=false;
	if((sw=feq(0,l.b))){
	swap(l.a, l.b);
	swap(c.o.x, c.o.y);
	}
	pair<tipo, tipo> rc = ecCuad(
	sqr(l.a)+sqr(l.b),
	2.0*l.a*l.b*c.o.y-2.0*(sqr(l.b)*c.o.x+l.c*l.a),
	sqr(l.b)*(sqr(c.o.x)+sqr(c.o.y)-sqr(c.r))+sqr(l.c)-2.0*l.c*l.b*c.o.y
	);
	pair<pto, pto> p( pto(rc.first, (l.c - l.a * rc.first) / l.b),
					  pto(rc.second, (l.c - l.a * rc.second) / l.b) );
	if(sw){
	swap(p.first.x, p.first.y);
	swap(p.second.x, p.second.y);
	}
	return p;
}
pair<pto, pto> interCC(Circle c1, Circle c2){
	line l;
	l.a = c1.o.x-c2.o.x;
	l.b = c1.o.y-c2.o.y;
	l.c = (sqr(c2.r)-sqr(c1.r)+sqr(c1.o.x)-sqr(c2.o.x)+sqr(c1.o.y)
	-sqr(c2.o.y))/2.0;
	return interCL(c1, l);
}

/////

int main() {
  int n;
  while(cin>>n){
    vector<int> l (n);
    int x,y;

    forn(i,n){
      cin>>l[i];

    }
    cin>>x>>y;
    vector<pair<int, int> > radios (n);
    radios[0].fst=l[0];
    radios[0].second=l[0];


    forr(i,1,n){
      if (l[i]<radios[i-1].fst){
        radios[i].fst=radios[i-1].fst - l[i];
      }else if(l[i]>radios[i-1].snd){
        radios[i].fst= - radios[i-1].snd + l[i];
      }else{
        radios[i].fst=0;
      }
      radios[i].snd=radios[i-1].snd + l[i];

    }

		vector<pto> res(n);


		Circle punto;
		punto.o={(double)x,(double)y};
		//cerr<< punto.o.x<<endl;
		punto.r=l[n-1];

		if (punto.o.norm()<radios[n-1].fst ){
			line lin((pto){0.0, 0.0}, punto.o);

			Circle limit;
			limit.o={0,0};
			limit.r=radios[n-1].fst;

			auto inter1=interCL(limit, lin);

			if (dist(inter1.fst, punto.o)>dist(inter1.snd, punto.o)){
				punto.o=inter1.snd;
			}else{
				punto.o=inter1.fst;
			}

		}else if ( (punto.o).norm()>radios[n-1].snd){
			line lin((pto){0.0, 0.0}, punto.o);

			Circle limit;
			limit.o={0,0};
			limit.r=radios[n-1].snd;

			auto inter1=interCL(limit, lin);

			if (dist(inter1.fst, punto.o)>dist(inter1.snd, punto.o)){
				punto.o=inter1.snd;
			}else{
				punto.o=inter1.fst;
			}

		}


		Circle limite;
		limite.o={0.0, 0.0};
		limite.r=radios[n-2].fst; //4
		res[n-1]=punto.o;
		dforn(i,n-1){
			auto inter=interCC(limite, punto).fst;
			//cerr<<"inters "<<inter.x<<' '<<inter.y<<endl;
			if (inter.x!=inter.x){

				//cerr<<"norma "<<punto.o.norm()<<endl;

				if (punto.o.norm()<radios[i].fst ){
					line lin((pto){0.0, 0.0}, punto.o);

					Circle limit;
					limit.o={0,0};
					limit.r=radios[i].fst;

					auto inter1=interCL(limit, lin);

					if (dist(inter1.fst, punto.o)>dist(inter1.snd, punto.o)){
						punto.o=inter1.snd;
					}else{
						punto.o=inter1.fst;
					}

				}else if ( (punto.o).norm()>radios[i].snd){
					line lin((pto){0.0, 0.0}, punto.o);

					Circle limit;
					limit.o={0,0};
					limit.r=radios[i].snd;

					auto inter1=interCL(limit, lin);

					if (dist(inter1.fst, punto.o)>dist(inter1.snd, punto.o)){
						punto.o=inter1.snd;
					}else{
						punto.o=inter1.fst;
					}

				}else{

					punto.o={punto.o.x+punto.r, punto.o.y};
				}

			res[i]=punto.o;

			}else{
				res[i]=inter;
				punto.o=inter;
			}

			punto.r=l[i];
			if (i) limite.r=radios[i-1].fst;

		}

		forn(i,n){
			cout<<setprecision(3)<<fixed<<res[i].x<<' '<<res[i].y<<endl;
		}

  }

  return 0;
}
