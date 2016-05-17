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

bool isPar (int a1,int b1, int a2, int b2) {
  int a3=a1-a2;
  int b3=b1-b2;
  if (a3==0||b3==0) return true;
  else return false;
}

bool isNMidd (int a1,int b1, int a2, int b2, int a3, int b3){
  if (a1<a2&&a2<a3) return false;
  if (b1<b2&&b2<b3) return false;
  
  return true;
}


int main () {
  
  int x1,y1,x2,y2,x3,y3;
  cin>>x1>>y1;
  cin>>x2>>y2;
  cin>>x3>>y3;
  
  if (isPar(x1,y1,x2,y2)&&isPar(x1,y1,x3,y3)&&isPar(x2,y2,x3,y3)){
    cout<<"1"<<endl;
    return 0;
  }
  
  /*else if (isPar(x1,y1,x2,y2)||isPar(x1,y1,x3,y3)||isPar(x2,y2,x3,y3)){
    cout<<"2"<<endl;
    return 0;
  }
  */
  
  if (isPar(x1,y1,x2,y2)&&isNMidd(x1,y1,x3,y3,x2,y2)){
    cout<<"2"<<endl;
    return 0;
  }
  
  if (isPar(x1,y1,x3,y3)&&isNMidd(x1,y1,x2,y2,x3,y3)){
    cout<<"2"<<endl;
    return 0;
  }
 
  if (isPar(x3,y3,x2,y2)&&isNMidd(x3,y3,x1,y1,x2,y2)){
    cout<<"2"<<endl;
    return 0;
  }
  
  cout<<"3"<<endl;
  
  
  
  return 0;
  
}