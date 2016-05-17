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

int dist (pair <int,int> a, pair <int,int> b){
  int d = (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
  return d;
}


int main (){

  int t,n;
  pair <int,int> st[2005];

  int dis[2005];

  cin>>t;

  forn (h,t){
    int cnt=0;

    cin>>n;

    forn (j ,n){
      cin>>st[j].first>>st[j].second;
    }


    forn (i,n){

      for (int j=i+1,j<n,j++;){

        dis[j-i-1]=dist(st[i],st[j]);


      }

      sort (dis,dis+n-i-1);
      

    }


  }






  return 0;

}
