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

long long int sum[100005]={0};

int bse (long long int a, int up){
  int down=0;
  int temp;

  if (sum[up]<=a) return (up);

  while (up-down>1){
    temp=(up+down)/2;
    if (sum[temp]<=a) down =temp;
    else up =temp;
  }
  return down;
}

int main (){

  int t,n;

  long long int p,tp;
  //long long int sum[100005]={0};

  cin>>t;

  forn (h,t){

    cin>>n>>p;

    //cout<<p<<"--";

    forn (i,n) {
      long long int c;
      cin>>c;
      sum[i+1]=c+sum[i];

      //cout<<sum[i+1]<<" ";
    }
    //cout<<endl;

    long long int cnt=0;
    forn (i,n) {
      int f=0;
      f=bse(p+sum[i],n);
      //cout<<"bsea "<<f<<"  "<<i<<endl;
      cnt+=f-i;
    }

    //if (p+sum[n-1]>=sum[n]) cnt++;
    cout<<"Case #"<<h+1<<": "<<cnt<<endl;
  }

  return 0;

}
