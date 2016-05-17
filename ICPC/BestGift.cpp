#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back

int n,m,temp,resp;
int gen[12];

int sum (int k,int h){
  int ans=0;
  forn (i,h-k){
    ans+=gen[i+k];
   // cout<<"a";
  }
  return ans;
}
int main (){
  resp=0;
  cin>>n>>m;
  forn (i,n){
    cin>>temp;
    gen[temp-1]++;
  }
  
  forn (j,m){
    while (gen[j]>0){
      if (j+1<m) resp+=sum(j+1,m);
      gen[j]--;
      
    }
  }

    cout<<resp<<endl;
  return 0;
}