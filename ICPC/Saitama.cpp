#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back

pair <int,int> p [105];
int n,s,tim,pre,flo;

int main () {
  cin>>n>>s;
  forn (i,n) cin>>p[i].first>>p[i].second;

  tim =0;
  flo=s;


  sort (p,p+n);

  forn (i,n) {
    if (p[n-1-i].first!=flo){
      tim+=flo-p[n-1-i].first;
      flo=p[n-1-i].first;
    }

    while (p[n-1-i].second>tim) {
      tim++;
      //cout<<i<<endl;
      pre=p[n-1-i].first;
    }

  }

  tim+=flo;

  cout <<tim<<endl;


  return 0;
}
