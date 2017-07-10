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
#define debug(v) //cerr<< #v << ": " << (v) <<endl;
#define INF 1e9
typedef long long ll;
typedef pair<int,int> ii;
typedef double tipo;
/////

int main() {
  int p, k;
  cin>>p>>k;

  int res=0;
  forn(ii, p){
    int n;
    cin>>n;

    vector<int> v(n);
    forn(i,n){
      cin>>v[i];
    }

    vector<int> ganadora(n, 0);
    forn(i,n){
      set<int> s;
      forn(j, min(i, k) + 1){
        int temp = (i - j - v[i - j]) ;
        if (temp == -1) {
          s.insert(0);
        }else if (temp>=0){
          s.insert(ganadora[temp]);
        }
         ganadora[i]=0;
        while (s.find(ganadora[i]) != s.end()) ganadora[i]++;

      }
      debug(i);
      debug(ganadora[i]);

    }

    res = res ^ ( ganadora[n-1]);

  }

  cout<<(res ? "Alice can win." : "Bob will win.")<<endl;

  return 0;
}
