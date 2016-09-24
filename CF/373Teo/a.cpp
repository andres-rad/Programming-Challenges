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
  
  int n;
  cin>>n;

  int ant, cur;
  cur=-1;

  forn(i,n){
    ant=cur;
    cin>>cur;


  }

  if (n==1 && (cur!=0 && cur!=15)){
    cout<<-1<<endl;
  }else if (cur==0 || (ant<cur && cur!=15)){
    cout<<"UP"<<endl;
  }else {
    cout<<"DOWN"<<endl;
  }
  
  return 0;
}