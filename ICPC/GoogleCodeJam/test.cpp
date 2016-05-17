#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define forn(i,n) for (long long int i=0;i<n;i++)
#define pb push_back

int isPrime (long long int a){
  for (int i=2;i<floor(sqrt(a)+1);i++){
    if (a%i==0) return i;
  }
  return 0;
}

long long int power (int a, int b){
  long long int res=1;
  forn (i,b){
    res=res*a;
  }
  
  return res;
  
}

int main(){
  int t;
  cin>>t;
  
  forn (i,t){
    int k,c,s;
    cin>>k>>c>>s;
    
    
    cout<<"Case #"<<i+1<<":";
    forn (i,s) {
      cout<<" "<<1+(i*(power(k,c-1)));
    }
    cout<<endl;
  }
  
  return 0;
}