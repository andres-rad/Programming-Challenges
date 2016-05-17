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


struct point {
  int cnt;
  vector<int> rel;
  int longt;
};

//pair <int,int> seg[400005];

//point po[100005];
//int n,m;


/*int times (int a, int b){
  int t=0;
  forn (i,b){
    if (seg[i].first==a){
      t++;
    }
  }
  
  return t;
};
*/

int longtail (int a, point *po){
  int t=0;
  forn (i, po[a].cnt){
    int h=po[a].rel[i];
    if (h<a){
      t=max(t,1+po[h].longt);
    }
  }
  return t;
};

int main (){
  
  int n,m;
  
  cin>>n>>m;
  
  point po[100005];
  
 /* forn (i,m){
    
    int s,t;
    cin>>s>>t;
    seg[2*i].first=s;
    seg[2*i].second=t;
    seg[2*i+1].first=t;
    seg[2*i+1].second=s;
  }*/
  
  forn (i,n){
    po[i].cnt=0;
    po[i].longt=0;
  }
  
  forn (i,m){
    
    int s,t;
    cin>>s>>t;
    //po[s].rel[po[s].cnt]=t;
    po[s].rel.push_back (t);
    po[s].cnt++;
    //po[t].rel[po[t].cnt]=s
    po[t].rel.push_back (s);
    po[t].cnt++;
  }
  
  //sort (seg,seg+2m+1);
  int ma=0;
  /*forn (i,n){
    ma=max(ma,po[i].cnt*)
    
  }*/
  
  forn (i,n+1){
    po[i].longt=longtail(i,po);
    ma=max(ma, po[i].cnt*(po[i].longt+1));
    //cout <<ma<<"  "<<i<<endl;
  }
  
  cout<<ma<<endl;
  
  
  
  
  return 0;
  
}