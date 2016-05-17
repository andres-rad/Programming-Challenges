#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back


int main (){

  int t,n;
  pair <int,int> st[2005];



  cin>>t;

  forn (h,t){
    int cnt=0;

    cin>>n;

    forn (j ,n){
      cin>>st[j].first>>st[j].second;
    }

    //sort (st,st+n);

    forn (i,n){
      forn (j,n){
        if (j==i) continue;

        forn (p,n) {
          if (p==j||p==i) continue;

          int d1=(st[i].first-st[j].first)*(st[i].first-st[j].first)+(st[i].second-st[j].second)*(st[i].second-st[j].second);
          int d2=(st[i].first-st[p].first)*(st[i].first-st[p].first)+(st[i].second-st[p].second)*(st[i].second-st[p].second);

          //cout<<i<<" "<<j<<" "<<p<<" "<<d1<<" "<<d2<<endl;

          if (d1==d2) cnt++;

        }
      }
    }

    cout<<"Case #"<<h+1<<": "<<cnt/2<<endl;


  }


  return 0;
}
