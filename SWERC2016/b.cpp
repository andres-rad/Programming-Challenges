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
#define debug(v) cerr<< #v << ": " << (v) <<endl;
typedef long long ll;
typedef pair<int,int> ii;
typedef long tint;

#ifdef ONLINE_JUDGE
#undef debug
#define debug
#endif

const int MAXN=100100;

///punto

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
	tint operator^(const pto a) const {return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	//bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
	bool operator<(const pto &a) const{return x*a.y-y*a.x < 0;}
bool operator==(pto a){return abs(x-a.x)==0 && abs(y-a.y)==0;}
	tint norm(){return sqrt(x*x+y*y);}
	tint norm_sq(){return x*x+y*y;}
};

/////

int main() {
  int n;
	while(cin>>n){
		int rX=0, rY = 0;
		int upper=0, lower=0;
		vector<pto> add;
		vector<pto> del;

		cin >> rX >> rY;

		// read ptos
		forn(i, n-1) {
			tint x,y;
			cin >> x >> y;
			x-=rX;
			y-=rY;
			pto p = {x,y};

			if(x<0 && y>0) {
				add.pb(p);
			} else if(x>0 && y<0) {
				del.pb(p);
			} else if(y>=0 && x >=0) {
				upper++;
			} else {
				lower++;
			}

			/*
			if(x>0 && y>0) {
				upper++;
			} else if(x<0 && y<0) {
				lower++;
			} else if(y<0 || (y==0 && x >0)) {
				del.pb(p);
			} else {
				add.pb(p);
			}
			*/
		}
		sort(add.begin(), add.end());
		sort(del.begin(), del.end());

		// sweep
		tint curr = del.size() + upper + 1;
		tint maxC = curr;
		tint minC = curr;

		debug(curr);
		debug(add.size());
		debug(del.size());

		auto a = add.begin();
		auto d = del.begin();
		while(a != add.end() and d != del.end()) {

			if((tint)((*d)^(*a)) == 0) {
					// collapse
					tint countA = 1;
					tint countD = 1;

					auto nextA = a;
					nextA++;
					while(nextA != add.end() and ((*a)^(*nextA)) == 0) {
						countA++;
						a++;
						nextA++;
					}

					auto nextD = d;
					nextD++;
					while(nextD != del.end() and (tint)((*d)^(*nextD)) == 0) {
						countD++;
						d++;
						nextD++;
					}

					debug(countA);
					debug(countD);

					maxC = max(maxC, curr + countA);
					minC = min(minC, curr - countD);
					curr = curr + countA - countD;
					a++;
					d++;
			} else if((tint)((*d)^(*a)) > 0) {
				curr++;
				maxC = max(maxC, curr);
				a++;
			} else {
				curr--;
				minC = min(minC, curr);
				d++;
			}
		}

		curr += distance(a, add.end());
		maxC = max(maxC, curr);

		curr -= distance(d, del.end());
		minC = min(minC, curr);

		debug(upper);
		debug(lower);
		debug(minC);
		debug(maxC);

		cout << minC << " " << maxC << endl;
	}
  return 0;
}
