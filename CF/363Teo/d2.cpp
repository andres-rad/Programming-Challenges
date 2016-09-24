#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back

typedef long long int tint;

vector<int> _cl;
int cl(int i) {
  return (_cl[i] == -1 ? i : _cl[i] = cl(_cl[i]));
}
void join(int i, int j) {
  if(cl(i)!=cl(j)) _cl[cl(i)] = cl(j);
}
void ini(int n) {
   _cl.clear(); _cl.insert(_cl.begin(), n, -1);
}



int main () {

  int n;
  cin>>n;


  vector<int> seq;
  ini(n);

  int primeraraiz=-1;


  forn (i,n){
    int t;
    cin>>t;
    if (primeraraiz==-1 && i==t-1){
      primeraraiz=i;
    }
    join(t-1,i);

    seq.pb(t);
  }



  set<int> vistas;
  int ans=0;

  if (primeraraiz==-1){
    primeraraiz=cl(0);
    vistas.insert(primeraraiz);
    seq[primeraraiz]=primeraraiz+1;
    ans++;
  }


  forn (i,n){
    if (vistas.find(cl(i))==vistas.end() && cl(i)!=cl(primeraraiz)){
      seq[cl(i)]=primeraraiz+1;
      ans++;
      vistas.insert(cl(i));
    }
  }

  cout<<ans<<endl;

  forn (i,n-1){
    cout<<seq[i]<<' ';
  }
  cout<<seq[n-1]<<endl;




  return 0;
}
