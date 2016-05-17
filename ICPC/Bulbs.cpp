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
  
  int n,m;
  
  cin>>n>>m;
  
  int bulbs[105]={0};
  
  forn (i,n){
    int p;
    cin>>p;
    forn (j,p){
      int t;
      cin>>t;
      bulbs[t-1]=1;
    }
  }
  
  forn (i,m){
    if (bulbs[i]==0) {
      cout<<"NO"<<endl;
      return 0;
    }
  }
  
  cout<<"YES"<<endl;
  
  return 0;
}

