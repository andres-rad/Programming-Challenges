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

typedef long long int tint;
typedef pair<int,int> par;

int t[100100];
int n,q;

tint mcd(tint a, tint b)
{
	if(b == 0) return a;
	return mcd(b, a % b);
}

string solve(int s, int d, int m)
{
	if(n == 1)
	{
		if( (2 * t[0] - s) == d ) return "Y";
		else return "N";
	}
	if(n == 2)
	{
		if( (d - s) % (2 * (t[0] - t[1])) == 0 ) return "Y";
		if( (d + s - 2 * t[1]) % (2 * (t[0] - t[1]) ) == 0 ) return "Y";
		return "N";
	}

	if( ( (d - s) % (2 * m) ) == 0) return "Y";
	if( ( (d + s - 2 * t[n-1] ) % (2 * m) ) == 0) return "Y";

	return "N";
}

int abs(int b)
{
	if(b < 0) return (-b);
	return (b);
}

int main()
{
	while(cin >> n >> q and n)
	{
		vector<string> ans;
		forn(i,n) cin >> t[i];
		int m;
		if(n > 1)
		{
			m = mcd(abs(t[0] - t[n-1]), abs(t[1] - t[n-1]) );
			forsn(i,2,n-1) m = mcd(m, abs(t[i] - t[n-1]) );
		}
		int s,d;

		forn(i,q)
		{
			cin >> s >> d;
			ans.pb(solve(s,d,m));
		}
		forn(i,q-1) cout << ans[i] << " ";
		cout << ans[q-1] << endl;
	}

	return 0;
}
