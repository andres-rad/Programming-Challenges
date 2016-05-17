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
  int x=0,j=5, cnt=0;
  
  cin>>x;
  
  while (j>0){
    while(j<=x){
      x-=j;
      cnt++;
    }
    j--;
  }

  cout<<cnt<<endl;


  return 0;
}