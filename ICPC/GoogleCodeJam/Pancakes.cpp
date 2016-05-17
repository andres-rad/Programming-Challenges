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


int main () {
  
  string panc;
  int n=0,t;
  char curr='a';
  
  cin>>t;
  
  forn (j,t){
    n=0;
    curr='a';
    
    cin>>panc;

    forn (i,panc.size()){
      if (panc[i]!=curr){
        n++;
        curr=panc[i];
      }
    }

    if (panc[panc.size()-1]=='+') n--;
    
    cout<<"Case #"<<j+1<<": "<<n<<endl;

  }
  return 0;
}