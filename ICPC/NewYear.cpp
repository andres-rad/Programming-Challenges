#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back

int main (){

  int n,t;
  int y=366;
  string cas;

  cin>>n>>cas>>cas;

  //cout<<n<<endl<<cas<<endl;

  if (cas=="month"){
      switch (n){
        case 31:
          cout<<"7"<<endl;
          break;
        case 30:
          cout<<"11"<<endl;
          break;
        default:
          cout<<"12"<<endl;
          break;

      }}
    else{
      switch (n){
        case 5:
        case 6:
          cout<<"53"<<endl;
          break;
        default:
          cout<<"52"<<endl;
          break;

      }
  }



  return 0;
}
