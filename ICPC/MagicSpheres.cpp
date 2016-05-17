#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)



int main () {

  int a,b,c,x,y,z,suma,sumx;

  cin>>a>>b>>c;
  cin>>x>>y>>z;
  suma=0;
  sumx=0;

  if (a<=x) sumx+=x-a;
  else suma+=a-x;

  if (b<=y) sumx+=y-b;
  else suma+=b-y;

  if (c<=z) sumx+=z-c;
  else suma+=c-z;


  while (a-x>=2) {
    a-=2;
    sumx-=1;
  }
  while (b-y>=2) {
    b-=2;
    sumx-=1;
  }
  while (c-z>=2) {
    c-=2;
    sumx-=1;
  }

  if (sumx>0) cout<< "No"<<endl;
  else cout<<"Yes"<<endl;

  return 0;
}
