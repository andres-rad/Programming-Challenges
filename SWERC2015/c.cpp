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
typedef double tipo;
/////

ll dfs(ll* canvas, int i, int j){
  if (i + 1 >= j) return 0;
  ll total= (canvas[j-1] + canvas[i] + 1)/2;
   //total /=2;
   //total += canvas[i];
  int lo, hi;
  lo = i;
  hi =j;
  while(lo<hi-1){
    int m = (lo+hi)/2;
    if (canvas[m]<=total){
      lo = m;
    }else{
      hi = m;
    }
  }

  if (hi==j) hi--;
  int mini = abs((canvas[j-1] - canvas[hi-1]) - (canvas[hi-1] - canvas[i-1]));

  int temphi = hi+1;
  if (temphi<j && mini > abs((canvas[j-1] - canvas[temphi-1]) - (canvas[temphi-1] - canvas[i-1]))){
    hi = temphi;
    mini =  abs((canvas[j-1] - canvas[temphi-1]) - (canvas[temphi-1] - canvas[i-1]));
  }

  temphi = temphi-2;
  if (temphi>i && mini > abs((canvas[j-1] - canvas[temphi-1]) - (canvas[temphi-1] - canvas[i-1]))){
    hi = temphi;
    mini =  abs((canvas[j-1] - canvas[temphi-1]) - (canvas[temphi-1] - canvas[i-1]));
  }


  ll res= canvas[j-1] - canvas[i-1] + dfs(canvas, i, hi) + dfs(canvas, hi, j);
  //debug (i); debug(j); debug(res); cerr<<endl;
  return res;

}


int main() {
  int t;
  cin>>t;
  ll canvas [100100];

  while(t > 0){
    t--;
    int n;
    cin>>n;
    //memset(canvas, 0, n+10);
    canvas[0]=0;
    forn(i, n){
      cin>>canvas[i+1];
      canvas[i+1]+=canvas[i];
    }

    ll res = 0;

    res = dfs(canvas, 1, n+1);

    cout<<res<<endl;

  }
  return 0;
}
