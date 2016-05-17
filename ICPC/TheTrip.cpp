//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1078

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)

double round(double d)
{
  return floor(d + 0.5);
}

int main () {
  
  double stu[1005];
  int a;
  double sum,each,t;
  
  cin>>a;
  
  while (a!=0){
    sum=0;
    forn (i, a){
      cin>>stu[i];
      sum+=stu[i]/a;
    }
    each=sum;
    each=each*100;
    t=each-floor(each);
    t=round(t*a);
    t=t/100;
    each= floor(each);
    each=each/100;
    
    sum=0;
    forn (i,a){
      if (stu[i]>each) {
        sum+=stu[i]-each;
        if (t>=0.009){
          sum-=0.01;
          t-=0.01;
        }
      }
    }
    
    cout<<"$"<<fixed<<setprecision(2)<<sum<<endl;
    
    
    cin>>a;
  }
  
  
  return 0;
}