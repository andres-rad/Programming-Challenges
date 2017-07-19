#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forsn(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
#define INF 1e9
#define MAX_V  220
#define debug(a) cerr<< #a << ": " << a <<endl;
#define add(a, b, w) G[a].pb(make_pair(w, b))
#define sq(x) (x)*(x)
#define mp make_pair
typedef long long ll;
typedef pair<int,int> ii;
typedef double tipo;

map<string, vector< pair<string,string> > > regla;
map<string, vector< vector<double> > > dp;

double calc(string c, int i, int j)
{
	if(i > j) return (0.0);
	
	if(dp[c][i][j] != -1.0) return dp[c][i][j];
	
	dp[c][i][j] = 0.0;
	
	if(regla.find(c) == regla.end()) return (0.0);
	
	for(auto it:regla[c])
	{			
		string r1 = it.fst;
		string r2 = it.snd;
		forsn(k,i,j)
		{
			//debug(i);debug(j);debug(k);
			dp[c][i][j] += calc(r1,i,k) * calc(r2,k+1,j);
			dp[c][i][j] += calc(r2,i,k) * calc(r1,k+1,j);
		}
	}
		
	

	return (dp[c][i][j]);
}


int main()
{
	int r,t,n;
	string s1,s2,s3;
	cin >> r;
	set<string> cls;
	forn(i,r)
	{
		cin >> s1 >> s2 >> s3;
		cls.insert(s1); cls.insert(s2); cls.insert(s3);
		regla[s3].pb( mp( min(s1,s2), max(s1,s2) ) );
	}

	cin >> t;

	forn(caso,t)
	{
		for(auto it:cls)
		{
			dp[it] = vector< vector<double> >(510, vector<double>(510,-1.0));
		}
		cin >> n;
		string col; double prob;
		forn(i,n)
		{
			while(cin >> col and col != "END")
			{
				cin >> prob;
				dp[col][i][i] = prob;
				//debug(col); debug(prob); debug(dp[col][i][i]);
			}
		}
		double best = 0.0;
		string ans = "GAMEOVER";

		for(auto it:regla)
		{	
			//debug(it.fst);
			string c = it.fst;
			double cnd = calc(c,0,n-1);
			//debug(cnd);
			if(cnd > best)
			{
				best = cnd;
				ans = c;
			}
		}

		cout << ans << endl;
	}

	return 0;
}