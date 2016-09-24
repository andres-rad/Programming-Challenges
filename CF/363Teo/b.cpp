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

  int n,m;
  cin>>n>>m;

  vector<vector<int> > mat (n, vector<int> (m));

  vector<int> sumay (n,0), sumax(m,0);
  int total=0;
  forn (i,n){
    forn (j,m){
      char temp;
      cin>>temp;
      total+=(temp=='*'?1:0);
      mat[i][j]=(temp=='*'?1:0);
      sumay[i]+=(temp=='*'?1:0);
      sumax[j]+=(temp=='*'?1:0);
    }
  }

  forn (i,n){
    forn (j,m){
      //cout<<i<<' '<<j<<' '<<sumay[i]<<' '<<sumax[j]<<' '<<total<<endl;
      if (sumay[i]+sumax[j]-mat[i][j]==total){
        cout<<"YES"<<endl<<i+1<<' '<<j+1<<endl;
        return 0;
      }
    }
  }

  cout<<"NO"<<endl;
/*
  int maxx=0,maxy=0, cantx=0, canty=0, posx=0, posy=0;

  int masx=0, masy=0;

  forn(i,n){
    posy=(sumay[i]>maxy?i:posy);
    maxy=max(maxy, sumay[i]);
    canty+=(sumay[i]>0?1:0);
    masy+=(sumay[i]>1?1:0);

  }
  forn(i,m){
    posx=(sumax[i]>maxx?i:posx);
    maxx=max(maxx, sumax[i]);
    cantx+=(sumax[i]>0?1:0);
    masx+=(sumax[i]>1?1:0);
  }

  cout<<"maxy "<<maxy<<" maxx "<<maxx<<endl;
  cout<<"canty "<<canty<<" cantx "<<cantx<<endl;
  if (masy<2 && masx<2 && cantx==maxy && canty==maxx){
    cout<<"YES"<<endl<<posy+1<<' '<<posx+1<<endl;
  }else{
    cout<<"NO"<<endl;
  }

*/



  return 0;
}
