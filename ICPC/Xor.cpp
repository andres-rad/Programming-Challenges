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
  
  const int N=100005;
  
  
  int n,m,k;
  
  int a[100005]={0};
  
  cin>>n>>m>>k;
  
  forn (i,n){
    int b;
    scanf("%i",&b);
    a[i+1]=a[i]^b;
  }
  
  
  forn (h,m){
    int cnt=0;
    
    int l,r;
    scanf ("%i %i",&l,&r);
    
    for (int i=l;i<=r;i++){
      for (int j=i;j<=r;j++){
        
        int p=a[j]^a[i-1];
        if (p==k) {cnt++; 
                             //cout<<i<<"  "<<j<<"  "<<p<<endl;
                            }
      }
    }
    
    cout<<cnt<<endl;
  }
  
  
  
  return 0;
}