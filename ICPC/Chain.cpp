#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back


int main () {
  
  int cnt[1000005];
  int n;
  int nums [100005];
  
  pair <int,int> bea [100005];
  
  cin >>n;
  
  forn (i,n) cin>>bea[i].first>>bea[i].second;
  sort (bea,bea+n);
  
  int pre=0;
  cnt[0]=0;
  
  forn (i,1000003) {
    if (bea[pre].first==i) {
      pre++;
      //cout<<pre<<" "<<i<<endl;
    }
    cnt [i+1]=pre;
    
  }
  
  int mi =2000000;
  int t=0;
  
  forn (i,n){
    t=cnt[bea[i].first]-cnt[max(0,bea[i].first-bea[i].second)];
    t+=nums[max(0,i-t-1)];
    nums[i]=t;
    //cout<<bea[i].first-bea[i].second<<endl;
    t+=n-i-1;
    mi =min(mi,t);
    
  }
  
  cout<<mi<<endl;
  return 0;
}