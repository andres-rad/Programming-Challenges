#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define sq(x) ((x) * (x))
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define f first
#define s second
#define mp make_pair

using namespace std;
typedef pair<int,int> par;

int g[1100];
int v[1100];
int mini[1100];
int fin[1100];

int mcd(int a, int b)
{
	if(b == 0) return (a);

	return mcd(b, a % b);
}

int main()
{
	int n,k;
	cin >> n >> k;

	forn(i,n)
	{
		cin >> g[i];
	}

	int d = mcd(n,k);
	int q = n / d;
	int kk = k / d;

	bool ok = true;

	forn(x,d)
	{
		int c = 0;
		forn(j,q)
		{
			int a = (g[ (j * k + k - 1 + x + 1) % n] - g[ (j * k + k - 1 + x) % n]);
			c += a;
			//cout << a << " " << c << endl;
			mini[x] = min(mini[x],c);
			v[((j+1)*k + x) % n] = c;
		}
		//cout << c << " " << x << " " << mini[x] << endl;
		if(c)
		{
			ok = false;
			break;
		}
	}
	/*
	forn(i,n) cout << v[i] << " ";
	cout << endl;
	*/
	int share = 0;
	forn(ind,k)
	{
		share += v[ind % n];
	}
	share = g[k-1] - share;

	//cout << share << endl;

	forn(eq,n)
	{
		int s = 0;
		forn(ind,k)
		{
			s += v[(ind + eq) % n];
		}
		s = g[(eq + k - 1) % n] - s;
		//cout << (eq + k - 1) % n << " " << g[(eq + k - 1) % n] << " " << s << endl;
		if(s != share)
		{
			ok = false;
			break;
		}
		if(s % kk)
		{
			ok = false;
			break;
		}
	}
	int t = 0;
	forn(x,d)
	{
		fin[x] = max(0, -mini[x]);
		t += fin[x];
		forsn(j,1,q) fin[(j * k + x) % n] = v[(j * k + x) % n] + fin[x];
	}
	if(t * kk > share) ok = false;
	/*
	forn(i,n) cout << fin[i] << " ";
	cout << endl;
	
	forn(eq,n)
	{
		int cnd = 0;
		forn(j,k) cnd += fin[(j + eq) % n];
		
		//cout << cnd << endl;
		if(cnd != g[(eq + k - 1) % n])
		{
			ok = false;
			break;
		}
	}
	*/
	if(ok) cout << "S" << endl;
	else cout << "N" << endl;

	return 0;
}