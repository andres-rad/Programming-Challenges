#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back



int main () {

  string at,bt;
  cin>>at;
  cin>>bt;
  bool a[200005];
  bool b[200005];
    int sum=0;

  forn (i, at.size()){
    if (at[i]=='1') a[i]=true;
    else a[i]=0;
  }

  forn (i, bt.size()){
    if (bt[i]=='1') b[i]=true;
    else b[i]=0;
  }

  forn (i,bt.size()-at.size()+1){


    forn (j,at.size()){
      if (a[j]!=b[j+i]) sum++;
      //sum+=abs(a[j]-b[j+i]);
    }
  }

  //cout<<a<<endl<<b<<endl;
/*
  int sum=0;
  int last, first;
  first=b[0];

  forn (i,b.size()-a.size()+1){
    last = b[i+a.size()-1];

    forn (j,a.size()){

      sum+=abs(a[j]-b[j+i]);
    }
    first = b[i];
  }


  */
  cout << sum<<endl;

  return 0;
}
