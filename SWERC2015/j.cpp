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
#define debug(v) //cerr<< #v << ": " << (v) <<endl;
typedef long long tint;
typedef pair<int,int> ii;
typedef double tipo;
/////

//punto
const double EPS = 1e-9;

struct pto{
  tint x, y;
  pto(tint x=0, tint y=0):x(x),y(y){}
  pto operator+(pto a){return pto(x+a.x, y+a.y);}
  pto operator-(pto a){return pto(x-a.x, y-a.y);}
  pto operator+(tint a){return pto(x+a, y+a);}
  pto operator*(tint a){return pto(x*a, y*a);}
  pto operator/(tint a){return pto(x/a, y/a);}
  //dot product, producto interno:
  tint operator*(pto a){return x*a.x+y*a.y;}
  //module of the cross product or vectorial product:
  //if a is less than 180 clockwise from b, a^b>0
  tint operator^(pto a){return x*a.y-y*a.x;}
  //returns true if this is at the left side of line qr
  bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
  bool collinear(pto q, pto r){return ((q-*this)^(r-*this))==0;}
  bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
  bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
  tint norm(){return sqrt(x*x+y*y);}
  tint norm_sq(){return x*x+y*y;}
  };
tint dist(pto a, pto b){return (b-a).norm();}
typedef pto vec;
tint angle(pto a, pto o, pto b){
  pto oa=a-o, ob=b-o;
  return atan2(oa^ob, oa*ob);}
//rotate p by theta rads CCW w.r.t. origin (0,0)
pto rotate(pto p, double theta){
  return pto(p.x*cos(theta)-p.y*sin(theta),
  p.x*sin(theta)+p.y*cos(theta));
}



//chull

void CH(vector<pto>& P, vector<pto> &S)
{
	S.clear();
	sort(P.begin(), P.end());//first x, then y
	forn(i, sz(P))
	{
  		while(sz(S)>= 2 && (S[sz(S)-1].left(S[sz(S)-2], P[i]) || S[sz(S)-1].collinear(S[sz(S)-2], P[i]))) S.pop_back();
  		S.pb(P[i]);
	}
	S.pop_back();
	int k=sz(S);
	dforn(i, sz(P))
	{
		while(sz(S) >= k+2 && (S[sz(S)-1].left(S[sz(S)-2], P[i]) || S[sz(S)-1].collinear(S[sz(S)-2], P[i])) ) S.pop_back();
  		S.pb(P[i]);
	}
	S.pop_back();
}

//point in poly
void normalize(vector<pto> &pt)
{
	//this makes it clockwise:
	if(pt[2].left(pt[0], pt[1])) reverse(pt.begin(), pt.end());
	int n=sz(pt), pi=0;
	forn(i, n)
		if(pt[i].x<pt[pi].x || (pt[i].x==pt[pi].x && pt[i].y<pt[pi].y))
			pi=i;
	vector<pto> shift(n);//puts pi as first point
	forn(i, n) shift[i]=pt[(pi+i) %n];
	pt.swap(shift);
}

bool inPolygon(pto p, const vector<pto> &pt)
{
	//call normalize first!
	if(p.left(pt[0], pt[1]) || p.left(pt[sz(pt)-1], pt[0])) return false;
	int a=1, b=sz(pt)-1;
	while(b-a>1)
	{
		int c=(a+b)/2;
		if(!p.left(pt[0], pt[c])) a=c;
		else b=c;
	}
	return !p.left(pt[a], pt[a+1]);
}

////

int main() {

  int l, s;
  cin>>l;
  vector<pto> P (l);
  vector<pto> S;

  forn(i,l){
    tint a, b;
    cin>>a>>b;
    P[i] = {a, b};
  }

  cin>>s;
  vector<pto> littles(s);
  forn(i, s ){
    tint a, b;
    cin>>a>>b;
    littles[i] = {a, b};
  }

  CH(P, S);
  forn(i, sz(S)){
    debug(S[i].x);
    debug(S[i].y);
  }
  normalize(S);

  int res = 0;
  forn(i,s){
    if (inPolygon(littles[i], S)) res++;
  }

  cout<<res<<endl;

  return 0;
}
