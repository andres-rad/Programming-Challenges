#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define sq(x) ((x) * (x))
#define all(v) ((v).begin, (v).end)
#define x real()
#define y imag()
#define pb push_back
#define f first
#define s second
#define mp make_pair

using namespace std;
typedef pair<int,int> par;

vector<par> a;
vector<par> impares;

int main()
{
	int n; int m;
	cin >> n;
	forn(i,n)
	{
		cin >> m;
		int cant = 1;
		int aux = m / 2;
		while(aux & 1)
		{
			cant++;
			aux /= 2;
		}
		par p;
		p.f = cant;
		p.s = aux;
		if(m & 1)
			impares.pb(p);
		else
			a.pb(p);
	}
	sort(impares.begin(), impares.end());

	int lo = 0; int hi = 32*n;

	int ODD = (int)impares.size();

	if(ODD == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	// con hi se puede, con lo no

	while(hi - lo > 1)
	{
		int m = (hi + lo) / 2;
		bool can = false;

		priority_queue< par, vector< par >, greater< par > > pq(a.begin(),a.end());

		int d = ODD - m;
		int curodd = ODD;
		int curop = 0;
		int ind = 0;

		if(d > 0)
		{
			ind = d;
			forn(i, d)
			{
				curop += impares[i].f;
				curodd -= impares[i].f;
				curodd--;
				curodd = max(curodd, 0);
				int b = impares[i].s / 2;
				int c = 1;
				while(b & 1)
				{
					c++;
					b /= 2;
				}
				pq.push(mp(c,b));
			}
		}

		while(curop <= m)
		{
			if(curodd == 0)
			{
				can = true;
				break;
			}

			par m1 = pq.empty() ? mp(50*n,1) : pq.top();
			par imp = ind < ODD ? impares[ind] : mp(50*n,1);

			if(m1.f != (imp.f - 1))
			{
				if(m1.f < (imp.f - 1))
				{
					pq.pop();
					curop += m1.f;
					curodd -= m1.f;
					curodd = max(curodd,0);
					int b = m1.s / 2;
					int c = 1;

					while(b & 1)
					{
						c++;
						b /= 2;
					}
					pq.push(mp(c,b));
				}
				else
				{
					curop += imp.f;
					curodd -= (imp.f + 1);
					curodd = max(curodd,0);
					int b = imp.s / 2;
					int c = 1;

					while(b & 1)
					{
						c++;
						b /= 2;
					}
					pq.push(mp(c,b));
					ind++;
				}
			}
			else
			{
				int res = m - curop;
				if(res < imp.f)
				{
					pq.pop();
					curop += m1.f;
					curodd -= m1.f;
					curodd = max(curodd,0);
					int b = m1.s / 2;
					int c = 1;

					while(b & 1)
					{
						c++;
						b /= 2;
					}
					pq.push(mp(c,b));
				}
				else
				{
					int b1 = m1.s / 2;
					int c1 = 1;

					while(b1 & 1)
					{
						c1++;
						b1 /= 2;
					}

					int b2 = imp.s / 2;
					int c2 = 1;

					while(b2 & 1)
					{
						c2++;
						b2 /= 2;
					}

					if(c1 < c2)
					{
						pq.pop();
						curop += m1.f;
						curodd -= m1.f;
						curodd = max(curodd,0);
						pq.push(mp(c1,b1));
					}
					else
					{
						curop += imp.f;
						curodd -= (imp.f + 1);
						curodd = max(curodd,0);
						pq.push(mp(c2,b2));
						ind++;
					}
				}
			}
		}

		if(can) hi = m;
		else lo = m;
	}

	cout << hi << endl;

	return 0;
}