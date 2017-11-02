#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <stack>
#include <set>
#include <map>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define EPS 1e-9

using namespace std;

typedef signed long long int tint;
typedef pair<tint,tint> par;

tint signed_area(par a, par b, par c)
{
	tint res = a.x * b.y - a.y * b.x + a.y * c.x - a.x * c.y + b.x * c.y - c.x * b.y;

	return (res);
}

tint mcd(tint a, tint b)
{
	return (a == 0)? b : mcd(b % a, a);
}

par rac(tint a, tint b)
{
	tint sg;
	if(a > 0) sg = (b >= 0) ? 1 : -1;
	else sg = (b >= 0) ? -1 : 1;
	tint d = mcd(abs(a),abs(b));
	tint aa = abs(a) / d; tint bb = abs(b) / d;
	return mp(sg * aa, bb);
}

pair<par,par> centro(par a, par b, par c)
{
	//par m1 = (a.x == b.x) ? mp(0,1) : rac(mp(b.y - a.y,b.x - a.x));
	//par m2 = (b.x == c.x) ? mp(0,1) : rac(mp(c.y - b.y, c.x - b.x));
	par x,y;

	tint u1 = b.y - a.y; tint v1 = b.x - a.x;
	tint u2 = c.y - b.y; tint v2 = c.x - b.x;

	if(a.x == b.x)
	{
		//m1 = oo
		x = rac( v2 * (b.x + c.x) + u2 * (a.y - c.y), 2 * v2);
		y = rac(a.y + b.y, 2);

		return mp(x,y);
	}
	if(b.x == c.x)
	{
		//m2 = oo
		x = rac( u1 * (a.y - c.y) + v1 * (a.x + b.x), 2 * v1);
		y = rac(b.y + c.y, 2);

		return mp(x,y);
	}

	/*cout << a.x << " " << a.y << endl;
	cout << b.x << " " << b.y << endl;
	cout << c.x << " " << c.y << endl;
	cout << u1 << " " << v1 << endl;
	cout << u2 << " " << v2 << endl;*/
	x = rac(u1 * u2 * (a.y - c.y) + u2 * v1 * (a.x + b.x) - u1 * v2 * (b.x + c.x), 2 * (u2 * v1 - v2 * u1));
	y = rac(v1 * v2 * (c.x - a.x) + v1 * u2 * (b.y + c.y) - v2 * u1 * (a.y + b.y), 2 * (u2 * v1 - u1 * v2));

	return (mp(x,y));
}

double sqr(double x)
{
	return ((x)*(x));
}

double sqrdis(pair<par,par> a, par b)
{
	double aax = a.x.x / (a.x.y + .0);
	double aay = a.y.x / (a.y.y + .0);
	return ( sqr(aax - b.x) + sqr(aay - b.y) );
}

int main()
{
	//freopen("test.txt", "r", stdin);
	int n;
	par punto[110];

	while(scanf("%d",&n))
	{
		if(n == 0) break;
		//vector<pair<par,par> > ce;
		forn(i,n) scanf("%lld %lld", &punto[i].x , &punto[i].y);
		int best = 1;

		forn(i,n)
		{
			forsn(j,i+1,n)
			{
				//cout << i << "; " << j << " : " << endl;
				map<pair<par,par>,int> cent;
				forn(k,n)
				{
					if(signed_area(punto[i], punto[j], punto[k]) != 0)
					{
						pair<par, par> c = centro(punto[i], punto[j], punto[k]);
						//cout << c.x.x << " " << c.x.y << " " << c.y.x << " " << c.y.y << " " << k << endl;
						cent[c]++;
						//cout << k << " " << cent[c] << endl;
						best = max(best, 2 + cent[c]);
					}
				}
				/*
				sort(ce.begin(), ce.end());
				int sz = ce.size();
				//forn(k,sz) cout << "( " << ce[k].x.x << " " << ce[k].x.y << " , " << ce[k].y.x << " " << ce[k].y.y << " ) "; cout << endl;

				for(int lo = 0; lo < ce.size(); )
				{
					int hi = sz - 1;
					if(ce[lo] == ce[hi])
					{
						best = max(best, hi - lo + 3);
						lo = hi + 1;
					}
					else
					{
						int l = lo;
						// ce[lo] < ce[hi]
						while(hi - l > 1)
						{
							int med = (hi + l) / 2;
							if(ce[med] > ce[l]) hi = med;
							else l = med;
						}
						best = max(best, l - lo + 3);
						lo = hi;
					}
				}
				ce.clear();*/
			}
		}
		
		if(n >= 2) best = max(2, best);
		cout << best << endl;
	}

	return 0;
}