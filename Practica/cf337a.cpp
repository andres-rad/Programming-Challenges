//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>

using namespace std;

#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)

const int MAXN=100100;
int n;

int main() {
	int n,m;
    while(cin >> n >>m){
    
		vector <int> piezas;
		
		forn (i,m){
			int t;
			cin>>t;
			piezas.pb(t);
		}
		
		sort(piezas.begin(), piezas.end());
		
		int ans=100000;
		
		forn (i,m-n+1){
			ans=min(ans, piezas[i+n-1]-piezas[i]);
		}
		
		cout<<ans<<endl;
		
		
    }
    
    return 0;
}
