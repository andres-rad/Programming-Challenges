#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back

int n,m,counter;
int size[105];


int main () {
  counter=0;
 cin>>n;
  cin>>m;
  forn (i,n){
    cin>>size[i];
  }
  
  sort (size,size+n);
  int j=n-1;
  while (m>0) {
    m-=size[j];
    j--;
    counter++;
    
  }
  cout<<counter<<endl;
  return 0;
}