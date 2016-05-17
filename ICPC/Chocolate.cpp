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
  
  int n,curr,j;
  
  long long int cnt=1;
  
  cin>>n;
  
  int h=1;
  
  cin>>curr;
  
  while (curr!=1){
    //cin>>curr;
    if (h>=n) {cout<<"0"<<endl; return 0;}
    scanf("%i", &curr);
    
    h++;
  }
  
  j=1;
  
  
  
  while (h<n){
    //cin>>curr;
    scanf("%i", &curr);
    h++;
    if (curr==0) {j++;}
    else { cnt=cnt*j; j=1;}
    
  }
  
  cout<<cnt<<endl;
  
  
  return 0;
  
}