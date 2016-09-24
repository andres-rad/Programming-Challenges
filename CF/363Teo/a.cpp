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

typedef long long int tint;


int main () {

  int n;
  cin>>n;

  tint ans=10000000000;

  int lastr=-1;
  int last=0;

  vector<int> dir, pos;

  forn (i,n){
    char temp;
    cin>>temp;
    dir.pb(((temp=='R')?1:0));
  }
  forn (i,n){
    int temp;
    cin>>temp;
    pos.pb(temp);
  }

  forn (i,n){
    if (dir[i]==1){
      last=1;
      lastr=pos[i];
      //cout<<dir[i]<<endl;
    }else{
      if (last){
        //cout<<dir[i]<<endl;
        ans=min(ans, (tint)(pos[i]-lastr)/2);
        last=0;
      }
    }

  }

  cout<<(ans==10000000000?-1:ans)<<endl;


  return 0;
}
