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


int main() {
  int n,m;

	cin>>n>>m;
	vector<int> probs (43, 0);

	forn (i,n){
		forn(j,m){
			probs[i+j + 2]++;
		}
	}

	int maxi=-1;
	forn (i, probs.size()){
		maxi = max(maxi, probs[i]);
 	}

	forn(i, probs.size()){
		if (probs[i]==maxi){
			cout<<i<<endl;
		}
	}
  return 0;
}
