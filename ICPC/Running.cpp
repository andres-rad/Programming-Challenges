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
  
  string a,b,c;
  int coatings=0;
  pair <int,int> coats[3010];
  
  //cin>>a>>b;
  
  a="abc";
  b="cbaabc";
  
  c=a;
  reverse(c.begin(),c.end());
  
  forn (i,b.size()){
    cout<<i<<endl;
    int h=0;
    int pos=0;
    int ppos=0;
    int rh=0;
    int rpos=0;
    int rppos=0;
    string temp;
    bool reversed=false;
   
    
   /* while (pos!=-1||h==b.size()){
      
      ppos=pos;
      temp=b.substr(i,h);
      pos =a.find(temp);
      h++;
      
      
      
    }
    
    
    while (rpos!=-1||rh==b.size()){
      
      rppos=rpos;
      temp=b.substr(i,h);
      rpos =c.find(temp);
      rh++;
      
      
      
    }*/
    
    if (rh>h) reversed=true;
    
    if (h==0&&pos==-1) {
      cout<<"-1"<<endl;
      return 0;
    }
    else if (reversed==false) {
      coats[coatings].first=ppos;
      coats[coatings].second=ppos+h-1;
      coatings++;
      i+=h-1;
    }
    else if (reversed==true){
      coats[coatings].first=rppos+rh-1;
      coats[coatings].second=rppos;
      coatings++;
      i+=rh-1;
    }

  }
  
  cout<<coatings<<endl;
  forn(i,coatings){
    cout<<coats[i].first<<" "<<coats[i].second<<endl;
  }
  
  return 0;
  
  
}