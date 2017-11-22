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
typedef pair<double,int> par;

int mcd(int a, int b)
{
	if(b == 0) return a;
	return mcd(b, a%b);
}


int main()
{
	int n;
	string s;

	cin >> s;
	n = s.size();
	vector<int> pegs;
	forn(i,n)
	{
		if(s[i] == 'P') pegs.pb(i);
	}

	int ans = 0;
	vector<int> divs;
	forsn(d,1,n)
	{
		if(n % d == 0)
		{
			divs.pb(d);
		}
	}

	vector<bool> can(n, true);

	forn(i,divs.size())
	{
		vector<bool> in(divs[i],false);
		int seen = 0;
		forn(j,pegs.size())
		{
			int mo = pegs[j] % divs[i];
			if(!in[mo]) seen++;
			in[mo] = true;
		}
		/*cout << divs[i] << endl;
		forn(j,divs[i]) cout << in[j] << " ";
		cout << endl; cout << endl;*/
		if(seen == divs[i]) can[divs[i]] = false;
	}

	forsn(d,1,n)
	{
		int m = mcd(d,n);
		if(m == 1)
		{
			if(pegs.size() == 0) ans++;
		}
		else
		{
			if(can[m]) ans++;
		}
		//cout << d << " " << m << " " << ans << endl;
	}

	cout << ans << endl;

	return 0;
}