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

int n,secs;
int load[100005];
int main (){
  cin>>n;
  secs=0;
  forn (i,n) cin>>load[i];

  int sum=0, rest=0;

  forn (i,n) {
    rest+=load[i]%n;
    sum+=load[i]/n;
  }
  sum+=rest/n;


  sort (load,load+n);

  int p=0, q=0;

  while (load[n-1]-load[0]>1){
  while (load[n-1-p]-load[0+q]>1){
    secs++;
    load[n-1-p]--;
    load[0+q]++;
    //if ((load[n-1]-sum<=1)||(sum-load[0]<=0)) sort (load,load+n);
    if (load[n-1-p]-sum<=1) p++;
    if (sum-load[0+q]<=0) q++;
  }
  sort (load,load+n);
  p=0;
  q=0;
}
  //sort (load,load+n);
  /*int sum=0, rest=0;

  forn (i,n) {
    rest+=load[i]%n;
    sum+=load[i]/n;
  }
  sum+=rest/n;

  forn (i,n){
    while (load[i]>sum){
      load[i]--;
      secs++;
    }
  }*/

  /*
  while (load[n-1]-load[0]>1) {

    secs+=(load[n-1]-load[0])/2;
    if (((load[n-1]-load[0])/2)%2==1) secs--;
    load[0]+=(load[n-1]-load[0])/2;
    load[n-1]-=(load[n-1]-load[0])/2;
    sort (load,load+n);

  }*/

  cout<<secs<<endl;

  return 0;
}
