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
#define debug(a) cerr<< #a <<": "<<a<<endl;
typedef long long ll;
typedef pair<int,int> ii;
typedef double tipo;
/////

vector<string> pos(9);

string trans (const string & b){
  string res=b;
  forn (i, b.length()){
    res[res.length()-i-1]=(b[i] == 'L' ? 'R' : 'L');
  }

  return res;
}

bool isin ( int n,  string a){
  int end = 1;
  if (n>8){
    int resto = n-8;
    n = 8;
    end = 0;
    a =  trans(a);
    //return isin(1-end, n-1, trans(a));
  }//else
  {
    if (end){
      forr (i, 0, a.length()){
        if (pos[n][pos[n].length()-i] != a[a.length()-i]) return false;
      }
      return true;
    }else{
      forr (i, 0, a.length()){
        if (pos[n][i] != a[i]) return false;
      }
      return true;
    }
  }
}

bool intersects(int n, const string & a){
  if (n<=8){
    if (pos[n].length()>=a.length()){
      forn (i, pos[n].length()-a.length()){
        if (a==pos[n].substr(i, a.length())) return true;
      }
    }
    return false;
  }
  forn (i, a.length()){
    if (a[i] == 'L'){
      //debug(a.substr(a.length(),string::npos));
      //debug(a);
      //debug(trans(a));
      //debug(a.substr(0,i));
      //debug(a.substr(i+1, string::npos));
      if ((i==0 || isin(n-1, (a.substr(0,i)))) &&
          (i>=a.length()-1 || isin(n-1, trans(a.substr(i+1, string::npos))))){
        return true;
      }
    }
  }
  return false;
}

int main() {
  pos[0]="L";
  forr (i, 1, 9){
    pos[i]=pos[i-1] + "L" + trans(pos[i-1]);
  }

  int t;
  cin>>t;
  int curr=0;
  while(t>curr){
    curr++;
    int n;
    string s;
    cin>>n>>s;
    n--;

    bool res=intersects(n,s);

    while (not res && n>=7){
      n--;
      res=intersects(n, s) || intersects(n, trans(s));
    }

    cout<<"Case "<<curr<<": "<< (res?"Yes":"No")<<endl;
  }
  return 0;
}
